//
//  DSHHarness.m
//  DSH
//

#import "DSHHarness.h"
#import "DSHPortAllocator.h"
#import "DSHReadinessProbe.h"
#import "DSHGuestLauncher.h"

NSNotificationName const DSHHarnessStateDidChangeNotification = @"DSHHarnessStateDidChangeNotification";
static NSString *const kExpectedStartupKey = @"DSHExpectedStartupDuration";
static const NSTimeInterval kDefaultExpectedStartup = 25;

NSString *DSHHarnessStateName(DSHHarnessState state) {
    switch (state) {
        case DSHHarnessStateIdle: return @"idle";
        case DSHHarnessStateStarting: return @"starting";
        case DSHHarnessStateReady: return @"ready";
        case DSHHarnessStateRestarting: return @"restarting";
        case DSHHarnessStateFailed: return @"failed";
        case DSHHarnessStateStopped: return @"stopped";
    }
    return @"?";
}

@interface DSHHarness ()
@property (nonatomic) id<DSHGuestProcessLauncher> launcher;
@property (nonatomic, readwrite) DSHHarnessState state;
@property (nonatomic, readwrite) uint16_t port;
@property (nonatomic, readwrite) DSHLogBuffer *log;
@property (nonatomic, readwrite) NSUInteger restartCount;
@property (nonatomic, readwrite, nullable) NSString *lastError;
@property (nonatomic, readwrite) int guestPid;
@property (nonatomic, readwrite) NSTimeInterval lastStartupDuration;
@property (nonatomic) NSUInteger consecutiveCrashes;
@property (nonatomic) NSUInteger launchGeneration;
@property (nonatomic, nullable) DSHReadinessProbe *probe;
@property (nonatomic) BOOL userStopped;
@property (nonatomic) NSDate *lastLaunchAt;
@end

@implementation DSHHarness

+ (instancetype)shared {
    static DSHHarness *shared;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        shared = [[DSHHarness alloc] initWithLauncher:[DSHGuestLauncher new]];
    });
    return shared;
}

- (instancetype)initWithLauncher:(id<DSHGuestProcessLauncher>)launcher {
    if (self = [super init]) {
        _launcher = launcher;
        _log = [[DSHLogBuffer alloc] initWithCapacity:400];
        _serverExecutable = @"/usr/local/bin/dsh-serve";
        _extraEnvironment = @{};
        _preferredPort = 3080;
        _startupTimeout = 240;
        _maxConsecutiveCrashes = 4;
        _state = DSHHarnessStateIdle;
    }
    return self;
}

- (NSTimeInterval)expectedStartupDuration {
    double stored = [NSUserDefaults.standardUserDefaults doubleForKey:kExpectedStartupKey];
    return stored > 1 ? stored : kDefaultExpectedStartup;
}

- (NSDate *)launchStartedAt {
    return self.state == DSHHarnessStateStarting ? self.lastLaunchAt : nil;
}

- (NSURL *)baseURL {
    if (self.port == 0)
        return nil;
    return [NSURL URLWithString:[NSString stringWithFormat:@"http://127.0.0.1:%u/", self.port]];
}

- (void)setState:(DSHHarnessState)state {
    if (_state == state)
        return;
    _state = state;
    [self.log append:[NSString stringWithFormat:@"[dsh-ios] state -> %@", DSHHarnessStateName(state)]];
    [NSNotificationCenter.defaultCenter postNotificationName:DSHHarnessStateDidChangeNotification object:self];
}

#pragma mark - Control

- (void)start {
    NSAssert(NSThread.isMainThread, @"start on main");
    self.userStopped = NO;
    if (self.state == DSHHarnessStateStarting || self.state == DSHHarnessStateReady)
        return;
    self.consecutiveCrashes = 0;
    [self launch];
}

- (void)stop {
    NSAssert(NSThread.isMainThread, @"stop on main");
    self.userStopped = YES;
    self.launchGeneration++;
    [self.probe cancel];
    self.probe = nil;
    if (self.guestPid > 0) {
        [self.launcher killProcess:self.guestPid signal:SIGTERM];
        self.guestPid = 0;
    }
    self.state = DSHHarnessStateStopped;
}

- (void)restart {
    NSAssert(NSThread.isMainThread, @"restart on main");
    [self.log append:@"[dsh-ios] restart requested"];
    [self stop];
    self.userStopped = NO;
    self.consecutiveCrashes = 0;
    self.restartCount++;
    // Give the old process a moment to release the port.
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t) (0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        if (!self.userStopped)
            [self launch];
    });
}

- (void)launch {
    self.launchGeneration++;
    NSUInteger generation = self.launchGeneration;

    // Keep the previous port if it is still free so a restart lands on the
    // same URL; otherwise pick a fresh one.
    uint16_t port = self.port;
    if (port == 0 || ![DSHPortAllocator isLoopbackPortFree:port])
        port = [DSHPortAllocator freeLoopbackPortStartingAt:self.preferredPort span:20];
    if (port == 0) {
        self.lastError = @"No free loopback port between 3080 and 3099.";
        [self.log append:[@"[dsh-ios] " stringByAppendingString:self.lastError]];
        self.state = DSHHarnessStateFailed;
        return;
    }
    self.port = port;
    self.lastError = nil;
    self.lastLaunchAt = NSDate.date;
    self.state = DSHHarnessStateStarting;

    NSMutableDictionary *env = [self.extraEnvironment mutableCopy];
    env[@"DSH_PORT"] = [NSString stringWithFormat:@"%u", port];
    [self.log append:[NSString stringWithFormat:@"[dsh-ios] launching %@ on port %u", self.serverExecutable, port]];

    __weak typeof(self) weakSelf = self;
    int pid = [self.launcher launchExecutable:self.serverExecutable
                                    arguments:@[]
                                  environment:env
                                         line:^(NSString *line, BOOL isStdErr) {
        [weakSelf.log append:line];
    } exit:^(int exitCode) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [weakSelf processExitedWithCode:exitCode generation:generation];
        });
    }];
    if (pid < 0) {
        self.lastError = [NSString stringWithFormat:@"Could not start %@ (error %d).", self.serverExecutable, pid];
        [self.log append:[@"[dsh-ios] " stringByAppendingString:self.lastError]];
        self.guestPid = 0;
        [self scheduleRelaunchAfterFailure];
        return;
    }
    self.guestPid = pid;
    [self.log append:[NSString stringWithFormat:@"[dsh-ios] guest pid %d", pid]];

    self.probe = [[DSHReadinessProbe alloc] initWithURL:self.baseURL interval:0.5 timeout:self.startupTimeout];
    [self.probe startWithHandler:^(BOOL ready, NSTimeInterval elapsed) {
        typeof(self) self = weakSelf;
        if (self == nil || generation != self.launchGeneration)
            return;
        if (ready) {
            self.lastStartupDuration = elapsed;
            // Smooth the estimate for next time (EMA, weight on the new sample).
            double prev = [NSUserDefaults.standardUserDefaults doubleForKey:kExpectedStartupKey];
            double next = prev > 1 ? prev * 0.5 + elapsed * 0.5 : elapsed;
            [NSUserDefaults.standardUserDefaults setDouble:next forKey:kExpectedStartupKey];
            self.consecutiveCrashes = 0;
            [self.log append:[NSString stringWithFormat:@"[dsh-ios] server answered after %.1fs", elapsed]];
            self.state = DSHHarnessStateReady;
        } else if (self.state == DSHHarnessStateStarting) {
            self.lastError = [NSString stringWithFormat:@"The harness did not answer within %.0f seconds.", self.startupTimeout];
            [self.log append:[@"[dsh-ios] " stringByAppendingString:self.lastError]];
            self.launchGeneration++;   // the kill below must not count as a second failure
            if (self.guestPid > 0)
                [self.launcher killProcess:self.guestPid signal:SIGKILL];
            self.guestPid = 0;
            [self scheduleRelaunchAfterFailure];
        }
    }];
}

- (void)processExitedWithCode:(int)exitCode generation:(NSUInteger)generation {
    if (generation != self.launchGeneration)
        return; // an older incarnation; already superseded
    self.guestPid = 0;
    // Retire this launch before cancelling its probe so the probe's handler
    // does not count the same death as a startup timeout too.
    self.launchGeneration++;
    [self.probe cancel];
    self.probe = nil;
    if (self.userStopped) {
        self.state = DSHHarnessStateStopped;
        return;
    }
    self.lastError = [NSString stringWithFormat:@"dsh-serve exited with code %d.", exitCode];
    [self.log append:[@"[dsh-ios] " stringByAppendingString:self.lastError]];
    // A long-lived server that dies is a fresh incident, not a crash loop.
    if (-self.lastLaunchAt.timeIntervalSinceNow > 120)
        self.consecutiveCrashes = 0;
    [self scheduleRelaunchAfterFailure];
}

- (void)scheduleRelaunchAfterFailure {
    self.consecutiveCrashes++;
    if (self.consecutiveCrashes > self.maxConsecutiveCrashes) {
        [self.log append:@"[dsh-ios] giving up after repeated failures"];
        self.state = DSHHarnessStateFailed;
        return;
    }
    NSTimeInterval delay = MIN(pow(2, (double) (self.consecutiveCrashes - 1)), 30);
    [self.log append:[NSString stringWithFormat:@"[dsh-ios] relaunching in %.0fs (attempt %lu/%lu)", delay,
                      (unsigned long) self.consecutiveCrashes, (unsigned long) self.maxConsecutiveCrashes]];
    self.state = DSHHarnessStateRestarting;
    self.restartCount++;
    NSUInteger generation = self.launchGeneration;
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t) (delay * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        if (self.userStopped || generation != self.launchGeneration)
            return;
        [self launch];
    });
}

- (void)verifyAliveWithCompletion:(void (^)(BOOL))completion {
    if (self.state != DSHHarnessStateReady || self.baseURL == nil) {
        if (completion) completion(NO);
        return;
    }
    __weak typeof(self) weakSelf = self;
    [DSHReadinessProbe checkURL:self.baseURL timeout:5 completion:^(BOOL alive) {
        typeof(self) self = weakSelf;
        if (self != nil && !alive && self.state == DSHHarnessStateReady) {
            [self.log append:@"[dsh-ios] health check failed; restarting server"];
            [self restart];
        }
        if (completion) completion(alive);
    }];
}

@end

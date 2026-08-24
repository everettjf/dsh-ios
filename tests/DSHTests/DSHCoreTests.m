//
//  DSHCoreTests.m
//  DSHTests
//
//  Unit tests for the app-side logic that does not need the Linux guest:
//  port allocation, the log ring, the readiness probe and the harness
//  supervisor's state machine (driven through a fake process launcher).
//

#import <XCTest/XCTest.h>
#import "DSHPortAllocator.h"
#import "DSHLogBuffer.h"
#import "DSHReadinessProbe.h"
#import "DSHHarness.h"
#import "DSHBootCoordinator.h"
#import "DSHTestHTTPServer.h"

#pragma mark - Fake launcher

@interface DSHFakeLauncher : NSObject <DSHGuestProcessLauncher>
@property (nonatomic) NSMutableArray<NSDictionary *> *launches;
@property (nonatomic, copy) void (^onLaunch)(NSDictionary *env, void (^line)(NSString *, BOOL), void (^exit)(int));
@property (nonatomic) int nextPid;
@property (nonatomic) NSMutableArray<NSNumber *> *killed;
@property (nonatomic, copy, nullable) void (^lastExit)(int);
@end

@implementation DSHFakeLauncher
- (instancetype)init {
    if (self = [super init]) { _launches = [NSMutableArray array]; _killed = [NSMutableArray array]; _nextPid = 100; }
    return self;
}
- (int)launchExecutable:(NSString *)executable arguments:(NSArray<NSString *> *)arguments environment:(NSDictionary<NSString *,NSString *> *)environment line:(void (^)(NSString *, BOOL))line exit:(void (^)(int))exit {
    [self.launches addObject:@{@"exe": executable, @"env": environment}];
    self.lastExit = exit;
    if (self.onLaunch) self.onLaunch(environment, line, exit);
    return self.nextPid++;
}
- (BOOL)killProcess:(int)pid signal:(int)signal {
    [self.killed addObject:@(pid)];
    return YES;
}
@end

#pragma mark - Tests

@interface DSHCoreTests : XCTestCase
@end

@implementation DSHCoreTests

- (void)testPortAllocatorSkipsBusyPort {
    DSHTestHTTPServer *server = [[DSHTestHTTPServer alloc] initWithPort:0];
    XCTAssertNotNil(server);
    XCTAssertFalse([DSHPortAllocator isLoopbackPortFree:server.port], @"a listening port is not free");
    uint16_t picked = [DSHPortAllocator freeLoopbackPortStartingAt:server.port span:5];
    XCTAssertNotEqual(picked, 0);
    XCTAssertNotEqual(picked, server.port);
    XCTAssertTrue(picked > server.port && picked < server.port + 5);
    [server stop];
}

- (void)testPortAllocatorReturnsZeroWhenSpanExhausted {
    DSHTestHTTPServer *server = [[DSHTestHTTPServer alloc] initWithPort:0];
    XCTAssertEqual([DSHPortAllocator freeLoopbackPortStartingAt:server.port span:1], 0);
    [server stop];
}

- (void)testLogBufferRingAndNoiseFilter {
    DSHLogBuffer *log = [[DSHLogBuffer alloc] initWithCapacity:3];
    [log append:@"one\n"];
    [log append:@"Warning: disabling flag --expose_wasm due to conflicting flags"];
    [log append:@""];
    [log append:@"two"];
    [log append:@"three"];
    XCTAssertEqualObjects(log.lines, (@[@"one", @"two", @"three"]));
    [log append:@"four"];
    XCTAssertEqualObjects(log.lines, (@[@"two", @"three", @"four"]), @"oldest line is evicted");
    XCTAssertEqualObjects([log tail:2], @"three\nfour");
    XCTAssertEqual(log.count, 3u);
    [log clear];
    XCTAssertEqual(log.count, 0u);
}

- (void)testLogBufferPostsCoalescedNotification {
    DSHLogBuffer *log = [[DSHLogBuffer alloc] initWithCapacity:10];
    XCTestExpectation *e = [self expectationForNotification:DSHLogBufferDidChangeNotification object:log handler:nil];
    e.assertForOverFulfill = NO;
    for (int i = 0; i < 20; i++) [log append:[NSString stringWithFormat:@"l%d", i]];
    [self waitForExpectations:@[e] timeout:2];
    XCTAssertEqual(log.count, 10u);
}

- (void)testLogBufferRedactsCredentialsBeforeRetainingThem {
    DSHLogBuffer *log = [[DSHLogBuffer alloc] initWithCapacity:10];
    [log append:@"DEEPSEEK_API_KEY=secret-value request failed"];
    [log append:@"Authorization: Bearer another-secret"];
    NSString *text = [log.lines componentsJoinedByString:@"\n"];
    XCTAssertFalse([text containsString:@"secret-value"]);
    XCTAssertFalse([text containsString:@"another-secret"]);
    XCTAssertTrue([text containsString:@"<redacted>"]);
}

- (void)testReadinessProbeSucceedsWhenServerAnswers {
    DSHTestHTTPServer *server = [[DSHTestHTTPServer alloc] initWithPort:0];
    DSHReadinessProbe *probe = [[DSHReadinessProbe alloc] initWithURL:server.baseURL interval:0.1 timeout:5];
    XCTestExpectation *e = [self expectationWithDescription:@"ready"];
    [probe startWithHandler:^(BOOL ready, NSTimeInterval elapsed) {
        XCTAssertTrue(ready);
        XCTAssertLessThan(elapsed, 5);
        [e fulfill];
    }];
    [self waitForExpectations:@[e] timeout:6];
    XCTAssertFalse(probe.running);
    XCTAssertGreaterThan(server.requestCount, 0u);
    [server stop];
}

- (void)testReadinessProbeTimesOutOnClosedPort {
    uint16_t port = [DSHPortAllocator freeLoopbackPortStartingAt:39000 span:100];
    NSURL *url = [NSURL URLWithString:[NSString stringWithFormat:@"http://127.0.0.1:%u/", port]];
    DSHReadinessProbe *probe = [[DSHReadinessProbe alloc] initWithURL:url interval:0.1 timeout:1];
    XCTestExpectation *e = [self expectationWithDescription:@"timeout"];
    [probe startWithHandler:^(BOOL ready, NSTimeInterval elapsed) {
        XCTAssertFalse(ready);
        XCTAssertGreaterThanOrEqual(elapsed, 1.0);
        [e fulfill];
    }];
    [self waitForExpectations:@[e] timeout:5];
}

- (void)testReadinessProbeCancelFiresHandlerOnce {
    uint16_t port = [DSHPortAllocator freeLoopbackPortStartingAt:39200 span:100];
    NSURL *url = [NSURL URLWithString:[NSString stringWithFormat:@"http://127.0.0.1:%u/", port]];
    DSHReadinessProbe *probe = [[DSHReadinessProbe alloc] initWithURL:url interval:0.1 timeout:30];
    __block int calls = 0;
    [probe startWithHandler:^(BOOL ready, NSTimeInterval elapsed) { calls++; XCTAssertFalse(ready); }];
    [probe cancel];
    [probe cancel];
    XCTAssertEqual(calls, 1);
    XCTAssertFalse(probe.running);
}

- (void)testHarnessReachesReadyAndPassesPortToGuest {
    // The fake "guest" is a host HTTP server on whatever port the harness picks.
    DSHFakeLauncher *launcher = [DSHFakeLauncher new];
    __block DSHTestHTTPServer *server = nil;
    launcher.onLaunch = ^(NSDictionary *env, void (^line)(NSString *, BOOL), void (^exit)(int)) {
        uint16_t port = (uint16_t) [env[@"DSH_PORT"] intValue];
        server = [[DSHTestHTTPServer alloc] initWithPort:port];
        line([NSString stringWithFormat:@"dsh web: http://127.0.0.1:%u", port], NO);
        line(@"Warning: disabling flag --expose_wasm due to conflicting flags", YES);
    };
    DSHHarness *h = [[DSHHarness alloc] initWithLauncher:launcher];
    h.preferredPort = 38080;
    h.startupTimeout = 10;
    XCTAssertEqual(h.state, DSHHarnessStateIdle);
    XCTAssertNil(h.baseURL);

    XCTestExpectation *ready = [self expectationForNotification:DSHHarnessStateDidChangeNotification object:h handler:^BOOL(NSNotification *n) {
        return h.state == DSHHarnessStateReady;
    }];
    [h start];
    XCTAssertEqual(h.state, DSHHarnessStateStarting);
    XCTAssertEqual(launcher.launches.count, 1u);
    NSDictionary *first = launcher.launches.firstObject;
    NSString *exe = first[@"exe"];
    NSString *envPort = first[@"env"][@"DSH_PORT"];
    NSString *expectedPort = [NSString stringWithFormat:@"%u", h.port];
    XCTAssertEqualObjects(exe, @"/usr/local/bin/dsh-serve");
    XCTAssertEqualObjects(envPort, expectedPort);
    XCTAssertTrue(h.port >= 38080 && h.port < 38100);
    [self waitForExpectations:@[ready] timeout:10];

    XCTAssertEqualObjects(h.baseURL.absoluteString, ([NSString stringWithFormat:@"http://127.0.0.1:%u/", h.port]));
    XCTAssertTrue([[h.log tail:50] containsString:@"dsh web: http://127.0.0.1:"]);
    XCTAssertFalse([[h.log tail:50] containsString:@"expose_wasm"], @"noise is filtered");
    XCTAssertTrue([[h.log tail:50] containsString:@"server answered"]);
    XCTAssertGreaterThan(h.guestPid, 0);

    // stop kills the guest and reports stopped
    [h stop];
    XCTAssertEqual(h.state, DSHHarnessStateStopped);
    XCTAssertEqualObjects(launcher.killed.lastObject, @(100));
    [server stop];
}

- (void)testHarnessRelaunchesAfterCrashThenGivesUp {
    DSHFakeLauncher *launcher = [DSHFakeLauncher new];
    launcher.onLaunch = ^(NSDictionary *env, void (^line)(NSString *, BOOL), void (^exit)(int)) {
        // crash right away, asynchronously like the real executor
        dispatch_async(dispatch_get_main_queue(), ^{ exit(7); });
    };
    DSHHarness *h = [[DSHHarness alloc] initWithLauncher:launcher];
    h.preferredPort = 38200;
    h.maxConsecutiveCrashes = 2;   // back-off 1s, 2s -> then failed
    XCTestExpectation *failed = [self expectationForNotification:DSHHarnessStateDidChangeNotification object:h handler:^BOOL(NSNotification *n) {
        return h.state == DSHHarnessStateFailed;
    }];
    [h start];
    [self waitForExpectations:@[failed] timeout:15];
    XCTAssertEqual(launcher.launches.count, 3u, @"initial launch + 2 retries");
    XCTAssertTrue([h.lastError containsString:@"exited with code 7"]);
    XCTAssertGreaterThanOrEqual(h.restartCount, 2u);
}

- (void)testHarnessRestartRelaunchesOnSamePort {
    DSHFakeLauncher *launcher = [DSHFakeLauncher new];
    NSMutableArray<DSHTestHTTPServer *> *servers = [NSMutableArray array];
    launcher.onLaunch = ^(NSDictionary *env, void (^line)(NSString *, BOOL), void (^exit)(int)) {
        [servers addObject:[[DSHTestHTTPServer alloc] initWithPort:(uint16_t) [env[@"DSH_PORT"] intValue]]];
    };
    DSHHarness *h = [[DSHHarness alloc] initWithLauncher:launcher];
    h.preferredPort = 38300;
    XCTestExpectation *ready1 = [self expectationForNotification:DSHHarnessStateDidChangeNotification object:h handler:^BOOL(NSNotification *n) { return h.state == DSHHarnessStateReady; }];
    [h start];
    [self waitForExpectations:@[ready1] timeout:10];
    uint16_t port = h.port;
    [servers.lastObject stop];   // the "old" server goes away with the kill

    XCTestExpectation *ready2 = [self expectationForNotification:DSHHarnessStateDidChangeNotification object:h handler:^BOOL(NSNotification *n) { return h.state == DSHHarnessStateReady; }];
    [h restart];
    XCTAssertEqual(h.state, DSHHarnessStateStopped, @"restart first stops");
    [self waitForExpectations:@[ready2] timeout:10];
    XCTAssertEqual(h.port, port, @"same port reused when free");
    XCTAssertEqual(launcher.launches.count, 2u);
    XCTAssertEqual(h.restartCount, 1u);
    for (DSHTestHTTPServer *s in servers) [s stop];
}

- (void)testStateNames {
    XCTAssertEqualObjects(DSHHarnessStateName(DSHHarnessStateReady), @"ready");
    XCTAssertEqualObjects(DSHHarnessStateName(DSHHarnessStateFailed), @"failed");
    XCTAssertEqualObjects(DSHHarnessStateName(DSHHarnessStateIdle), @"idle");
}

- (void)testModelProviderNames {
    XCTAssertEqualObjects(DSHModelProviderName(DSHModelProviderApplePCC), @"Apple PCC");
    XCTAssertEqualObjects(DSHModelProviderName(DSHModelProviderDeepSeekAPI), @"DeepSeek API");
}

- (void)testPCCSupportMatchesOperatingSystemAvailability {
    if (@available(iOS 27.0, *))
        XCTAssertTrue(DSHApplePCCSupported());
    else
        XCTAssertFalse(DSHApplePCCSupported());
}

@end

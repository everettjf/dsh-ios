//
//  DSHRootUpgrader.m
//  DSH
//

#import "DSHRootUpgrader.h"
#import "Roots.h"
#import "ISHShellExecutor.h"
#import "AppGroup.h"
#include "kernel/init.h"
#include "kernel/calls.h"
#include "kernel/fs.h"
#include "kernel/task.h"
#include "fs/path.h"

static NSString *const kInstalledRootHashKey = @"DSHInstalledRootHash";
static NSString *const kPendingMigrationRootKey = @"DSHPendingMigrationRoot";
static NSString *const kRepairRootOnNextLaunchKey = @"DSHRepairRootOnNextLaunch";
static NSString *const kPrevMountPoint = @"/mnt/dsh-previous-root";

/// Bridges Roots' import progress to a block.
@interface DSHImportProgress : NSObject <ProgressReporter>
@property (nonatomic, copy, nullable) void (^handler)(double, NSString *);
@end

@implementation DSHImportProgress
- (void)updateProgress:(double)fraction message:(NSString *)message {
    if (self.handler) self.handler(fraction, message);
}
- (BOOL)shouldCancel { return NO; }
@end

@interface DSHRootUpgrader ()
@property (nonatomic, readwrite, nullable) NSString *bundledRootHash;
@end

@implementation DSHRootUpgrader

+ (instancetype)shared {
    static DSHRootUpgrader *shared;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ shared = [DSHRootUpgrader new]; });
    return shared;
}

- (instancetype)init {
    if (self = [super init]) {
        NSURL *shaURL = [NSBundle.mainBundle URLForResource:@"root.tar.gz" withExtension:@"sha256"];
        NSString *sha = shaURL ? [NSString stringWithContentsOfURL:shaURL encoding:NSUTF8StringEncoding error:nil] : nil;
        sha = [sha stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceAndNewlineCharacterSet];
        _bundledRootHash = sha.length ? sha : nil;
    }
    return self;
}

- (NSString *)installedRootHash {
    return [NSUserDefaults.standardUserDefaults stringForKey:kInstalledRootHashKey];
}

- (NSString *)pendingMigrationRoot {
    return [NSUserDefaults.standardUserDefaults stringForKey:kPendingMigrationRootKey];
}

- (BOOL)repairScheduled {
    return [NSUserDefaults.standardUserDefaults boolForKey:kRepairRootOnNextLaunchKey];
}

- (void)scheduleRepairOnNextLaunch {
    [NSUserDefaults.standardUserDefaults setBool:YES forKey:kRepairRootOnNextLaunchKey];
}

- (BOOL)prepareRootsBeforeBoot {
    return [self prepareRootsBeforeBootWithProgress:nil];
}

- (BOOL)prepareRootsBeforeBootWithProgress:(void (^)(double, NSString *))progressHandler {
    NSUserDefaults *defaults = NSUserDefaults.standardUserDefaults;
    NSString *bundled = self.bundledRootHash;
    // Look before Roots.instance exists: its first access imports the bundled
    // image as "default", which is exactly the fresh-install case.
    NSURL *rootsDir = [ContainerURL() URLByAppendingPathComponent:@"roots"];
    BOOL hadRoots = [NSFileManager.defaultManager contentsOfDirectoryAtPath:rootsDir.path error:nil].count > 0;
    if (!hadRoots && progressHandler)
        progressHandler(0, @"Installing the Linux image…");
    // First access imports the bundled image on a fresh install (no progress
    // callback available there — Roots owns that path).
    Roots *roots = Roots.instance;
    if (bundled == nil)
        return NO;

    if (self.installedRootHash == nil && !hadRoots) {
        // Fresh install: the default root is the bundled image, remember its hash.
        [defaults setObject:bundled forKey:kInstalledRootHashKey];
        return NO;
    }
    // installedRootHash == nil with existing roots means an install that
    // predates this bookkeeping: treat it as outdated and upgrade.
    BOOL repairing = self.repairScheduled;
    if ([self.installedRootHash isEqualToString:bundled] && !repairing)
        return NO;
    if (self.pendingMigrationRoot != nil)
        return NO; // an earlier upgrade is still waiting to migrate; finish it first

    NSString *suffix = [bundled substringToIndex:MIN(bundled.length, 8u)];
    NSString *newName = repairing
        ? [NSString stringWithFormat:@"dsh-repair-%@-%lld", suffix, (long long) NSDate.date.timeIntervalSince1970]
        : [NSString stringWithFormat:@"dsh-%@", suffix];
    if ([roots.roots containsObject:newName]) {
        // Left over from an interrupted attempt; start over.
        NSError *err;
        if (![roots destroyRootNamed:newName error:&err]) {
            NSLog(@"[dsh-ios] cannot remove stale root %@: %@", newName, err);
            return NO;
        }
    }
    NSURL *archive = [NSBundle.mainBundle URLForResource:@"root" withExtension:@"tar.gz"];
    NSError *error;
    NSLog(@"[dsh-ios] importing updated guest image as root %@", newName);
    DSHImportProgress *reporter = [DSHImportProgress new];
    reporter.handler = progressHandler;
    if (![roots importRootFromArchive:archive name:newName error:&error progressReporter:reporter]) {
        NSLog(@"[dsh-ios] import of updated root failed: %@ — keeping the current root", error);
        return NO;
    }
    NSString *previous = roots.defaultRoot;
    roots.defaultRoot = newName;
    [defaults setObject:bundled forKey:kInstalledRootHashKey];
    [defaults removeObjectForKey:kRepairRootOnNextLaunchKey];
    if (previous.length && ![previous isEqualToString:newName])
        [defaults setObject:previous forKey:kPendingMigrationRootKey];
    return YES;
}

- (void)migrateIfNeededWithCompletion:(void (^)(BOOL, NSError *_Nullable))completion {
    NSString *previous = self.pendingMigrationRoot;
    if (previous == nil || ![Roots.instance.roots containsObject:previous]) {
        if (previous)
            [NSUserDefaults.standardUserDefaults removeObjectForKey:kPendingMigrationRootKey];
        completion(NO, nil);
        return;
    }
    NSURL *prevData = [[Roots.instance rootUrl:previous] URLByAppendingPathComponent:@"data"];
    NSLog(@"[dsh-ios] migrating user data from root %@", previous);

    // Mount the previous root's fakefs read-write inside the running guest and
    // copy the harness home + workspace with the guest's own cp so ownership
    // and modes land in the new root's metadata.
    current = pid_get_task(1);
    generic_mkdirat(AT_PWD, "/mnt", 0755);
    generic_mkdirat(AT_PWD, kPrevMountPoint.UTF8String, 0755);
    int err = do_mount(&fakefs, prevData.fileSystemRepresentation, kPrevMountPoint.UTF8String, "", 0);
    if (err < 0) {
        NSError *e = [NSError errorWithDomain:NSPOSIXErrorDomain code:-err userInfo:@{NSLocalizedDescriptionKey: @"could not mount previous root"}];
        NSLog(@"[dsh-ios] %@ (%d)", e.localizedDescription, err);
        completion(NO, e);
        return;
    }
    // The harness home carries user data (sessions, credentials, settings) and
    // the patch files this image ships. Copy the whole directory for the data,
    // then put this image's patches back — otherwise an update silently keeps
    // the previous image's configuration, including which plugins are mounted.
    NSString *script = [NSString stringWithFormat:
        @"set -e; P=%@; "
        @"if [ -d \"$P/root/.dsh\" ]; then rm -rf /root/.dsh && cp -a \"$P/root/.dsh\" /root/.dsh; fi; "
        @"install -m 0644 /usr/local/share/dsh/home.patch.yml /root/.dsh/cordis.patch.yml; "
        @"[ -d /root/.dsh/profiles/web ] && install -m 0644 /usr/local/share/dsh/cordis.patch.yml /root/.dsh/profiles/web/cordis.patch.yml; "
        @"if [ -d \"$P/root/workspace\" ]; then mkdir -p /root/workspace && cp -a \"$P/root/workspace/.\" /root/workspace/; fi; "
        @"for f in .gitconfig .ssh .npmrc .profile .ashrc; do [ -e \"$P/root/$f\" ] && cp -a \"$P/root/$f\" /root/ || true; done; "
        @"echo MIGRATION-DONE", kPrevMountPoint];
    __block BOOL sawDone = NO;
    [ISHShellExecutor executeCommand:script lineCallback:^(NSString *line, BOOL isStdErr) {
        if ([line containsString:@"MIGRATION-DONE"]) sawDone = YES;
        NSLog(@"[dsh-ios] migrate: %@", line);
    } completion:^(ISHShellExecutionResult *result) {
        do_umount(kPrevMountPoint.UTF8String);
        NSError *e = nil;
        BOOL ok = result.exitCode == 0 && sawDone;
        if (ok) {
            NSError *destroyErr;
            if ([Roots.instance destroyRootNamed:previous error:&destroyErr])
                NSLog(@"[dsh-ios] removed previous root %@", previous);
            else
                NSLog(@"[dsh-ios] previous root %@ kept: %@", previous, destroyErr);
            [NSUserDefaults.standardUserDefaults removeObjectForKey:kPendingMigrationRootKey];
        } else {
            e = [NSError errorWithDomain:@"DSH" code:result.exitCode userInfo:@{NSLocalizedDescriptionKey: @"user data migration failed; previous root kept"}];
            NSLog(@"[dsh-ios] %@ (exit %d)", e.localizedDescription, result.exitCode);
            // Leave the pending marker so the next launch retries.
        }
        completion(ok, e);
    }];
}

@end

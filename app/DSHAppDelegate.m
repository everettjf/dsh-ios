//
//  DSHAppDelegate.m
//  DSH
//

#import "DSHAppDelegate.h"
#import "DSHHarness.h"
#import "DSHRootUpgrader.h"
#import "DSHRootViewController.h"

@implementation DSHAppDelegate

- (BOOL)application:(UIApplication *)application willFinishLaunchingWithOptions:(NSDictionary<UIApplicationLaunchOptionsKey,id> *)launchOptions {
    // Import an updated guest image (if this build ships one) before the
    // kernel mounts the default root.
    if (![NSUserDefaults.standardUserDefaults boolForKey:@"recovery"])
        [DSHRootUpgrader.shared prepareRootsBeforeBoot];
    return [super application:application willFinishLaunchingWithOptions:launchOptions];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    BOOL ok = [super application:application didFinishLaunchingWithOptions:launchOptions];
    // The kernel booted in -willFinishLaunching (or failed: bootError != 0).
    if (AppDelegate.bootError != 0) {
        NSLog(@"[dsh-ios] kernel boot failed with %d; not starting harness", AppDelegate.bootError);
        return ok;
    }
    DSHHarness *harness = DSHHarness.shared;
    if (DSHRootUpgrader.shared.pendingMigrationRoot != nil) {
        [harness.log append:@"[dsh-ios] new guest image installed; migrating your sessions and workspace…"];
        [DSHRootUpgrader.shared migrateIfNeededWithCompletion:^(BOOL migrated, NSError *error) {
            if (error)
                [harness.log append:[NSString stringWithFormat:@"[dsh-ios] migration problem: %@", error.localizedDescription]];
            else if (migrated)
                [harness.log append:@"[dsh-ios] migration complete"];
            [harness start];
        }];
    } else {
        [harness start];
    }
    return ok;
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Suspension may have broken the guest's sockets. Confirm the server still
    // answers; DSHHarness restarts it otherwise and the UI reloads.
    [DSHHarness.shared verifyAliveWithCompletion:nil];
}

@end

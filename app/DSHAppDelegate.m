//
//  DSHAppDelegate.m
//  DSH
//

#import "DSHAppDelegate.h"

// iSH's AppDelegate boots the kernel inside -willFinishLaunching. That takes
// far longer than iOS's launch watchdog allows on a phone (importing the guest
// image alone can take a minute), so DSH overrides both launch methods, keeps
// only their cheap parts, and lets DSHBootCoordinator do the work in the
// background while the UI is already on screen.
@implementation DSHAppDelegate

- (BOOL)application:(UIApplication *)application willFinishLaunchingWithOptions:(NSDictionary<UIApplicationLaunchOptionsKey,id> *)launchOptions {
    NSUserDefaults *defaults = NSUserDefaults.standardUserDefaults;
    if ([defaults boolForKey:@"hail mary"]) {
        [defaults removeObjectForKey:@"Boot Command"];
        [defaults removeObjectForKey:@"Init Command"];
        [defaults setBool:NO forKey:@"hail mary"];
    }
    return YES;   // deliberately no [super ...]: that would boot synchronously
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // The native agent starts immediately. Linux is launched only when a tool
    // explicitly needs it; see LazyGuestManager in the guest integration phase.
    return YES;
}

@end

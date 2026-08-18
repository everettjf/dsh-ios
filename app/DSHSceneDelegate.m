//
//  DSHSceneDelegate.m
//  DSH
//

#import "DSHSceneDelegate.h"
#import "DSHRootViewController.h"
#import "AppDelegate.h"
#import "AboutViewController.h"

@implementation DSHSceneDelegate

- (void)scene:(UIScene *)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *)connectionOptions {
    UIWindowScene *windowScene = (UIWindowScene *) scene;
    self.window = [[UIWindow alloc] initWithWindowScene:windowScene];
    if ([NSUserDefaults.standardUserDefaults boolForKey:@"recovery"]) {
        // Same escape hatch as iSH: the kernel is not booted, only settings.
        UINavigationController *vc = [[UIStoryboard storyboardWithName:@"About" bundle:nil] instantiateInitialViewController];
        ((AboutViewController *) vc.topViewController).recoveryMode = YES;
        self.window.rootViewController = vc;
    } else {
        self.window.rootViewController = [[DSHRootViewController alloc] init];
    }
    [self.window makeKeyAndVisible];
}

- (void)sceneDidBecomeActive:(UIScene *)scene {
    UIViewController *root = self.window.rootViewController;
    if ([root isKindOfClass:DSHRootViewController.class])
        [(DSHRootViewController *) root sceneDidBecomeActive];
}

@end

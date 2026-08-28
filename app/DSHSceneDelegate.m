//
//  DSHSceneDelegate.m
//  DSH
//

#import "DSHSceneDelegate.h"
#import "DSHBootCoordinator.h"
#import "DSH-Swift.h"

@implementation DSHSceneDelegate

- (void)scene:(UIScene *)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *)connectionOptions {
    // Native tools must be ready with the Swift UI. This only registers their
    // in-process routes; Linux remains dormant until a guest tool is requested.
    [DSHBootCoordinator prepareNativeCapabilities];
    UIWindowScene *windowScene = (UIWindowScene *) scene;
    self.window = [[UIWindow alloc] initWithWindowScene:windowScene];
    self.window.rootViewController = [DSHNativeRootFactory makeViewController];
    [self.window makeKeyAndVisible];
}

@end

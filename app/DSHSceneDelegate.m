//
//  DSHSceneDelegate.m
//  DSH
//

#import "DSHSceneDelegate.h"
#import "DSH-Swift.h"

@implementation DSHSceneDelegate

- (void)scene:(UIScene *)scene willConnectToSession:(UISceneSession *)session options:(UISceneConnectionOptions *)connectionOptions {
    UIWindowScene *windowScene = (UIWindowScene *) scene;
    self.window = [[UIWindow alloc] initWithWindowScene:windowScene];
    self.window.rootViewController = [DSHNativeRootFactory makeViewController];
    [self.window makeKeyAndVisible];
}

@end

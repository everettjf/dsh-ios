//
//  DSHCallConfirmation.m
//  DSH
//

#import "DSHCallConfirmation.h"
#import "DSHHostBridge.h"
#import "DSHHarness.h"
#import <UIKit/UIKit.h>

/// Long enough for someone to read the alert and decide, short enough that an
/// abandoned prompt does not hold an agent turn open indefinitely.
static const NSTimeInterval kDefaultTimeout = 45;

static BOOL sAutoApprove = NO;
static BOOL sAutoDecline = NO;
static NSUInteger sPresentedCount = 0;
/// Guards "one alert at a time" across the bridge's concurrent handlers.
static BOOL sPromptUp = NO;
static NSLock *sLock = nil;

@implementation DSHCallConfirmation

+ (void)initialize {
    if (self == DSHCallConfirmation.class)
        sLock = [NSLock new];
}

+ (BOOL)automaticallyApproveForTesting { return sAutoApprove; }
+ (void)setAutomaticallyApproveForTesting:(BOOL)value { sAutoApprove = value; }
+ (BOOL)automaticallyDeclineForTesting { return sAutoDecline; }
+ (void)setAutomaticallyDeclineForTesting:(BOOL)value { sAutoDecline = value; }
+ (NSUInteger)presentedCount { return sPresentedCount; }

+ (DSHConfirmationOutcome)confirmTitle:(NSString *)title detail:(NSString *)detail {
    return [self confirmTitle:title detail:detail timeout:kDefaultTimeout];
}

+ (DSHConfirmationOutcome)confirmTitle:(NSString *)title
                                detail:(NSString *)detail
                               timeout:(NSTimeInterval)timeout {
    if (sAutoApprove)
        return DSHConfirmationGranted;
    if (sAutoDecline)
        return DSHConfirmationDeclined;

    [sLock lock];
    if (sPromptUp) {
        // A second call arriving while the user is still reading the first one
        // is refused rather than queued: stacked dialogs are how an agent turns
        // one careless loop into a wall of prompts.
        [sLock unlock];
        return DSHConfirmationUnavailable;
    }
    sPromptUp = YES;
    [sLock unlock];

    __block DSHConfirmationOutcome outcome = DSHConfirmationUnavailable;
    dispatch_semaphore_t answered = dispatch_semaphore_create(0);
    dispatch_async(dispatch_get_main_queue(), ^{
        UIViewController *presenter = [self topViewController];
        if (presenter == nil || UIApplication.sharedApplication.applicationState != UIApplicationStateActive) {
            // Nothing the user can see: fail fast instead of waiting on a
            // dialog that will only appear after they come back.
            dispatch_semaphore_signal(answered);
            return;
        }
        sPresentedCount += 1;
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:title
                                                                      message:detail
                                                               preferredStyle:UIAlertControllerStyleAlert];
        [alert addAction:[UIAlertAction actionWithTitle:@"Don't Allow" style:UIAlertActionStyleCancel handler:^(UIAlertAction *a) {
            outcome = DSHConfirmationDeclined;
            dispatch_semaphore_signal(answered);
        }]];
        [alert addAction:[UIAlertAction actionWithTitle:@"Allow" style:UIAlertActionStyleDefault handler:^(UIAlertAction *a) {
            outcome = DSHConfirmationGranted;
            dispatch_semaphore_signal(answered);
        }]];
        alert.view.accessibilityIdentifier = @"dsh.confirmation";
        [presenter presentViewController:alert animated:YES completion:nil];

        // The alert has to come down on timeout too, or it sits there long
        // after the call it belongs to has been answered.
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t) (timeout * NSEC_PER_SEC)),
                       dispatch_get_main_queue(), ^{
            if (alert.presentingViewController == nil)
                return;
            [alert dismissViewControllerAnimated:YES completion:nil];
            outcome = DSHConfirmationTimedOut;
            dispatch_semaphore_signal(answered);
        });
    });

    // +2s so the main-queue timeout above wins and the alert is dismissed,
    // rather than this wait expiring first and leaving it on screen.
    dispatch_semaphore_wait(answered, dispatch_time(DISPATCH_TIME_NOW, (int64_t) ((timeout + 2) * NSEC_PER_SEC)));
    [sLock lock];
    sPromptUp = NO;
    [sLock unlock];

    [DSHHarness.shared.log append:[NSString stringWithFormat:@"[bridge] confirmation “%@”: %@", title,
                                   outcome == DSHConfirmationGranted ? @"allowed"
                                   : outcome == DSHConfirmationDeclined ? @"declined"
                                   : outcome == DSHConfirmationTimedOut ? @"timed out" : @"could not ask"]];
    return outcome;
}

+ (nullable UIViewController *)topViewController {
    UIWindow *window = nil;
    for (UIScene *scene in UIApplication.sharedApplication.connectedScenes) {
        if (![scene isKindOfClass:UIWindowScene.class] || scene.activationState != UISceneActivationStateForegroundActive)
            continue;
        for (UIWindow *candidate in ((UIWindowScene *) scene).windows)
            if (candidate.isKeyWindow) { window = candidate; break; }
        if (window) break;
    }
    UIViewController *controller = window.rootViewController;
    while (controller.presentedViewController)
        controller = controller.presentedViewController;
    return controller;
}

+ (nullable id)refusalFor:(DSHConfirmationOutcome)outcome action:(NSString *)action {
    switch (outcome) {
        case DSHConfirmationGranted:
            return nil;
        case DSHConfirmationDeclined:
            return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                                  message:[NSString stringWithFormat:
                                                           @"The user declined: %@. Do not retry the same action; ask them what they would prefer.", action]
                                              recoverable:NO];
        case DSHConfirmationTimedOut:
            return [DSHHostBridgeResponse errorWithStatus:408 code:@"permission_denied"
                                                  message:[NSString stringWithFormat:
                                                           @"Nobody answered the confirmation for: %@. The user may have put the device down; say what you were about to do and wait for them.", action]
                                              recoverable:YES];
        case DSHConfirmationUnavailable:
            return [DSHHostBridgeResponse errorWithStatus:409 code:@"unavailable"
                                                  message:[NSString stringWithFormat:
                                                           @"DSH could not ask the user about: %@ — the app is in the background, or another confirmation is already open. Try once the user is back in DSH.", action]
                                              recoverable:YES];
    }
}

@end

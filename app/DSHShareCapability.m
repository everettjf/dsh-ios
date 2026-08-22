//
//  DSHShareCapability.m
//  DSH
//

#import "DSHShareCapability.h"
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHCallConfirmation.h"
#import "DSHHarness.h"
#import <UIKit/UIKit.h>

NSString *const DSHCapabilityShare = @"share.present";

/// Long enough for a message or a note, short enough that the confirmation can
/// show a meaningful part of it before the sheet appears.
static const NSUInteger kMaxCharacters = 4000;

/// The sheet stays up until it is dealt with; this only bounds the wait so the
/// turn ends with an answer rather than hanging.
static const NSTimeInterval kSheetTimeout = 180;

@implementation DSHShareCapability

+ (NSUInteger)maximumCharacters { return kMaxCharacters; }

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

+ (void)installOn:(DSHHostBridge *)bridge {
    [DSHCapabilityRegistry.shared registerCapability:
        [[DSHCapability alloc] initWithIdentifier:DSHCapabilityShare
                                            title:@"Share sheet"
                                          details:@"Lets the agent offer text to the iOS share sheet. DSH asks every time, and shows you the text."
                                             gate:DSHCapabilityGatePerCall
                                 enabledByDefault:YES
                                        available:YES]];

    [bridge registerRoute:@"POST" path:@"/v1/share" capability:DSHCapabilityShare
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        NSString *text = request.json[@"text"];
        if (![text isKindOfClass:NSString.class] || text.length == 0)
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:@"Send a JSON body with a non-empty `text`."
                                              recoverable:NO];
        if (text.length > kMaxCharacters)
            return [DSHHostBridgeResponse errorWithStatus:413 code:@"invalid_request"
                                                  message:[NSString stringWithFormat:
                                                           @"That is %lu characters and the share route takes at most %lu.",
                                                           (unsigned long) text.length, (unsigned long) kMaxCharacters]
                                              recoverable:NO];

        // Shown before the sheet, in DSH's sentence, because the sheet itself
        // asks only where the text goes and not whether it should go at all.
        NSString *detail = [NSString stringWithFormat:@"DSH wants to share this text:\n\n“%@”\n\nYou will choose where it goes.",
                            DSHDisplayValue(text, 300)];
        DSHConfirmationOutcome outcome = [DSHCallConfirmation confirmTitle:@"Share this?" detail:detail
                                                               capability:DSHCapabilityShare];
        DSHHostBridgeResponse *declined =
            [DSHCallConfirmation refusalFor:outcome
                                     action:[NSString stringWithFormat:@"sharing “%@”", DSHDisplayValue(text, 60)]];
        if (declined)
            return declined;

        __block BOOL presented = NO;
        dispatch_semaphore_t done = dispatch_semaphore_create(0);
        __block BOOL completed = NO;
        __block NSString *destination = nil;
        DSHRunOnMainSync(^{
            UIViewController *top = [self topViewController];
            if (top == nil)
                return;
            UIActivityViewController *sheet =
                [[UIActivityViewController alloc] initWithActivityItems:@[text] applicationActivities:nil];
            sheet.completionWithItemsHandler = ^(UIActivityType type, BOOL ok, NSArray *items, NSError *error) {
                completed = ok;
                destination = type;
                dispatch_semaphore_signal(done);
            };
            // An iPad presents this as a popover and needs somewhere to point.
            sheet.popoverPresentationController.sourceView = top.view;
            sheet.popoverPresentationController.sourceRect =
                CGRectMake(CGRectGetMidX(top.view.bounds), CGRectGetMaxY(top.view.bounds) - 1, 1, 1);
            sheet.popoverPresentationController.permittedArrowDirections = UIPopoverArrowDirectionDown;
            [top presentViewController:sheet animated:YES completion:nil];
            presented = YES;
        });
        if (!presented)
            return [DSHHostBridgeResponse errorWithStatus:409 code:@"unavailable"
                                                  message:@"DSH is not in the foreground, so it cannot show the share sheet. Ask the user to open DSH and try again."
                                              recoverable:YES];

        if (dispatch_semaphore_wait(done, dispatch_time(DISPATCH_TIME_NOW, (int64_t) (kSheetTimeout * NSEC_PER_SEC))) != 0)
            return [DSHHostBridgeResponse errorWithStatus:504 code:@"timeout"
                                                  message:@"The share sheet was left open for three minutes without an answer."
                                              recoverable:YES];

        [DSHHarness.shared.log append:[NSString stringWithFormat:@"[bridge] share sheet %@",
                                       completed ? @"completed" : @"dismissed"]];
        // Which app the user picked is theirs to know, not the agent's: the
        // answer says whether the text left, not where it went.
        return [DSHHostBridgeResponse ok:@{
            @"shared": @(completed),
            @"note": completed
                ? @"The user shared the text. Where it went is not reported."
                : @"The user dismissed the share sheet without sharing.",
        }];
    }];
}

@end

//
//  DSHCallConfirmation.m
//  DSH
//

#import "DSHCallConfirmation.h"
#import "DSHHostBridge.h"
#import "DSHHarness.h"
#import "DSHActivityLog.h"
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

NSString *DSHDisplayValue(NSString *value, NSUInteger limit) {
    if (![value isKindOfClass:NSString.class] || value.length == 0)
        return @"";

    // Control characters and the bidi overrides, which are formatting rather
    // than control and so survive a plain control-character filter.
    static NSCharacterSet *removed;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        NSMutableCharacterSet *set = [NSMutableCharacterSet new];
        // Cc only, spelled out. NSCharacterSet.controlCharacterSet is Cc *and*
        // Cf, and Cf contains the zero-width joiner: filtering the whole
        // category takes a family emoji apart into four people and breaks
        // Indic and Persian text that joins with ZWJ/ZWNJ on purpose.
        [set addCharactersInRange:NSMakeRange(0x0000, 0x0020)];
        [set addCharactersInRange:NSMakeRange(0x007F, 0x0021)];  // DEL + C1
        [set formUnionWithCharacterSet:NSCharacterSet.illegalCharacterSet];
        // The formatting characters that actually reorder what is displayed.
        [set addCharactersInRange:NSMakeRange(0x202A, 5)];   // LRE RLE PDF LRO RLO
        [set addCharactersInRange:NSMakeRange(0x2066, 4)];   // LRI RLI FSI PDI
        [set addCharactersInRange:NSMakeRange(0x200E, 2)];   // LRM RLM
        [set addCharactersInRange:NSMakeRange(0x061C, 1)];   // ALM
        // Tabs and newlines are Cc, and the whitespace collapse below turns
        // them into a single space rather than joining the words either side.
        [set removeCharactersInRange:NSMakeRange(0x0009, 1)];
        [set removeCharactersInRange:NSMakeRange(0x000A, 1)];
        [set removeCharactersInRange:NSMakeRange(0x000D, 1)];
        removed = set;
    });

    NSString *stripped = [[value componentsSeparatedByCharactersInSet:removed] componentsJoinedByString:@""];
    NSArray *words = [stripped componentsSeparatedByCharactersInSet:NSCharacterSet.whitespaceAndNewlineCharacterSet];
    NSMutableArray *kept = [NSMutableArray array];
    for (NSString *word in words)
        if (word.length) [kept addObject:word];
    NSString *flat = [kept componentsJoinedByString:@" "];

    if (flat.length > limit) {
        // Enumerating gives grapheme clusters, ZWJ sequences included;
        // -rangeOfComposedCharacterSequencesForRange: does not span a ZWJ and
        // cuts a family emoji apart. Whole clusters only, so the result can
        // come in under the limit rather than over it.
        __block NSUInteger cut = 0;
        [flat enumerateSubstringsInRange:NSMakeRange(0, flat.length)
                                 options:NSStringEnumerationByComposedCharacterSequences
                              usingBlock:^(NSString *sub, NSRange range, NSRange enclosing, BOOL *stop) {
            if (NSMaxRange(range) > limit) { *stop = YES; return; }
            cut = NSMaxRange(range);
        }];
        flat = [[flat substringToIndex:cut] stringByAppendingString:@"…"];
    }
    return flat;
}

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
                            capability:(NSString *)capability {
    NSUInteger recent = capability ? [DSHActivityLog.shared countOf:capability within:600] : 0;
    NSString *full = recent >= 3
        ? [detail stringByAppendingFormat:@"\n\nThis is the %lu%@ time in ten minutes.",
           (unsigned long) (recent + 1), (recent + 1) % 10 == 1 && (recent + 1) != 11 ? @"st" : (recent + 1) % 10 == 2 && (recent + 1) != 12 ? @"nd" : (recent + 1) % 10 == 3 && (recent + 1) != 13 ? @"rd" : @"th"]
        : detail;
    return [self confirmTitle:title detail:full timeout:kDefaultTimeout];
}

+ (DSHConfirmationOutcome)confirmTitle:(NSString *)title
                                detail:(NSString *)detail
                               timeout:(NSTimeInterval)timeout {
    if (sAutoApprove)
        return [self finish:DSHConfirmationGranted title:title detail:detail];
    if (sAutoDecline)
        return [self finish:DSHConfirmationDeclined title:title detail:detail];

    [sLock lock];
    if (sPromptUp) {
        // A second call arriving while the user is still reading the first one
        // is refused rather than queued: stacked dialogs are how an agent turns
        // one careless loop into a wall of prompts.
        [sLock unlock];
        return [self finish:DSHConfirmationUnavailable title:title detail:detail];
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
    return [self finish:outcome title:title detail:detail];
}

/// Every exit goes through here. Recording used to sit on the tail of the one
/// path that presents an alert, which meant the shortcuts above — and, more to
/// the point, any future early return — silently produced a decision that
/// never reached the record.
+ (DSHConfirmationOutcome)finish:(DSHConfirmationOutcome)outcome
                           title:(NSString *)title
                          detail:(NSString *)detail {
    [DSHHarness.shared.log append:[NSString stringWithFormat:@"[bridge] confirmation “%@”: %@", title,
                                   outcome == DSHConfirmationGranted ? @"allowed"
                                   : outcome == DSHConfirmationDeclined ? @"declined"
                                   : outcome == DSHConfirmationTimedOut ? @"timed out" : @"could not ask"]];
    // The detail is what the user was shown, so recording it leaks nothing
    // they have not already seen — and it is the only way the log can answer
    // "what exactly did I agree to".
    [DSHActivityLog.shared recordSource:DSHActivitySourceConfirmation
                                   name:title
                                 detail:detail
                                 result:nil
                                outcome:outcome == DSHConfirmationGranted ? DSHActivityOutcomeOK
                                        : outcome == DSHConfirmationDeclined ? DSHActivityOutcomeDeclined
                                        : outcome == DSHConfirmationTimedOut ? DSHActivityOutcomeTimedOut
                                        : DSHActivityOutcomeRefused
                               duration:0];
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

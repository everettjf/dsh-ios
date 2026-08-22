//
//  DSHShortcutsCapability.m
//  DSH
//

#import "DSHShortcutsCapability.h"
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHCallConfirmation.h"
#import <UIKit/UIKit.h>

NSString *const DSHCapabilityShortcutsRun = @"shortcuts.run";

@implementation DSHShortcutsCapability

+ (nullable NSURL *)urlForShortcut:(NSString *)name input:(nullable NSString *)input {
    if (name.length == 0)
        return nil;
    NSCharacterSet *allowed = NSCharacterSet.URLQueryAllowedCharacterSet;
    NSMutableCharacterSet *strict = [allowed mutableCopy];
    // & and = would otherwise let a shortcut name inject extra parameters.
    [strict removeCharactersInString:@"&=+?#"];
    NSString *encodedName = [name stringByAddingPercentEncodingWithAllowedCharacters:strict];
    NSMutableString *url = [NSMutableString stringWithFormat:@"shortcuts://x-callback-url/run-shortcut?name=%@", encodedName];
    if (input.length) {
        [url appendString:@"&input=text&text="];
        [url appendString:[input stringByAddingPercentEncodingWithAllowedCharacters:strict] ?: @""];
    }
    return [NSURL URLWithString:url];
}

+ (void)installOn:(DSHHostBridge *)bridge {
    [DSHCapabilityRegistry.shared registerCapability:
        [[DSHCapability alloc] initWithIdentifier:DSHCapabilityShortcutsRun
                                            title:@"Shortcuts"
                                          details:@"Runs one of your shortcuts by name. A shortcut can do anything you built it to do, and running one leaves DSH."
                                             gate:DSHCapabilityGatePerCall
                                 enabledByDefault:YES
                                        available:YES]];

    [bridge registerRoute:@"POST" path:@"/v1/shortcut/run" capability:DSHCapabilityShortcutsRun
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        NSString *name = request.json[@"name"];
        NSString *input = request.json[@"input"];
        if (![name isKindOfClass:NSString.class] || name.length == 0)
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:@"Send a JSON body with the shortcut's `name` (and optionally a text `input`)."
                                              recoverable:NO];
        if (input != nil && ![input isKindOfClass:NSString.class])
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:@"`input` must be a string."
                                              recoverable:NO];

        NSURL *url = [self urlForShortcut:name input:input];
        if (url == nil)
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:@"That shortcut name cannot be put in a URL."
                                              recoverable:NO];

        NSString *shownName = DSHDisplayValue(name, 80);
        NSString *detail = input.length
            ? [NSString stringWithFormat:@"DSH wants to run your shortcut “%@” with this input:\n\n“%@”\n\nDSH will close while it runs.", shownName, DSHDisplayValue(input, 200)]
            : [NSString stringWithFormat:@"DSH wants to run your shortcut “%@”. DSH will close while it runs.", shownName];
        DSHConfirmationOutcome outcome = [DSHCallConfirmation confirmTitle:@"Run a shortcut?" detail:detail
                                                                capability:DSHCapabilityShortcutsRun];
        DSHHostBridgeResponse *refusal = [DSHCallConfirmation refusalFor:outcome
                                                                 action:[NSString stringWithFormat:@"running the shortcut “%@”", shownName]];
        if (refusal)
            return refusal;

        __block BOOL opened = NO;
        dispatch_semaphore_t done = dispatch_semaphore_create(0);
        dispatch_async(dispatch_get_main_queue(), ^{
            [UIApplication.sharedApplication openURL:url options:@{} completionHandler:^(BOOL success) {
                opened = success;
                dispatch_semaphore_signal(done);
            }];
        });
        dispatch_semaphore_wait(done, dispatch_time(DISPATCH_TIME_NOW, (int64_t) (10 * NSEC_PER_SEC)));
        if (!opened)
            return [DSHHostBridgeResponse errorWithStatus:502 code:@"unavailable"
                                                  message:@"iOS would not open Shortcuts. It may not be installed, or the name has no matching shortcut."
                                              recoverable:NO];

        // Deliberately not a lie: we handed the URL to Shortcuts and that is
        // all we know. There is no result to return, and the emulator is about
        // to be suspended behind us.
        return [DSHHostBridgeResponse ok:@{
            @"started": @YES,
            @"name": name,
            @"note": @"Shortcuts has been opened and is running this in the foreground. DSH is now in the background, "
                     @"so this turn stops here and its result is not visible to DSH. Tell the user what you asked for "
                     @"and ask them to come back and say what happened.",
        }];
    }];
}

@end

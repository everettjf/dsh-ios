//
//  DSHClipboardCapability.m
//  DSH
//

#import "DSHClipboardCapability.h"
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHCallConfirmation.h"
#import <UIKit/UIKit.h>

NSString *const DSHCapabilityClipboardWrite = @"clipboard.write";

static const NSUInteger kMaxWriteCharacters = 100000;

@implementation DSHClipboardCapability

+ (NSString *)previewOf:(NSString *)text {
    NSString *flat = [[text stringByReplacingOccurrencesOfString:@"\n" withString:@" "]
                      stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceCharacterSet];
    if (flat.length <= 120)
        return flat;
    return [[flat substringToIndex:120] stringByAppendingString:@"…"];
}

+ (void)installOn:(DSHHostBridge *)bridge {
    [DSHCapabilityRegistry.shared registerCapability:
        [[DSHCapability alloc] initWithIdentifier:DSHCapabilityClipboardWrite
                                            title:@"Clipboard (write)"
                                          details:@"Lets the agent put text on your clipboard."
                                             gate:DSHCapabilityGatePerCall
                                 enabledByDefault:NO
                                        available:YES]];

    [bridge registerRoute:@"POST" path:@"/v1/clipboard" capability:DSHCapabilityClipboardWrite
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        NSString *text = request.json[@"text"];
        if (![text isKindOfClass:NSString.class])
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:@"Send a JSON body with a `text` string."
                                              recoverable:NO];
        if (text.length > kMaxWriteCharacters)
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:[NSString stringWithFormat:
                                                           @"That is %lu characters; the clipboard accepts at most %lu.",
                                                           (unsigned long) text.length, (unsigned long) kMaxWriteCharacters]
                                              recoverable:NO];

        DSHConfirmationOutcome outcome =
            [DSHCallConfirmation confirmTitle:@"Copy to clipboard?"
                                       detail:[NSString stringWithFormat:@"DSH wants to replace what you have copied with:\n\n%@\n\n(%lu characters)",
                                               [self previewOf:text], (unsigned long) text.length]];
        DSHHostBridgeResponse *refusal = [DSHCallConfirmation refusalFor:outcome action:@"copying text to the clipboard"];
        if (refusal)
            return refusal;

        dispatch_sync(dispatch_get_main_queue(), ^{
            UIPasteboard.generalPasteboard.string = text;
        });
        return [DSHHostBridgeResponse ok:@{ @"written": @YES, @"characters": @(text.length) }];
    }];
}

@end

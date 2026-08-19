//
//  DSHClipboardCapability.m
//  DSH
//

#import "DSHClipboardCapability.h"
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHCallConfirmation.h"
#import <UIKit/UIKit.h>

NSString *const DSHCapabilityClipboardRead = @"clipboard.read";
NSString *const DSHCapabilityClipboardWrite = @"clipboard.write";

/// The pasteboard can hold a whole document; the agent pays per token for it.
static const NSUInteger kMaxReadCharacters = 20000;
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
    DSHCapabilityRegistry *registry = DSHCapabilityRegistry.shared;
    [registry registerCapability:[[DSHCapability alloc] initWithIdentifier:DSHCapabilityClipboardRead
                                                                    title:@"Clipboard (read)"
                                                                  details:@"Whatever you last copied. iOS shows its own banner each time DSH reads it."
                                                                     gate:DSHCapabilityGateEnabledOnly
                                                         enabledByDefault:NO
                                                                available:YES]];
    [registry registerCapability:[[DSHCapability alloc] initWithIdentifier:DSHCapabilityClipboardWrite
                                                                    title:@"Clipboard (write)"
                                                                  details:@"Lets the agent replace what you have copied. Asks you every time."
                                                                     gate:DSHCapabilityGatePerCall
                                                         enabledByDefault:NO
                                                                available:YES]];

    [bridge registerRoute:@"GET" path:@"/v1/clipboard" capability:DSHCapabilityClipboardRead
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        __block NSString *text = nil;
        __block BOOL hasImage = NO, hasURL = NO;
        // UIPasteboard is main-thread only, and touching it raises the system
        // paste banner — which is the point: the user sees every read.
        dispatch_sync(dispatch_get_main_queue(), ^{
            UIPasteboard *board = UIPasteboard.generalPasteboard;
            hasImage = board.hasImages;
            hasURL = board.hasURLs;
            if (board.hasStrings)
                text = board.string;
        });
        BOOL truncated = text.length > kMaxReadCharacters;
        if (truncated)
            text = [text substringToIndex:kMaxReadCharacters];
        return [DSHHostBridgeResponse ok:@{
            @"text": text ?: @"",
            @"hasText": @(text.length > 0),
            @"hasImage": @(hasImage),
            @"hasURL": @(hasURL),
            @"characters": @(text.length),
            @"truncated": @(truncated),
        }];
    }];

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

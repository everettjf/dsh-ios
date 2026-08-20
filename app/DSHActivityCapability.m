//
//  DSHActivityCapability.m
//  DSH
//

#import "DSHActivityCapability.h"
#import "DSHHostBridge.h"
#import "DSHActivityLog.h"

/// A turn can report a burst; accept them in one request rather than one
/// connection each.
static const NSUInteger kMaxBatch = 50;

@implementation DSHActivityCapability

+ (void)installOn:(DSHHostBridge *)bridge {
    [bridge registerRoute:@"POST" path:@"/v1/activity" capability:nil
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        NSArray *events = request.json[@"events"];
        if (![events isKindOfClass:NSArray.class])
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:@"send {\"events\": [...]}"
                                              recoverable:NO];
        NSUInteger accepted = 0;
        for (NSDictionary *event in events) {
            if (accepted >= kMaxBatch)
                break;
            if (![event isKindOfClass:NSDictionary.class])
                continue;
            NSString *name = event[@"name"];
            if (![name isKindOfClass:NSString.class] || name.length == 0)
                continue;
            NSString *status = event[@"outcome"];
            DSHActivityOutcome outcome = DSHActivityOutcomeOK;
            if ([status isEqualToString:@"error"]) outcome = DSHActivityOutcomeError;
            else if ([status isEqualToString:@"refused"]) outcome = DSHActivityOutcomeRefused;
            else if ([status isEqualToString:@"declined"]) outcome = DSHActivityOutcomeDeclined;
            else if ([status isEqualToString:@"started"]) outcome = DSHActivityOutcomeStarted;

            [DSHActivityLog.shared recordSource:DSHActivitySourceGuestTool
                                           name:name
                                         detail:[event[@"detail"] isKindOfClass:NSString.class] ? event[@"detail"] : nil
                                         result:[event[@"result"] isKindOfClass:NSString.class] ? event[@"result"] : nil
                                        outcome:outcome
                                       duration:[event[@"duration"] doubleValue]
                                  correlationID:[event[@"id"] isKindOfClass:NSString.class] ? event[@"id"] : nil];
            accepted += 1;
        }
        return [DSHHostBridgeResponse ok:@{ @"accepted": @(accepted) }];
    }];
}

@end

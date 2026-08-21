//
//  DSHNotificationCapability.m
//  DSH
//

#import "DSHNotificationCapability.h"
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHHarness.h"
#import <UserNotifications/UserNotifications.h>

NSString *const DSHCapabilityNotify = @"notifications.post";

/// An agent in a loop should not be able to turn the lock screen into a wall.
static const NSUInteger kMaxPerHour = 10;
static NSMutableArray<NSDate *> *sRecent = nil;
static NSLock *sLock = nil;

@implementation DSHNotificationCapability

+ (void)initialize {
    if (self == DSHNotificationCapability.class) {
        sRecent = [NSMutableArray array];
        sLock = [NSLock new];
    }
}

+ (void)resetRateLimitForTesting {
    [sLock lock];
    [sRecent removeAllObjects];
    [sLock unlock];
}

/// YES when this notification fits inside the hourly budget (and records it).
+ (BOOL)takeRateLimitSlot:(NSUInteger *)remaining {
    [sLock lock];
    NSDate *cutoff = [NSDate dateWithTimeIntervalSinceNow:-3600];
    [sRecent filterUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(NSDate *date, NSDictionary *bindings) {
        return [date compare:cutoff] == NSOrderedDescending;
    }]];
    BOOL allowed = sRecent.count < kMaxPerHour;
    if (allowed)
        [sRecent addObject:NSDate.date];
    if (remaining)
        *remaining = kMaxPerHour - MIN(sRecent.count, kMaxPerHour);
    [sLock unlock];
    return allowed;
}

+ (void)requestAuthorization {
    [UNUserNotificationCenter.currentNotificationCenter
        requestAuthorizationWithOptions:UNAuthorizationOptionAlert | UNAuthorizationOptionSound | UNAuthorizationOptionBadge
                      completionHandler:^(BOOL granted, NSError *error) {
        [DSHHarness.shared.log append:[NSString stringWithFormat:@"[bridge] notifications %@",
                                       granted ? @"allowed" : @"refused"]];
    }];
}

+ (UNAuthorizationStatus)authorizationStatus {
    __block UNAuthorizationStatus status = UNAuthorizationStatusNotDetermined;
    dispatch_semaphore_t done = dispatch_semaphore_create(0);
    [UNUserNotificationCenter.currentNotificationCenter getNotificationSettingsWithCompletionHandler:^(UNNotificationSettings *settings) {
        status = settings.authorizationStatus;
        dispatch_semaphore_signal(done);
    }];
    dispatch_semaphore_wait(done, dispatch_time(DISPATCH_TIME_NOW, (int64_t) (5 * NSEC_PER_SEC)));
    return status;
}

+ (void)installOn:(DSHHostBridge *)bridge {
    DSHCapability *capability =
        [[DSHCapability alloc] initWithIdentifier:DSHCapabilityNotify
                                            title:@"Notifications"
                                          details:@"Lets the agent notify you when a long task finishes. At most 10 an hour."
                                             gate:DSHCapabilityGateSystemPermission
                                 enabledByDefault:YES
                                        available:YES];
    capability.requestSystemPermission = ^{ [self requestAuthorization]; };
    [DSHCapabilityRegistry.shared registerCapability:capability];

    [bridge registerRoute:@"POST" path:@"/v1/notify" capability:DSHCapabilityNotify
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        NSString *title = request.json[@"title"];
        NSString *body = request.json[@"body"];
        if (![title isKindOfClass:NSString.class] || title.length == 0)
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:@"Send a JSON body with a non-empty `title` (and optionally `body`)."
                                              recoverable:NO];

        UNAuthorizationStatus status = [self authorizationStatus];
        if (status == UNAuthorizationStatusNotDetermined) {
            [self requestAuthorization];
            return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                                  message:@"iOS has just asked the user whether DSH may send notifications. Tell them to allow it, then try again."
                                              recoverable:YES];
        }
        if (status == UNAuthorizationStatusDenied)
            return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                                  message:@"Notifications are turned off for DSH in iOS Settings ▸ Notifications."
                                              recoverable:YES];

        NSUInteger remaining = 0;
        if (![self takeRateLimitSlot:&remaining])
            return [DSHHostBridgeResponse errorWithStatus:429 code:@"rate_limited"
                                                  message:[NSString stringWithFormat:
                                                           @"DSH has already sent %lu notifications this hour, which is the limit. Tell the user in the conversation instead.",
                                                           (unsigned long) kMaxPerHour]
                                              recoverable:NO];

        UNMutableNotificationContent *content = [UNMutableNotificationContent new];
        content.title = title.length > 100 ? [title substringToIndex:100] : title;
        if ([body isKindOfClass:NSString.class] && body.length)
            content.body = body.length > 500 ? [body substringToIndex:500] : body;
        content.sound = UNNotificationSound.defaultSound;

        NSString *identifier = [@"dsh." stringByAppendingString:NSUUID.UUID.UUIDString];
        UNNotificationRequest *notification =
            [UNNotificationRequest requestWithIdentifier:identifier content:content trigger:nil];
        __block NSError *failure = nil;
        dispatch_semaphore_t done = dispatch_semaphore_create(0);
        [UNUserNotificationCenter.currentNotificationCenter addNotificationRequest:notification
                                                            withCompletionHandler:^(NSError *error) {
            failure = error;
            dispatch_semaphore_signal(done);
        }];
        dispatch_semaphore_wait(done, dispatch_time(DISPATCH_TIME_NOW, (int64_t) (5 * NSEC_PER_SEC)));
        if (failure)
            return [DSHHostBridgeResponse errorWithStatus:500 code:@"internal"
                                                  message:[NSString stringWithFormat:@"iOS refused the notification: %@", failure.localizedDescription]
                                              recoverable:NO];
        return [DSHHostBridgeResponse ok:@{ @"delivered": @YES, @"remainingThisHour": @(remaining) }];
    }];
}

@end

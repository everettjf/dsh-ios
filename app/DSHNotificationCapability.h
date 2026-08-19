//
//  DSHNotificationCapability.h
//  DSH
//
//  Local notifications, so a long agent turn can tell the user it is done.
//
//  This is the one capability whose whole point is to reach the user when they
//  are *not* looking at DSH — which is also why it is the easiest to abuse.
//  Notifications are rate limited per hour, and the text is the agent's, shown
//  under DSH's name.
//

#import <Foundation/Foundation.h>
@class DSHHostBridge;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const DSHCapabilityNotify;

@interface DSHNotificationCapability : NSObject
+ (void)installOn:(DSHHostBridge *)bridge;
/// Tests: forget the rate-limit history.
+ (void)resetRateLimitForTesting;
/// Takes one slot from the hourly budget; NO when it is exhausted. Exposed so
/// the limit can be tested without sending ten real notifications.
+ (BOOL)takeRateLimitSlot:(nullable NSUInteger *)remaining;
@end

NS_ASSUME_NONNULL_END

//
//  DSHEventKitCapability.h
//  DSH
//
//  Calendar and Reminders, read-only for now, over EventKit.
//
//  Both are gated twice: the user's switch in DSH's settings, and iOS's own
//  permission dialog. A call that arrives before the system has been asked
//  triggers the request and answers `permission_denied` with `recoverable`,
//  rather than blocking the agent's turn on a dialog (docs/host-bridge.md §2).
//

#import <Foundation/Foundation.h>
@class DSHHostBridge;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const DSHCapabilityCalendarRead;
extern NSString *const DSHCapabilityRemindersRead;

@interface DSHEventKitCapability : NSObject

/// Registers the capabilities and adds `/v1/calendar/events` and `/v1/reminders`.
+ (void)installOn:(DSHHostBridge *)bridge;

/// Events in the next `days` days (or the past when negative), newest first,
/// at most `limit`. Returns the route's JSON body.
+ (NSDictionary *)eventsWithinDays:(NSInteger)days limit:(NSInteger)limit;
/// Reminders, optionally including completed ones.
+ (NSDictionary *)remindersIncludingCompleted:(BOOL)includeCompleted limit:(NSInteger)limit;

@end

NS_ASSUME_NONNULL_END

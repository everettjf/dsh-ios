//
//  DSHEventKitCapability.m
//  DSH
//

#import "DSHEventKitCapability.h"
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHHarness.h"
#import <EventKit/EventKit.h>

NSString *const DSHCapabilityCalendarRead = @"calendar.read";
NSString *const DSHCapabilityRemindersRead = @"reminders.read";

/// Calendar data is easily thousands of items; every route caps what it returns
/// and says so, because the model pays for each one.
static const NSInteger kDefaultLimit = 50;
static const NSInteger kMaxLimit = 200;
static const NSInteger kMaxDays = 366;

@implementation DSHEventKitCapability

+ (EKEventStore *)store {
    static EKEventStore *store;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ store = [EKEventStore new]; });
    return store;
}

#pragma mark Authorization

+ (EKAuthorizationStatus)statusFor:(EKEntityType)type {
    return [EKEventStore authorizationStatusForEntityType:type];
}

/// Asks iOS for access without making the caller wait: the dialog needs the app
/// to be in the foreground and the user to answer, which can take longer than
/// an agent turn should hang.
+ (void)requestAccessFor:(EKEntityType)type {
    EKEventStore *store = [self store];
    void (^done)(BOOL, NSError *) = ^(BOOL granted, NSError *error) {
        [DSHHarness.shared.log append:[NSString stringWithFormat:@"[bridge] %@ access %@",
                                       type == EKEntityTypeEvent ? @"calendar" : @"reminders",
                                       granted ? @"granted" : @"denied"]];
    };
    dispatch_async(dispatch_get_main_queue(), ^{
        if (@available(iOS 17.0, *)) {
            if (type == EKEntityTypeEvent)
                [store requestFullAccessToEventsWithCompletion:done];
            else
                [store requestFullAccessToRemindersWithCompletion:done];
        } else {
            [store requestAccessToEntityType:type completion:done];
        }
    });
}

/// nil when the call may proceed; otherwise the response to send back.
+ (nullable DSHHostBridgeResponse *)refusalFor:(EKEntityType)type name:(NSString *)name {
    EKAuthorizationStatus status = [self statusFor:type];
    BOOL authorized = status == EKAuthorizationStatusAuthorized;
    if (@available(iOS 17.0, *))
        authorized = authorized || status == EKAuthorizationStatusFullAccess;
    if (authorized)
        return nil;

    if (status == EKAuthorizationStatusNotDetermined) {
        [self requestAccessFor:type];
        return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                              message:[NSString stringWithFormat:
                                                       @"iOS has just asked the user for %@ access. Tell them to allow it, then try again.", name]
                                          recoverable:YES];
    }
    if (@available(iOS 17.0, *)) {
        if (status == EKAuthorizationStatusWriteOnly)
            return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                                  message:[NSString stringWithFormat:
                                                           @"DSH only has write access to %@; reading needs full access in Settings ▸ Privacy.", name]
                                              recoverable:YES];
    }
    return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                          message:[NSString stringWithFormat:
                                                   @"%@ access is denied for DSH in iOS Settings ▸ Privacy; the user has to grant it there.", name]
                                      recoverable:YES];
}

#pragma mark Data

+ (NSString *)isoString:(NSDate *)date {
    static NSISO8601DateFormatter *formatter;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ formatter = [NSISO8601DateFormatter new]; });
    return date ? [formatter stringFromDate:date] : @"";
}

+ (NSDictionary *)eventsWithinDays:(NSInteger)days limit:(NSInteger)limit {
    days = MAX(-kMaxDays, MIN(kMaxDays, days == 0 ? 7 : days));
    limit = MAX(1, MIN(kMaxLimit, limit <= 0 ? kDefaultLimit : limit));
    NSDate *now = NSDate.date;
    NSDate *other = [now dateByAddingTimeInterval:days * 24 * 60 * 60];
    NSDate *start = days >= 0 ? now : other;
    NSDate *end = days >= 0 ? other : now;

    EKEventStore *store = [self store];
    NSPredicate *predicate = [store predicateForEventsWithStartDate:start endDate:end calendars:nil];
    NSArray<EKEvent *> *events = [[store eventsMatchingPredicate:predicate]
                                  sortedArrayUsingSelector:@selector(compareStartDateWithEvent:)];
    NSMutableArray *out = [NSMutableArray array];
    for (EKEvent *event in events) {
        if (out.count >= (NSUInteger) limit)
            break;
        NSMutableDictionary *item = [@{
            @"title": event.title ?: @"(no title)",
            @"start": [self isoString:event.startDate],
            @"end": [self isoString:event.endDate],
            @"allDay": @(event.isAllDay),
            @"calendar": event.calendar.title ?: @"",
        } mutableCopy];
        if (event.location.length) item[@"location"] = event.location;
        if (event.notes.length) item[@"notes"] = [event.notes substringToIndex:MIN(event.notes.length, 500u)];
        if (event.hasAttendees) item[@"attendeeCount"] = @(event.attendees.count);
        [out addObject:item];
    }
    return @{
        @"events": out,
        @"from": [self isoString:start],
        @"to": [self isoString:end],
        @"truncated": @(events.count > out.count),
    };
}

+ (NSDictionary *)remindersIncludingCompleted:(BOOL)includeCompleted limit:(NSInteger)limit {
    limit = MAX(1, MIN(kMaxLimit, limit <= 0 ? kDefaultLimit : limit));
    EKEventStore *store = [self store];
    NSPredicate *predicate = includeCompleted
        ? [store predicateForRemindersInCalendars:nil]
        : [store predicateForIncompleteRemindersWithDueDateStarting:nil ending:nil calendars:nil];

    // EventKit's reminder fetch is asynchronous; the bridge handler runs on a
    // background queue, so waiting here is fine and keeps the route simple.
    __block NSArray<EKReminder *> *fetched = @[];
    dispatch_semaphore_t done = dispatch_semaphore_create(0);
    [store fetchRemindersMatchingPredicate:predicate completion:^(NSArray<EKReminder *> *reminders) {
        fetched = reminders ?: @[];
        dispatch_semaphore_signal(done);
    }];
    if (dispatch_semaphore_wait(done, dispatch_time(DISPATCH_TIME_NOW, (int64_t) (10 * NSEC_PER_SEC))) != 0)
        return @{ @"reminders": @[], @"truncated": @NO, @"note": @"EventKit did not answer in time" };

    NSArray<EKReminder *> *sorted = [fetched sortedArrayUsingComparator:^NSComparisonResult(EKReminder *a, EKReminder *b) {
        NSDate *da = a.dueDateComponents ? [NSCalendar.currentCalendar dateFromComponents:a.dueDateComponents] : NSDate.distantFuture;
        NSDate *db = b.dueDateComponents ? [NSCalendar.currentCalendar dateFromComponents:b.dueDateComponents] : NSDate.distantFuture;
        return [da compare:db];
    }];
    NSMutableArray *out = [NSMutableArray array];
    for (EKReminder *reminder in sorted) {
        if (out.count >= (NSUInteger) limit)
            break;
        NSMutableDictionary *item = [@{
            @"title": reminder.title ?: @"(no title)",
            @"completed": @(reminder.completed),
            @"list": reminder.calendar.title ?: @"",
        } mutableCopy];
        if (reminder.dueDateComponents) {
            NSDate *due = [NSCalendar.currentCalendar dateFromComponents:reminder.dueDateComponents];
            if (due) item[@"due"] = [self isoString:due];
        }
        if (reminder.priority > 0) item[@"priority"] = @(reminder.priority);
        if (reminder.notes.length) item[@"notes"] = [reminder.notes substringToIndex:MIN(reminder.notes.length, 500u)];
        [out addObject:item];
    }
    return @{ @"reminders": out, @"truncated": @(sorted.count > out.count) };
}

#pragma mark Routes

+ (void)installOn:(DSHHostBridge *)bridge {
    DSHCapabilityRegistry *registry = DSHCapabilityRegistry.shared;
    [registry registerCapability:[[DSHCapability alloc] initWithIdentifier:DSHCapabilityCalendarRead
                                                                    title:@"Calendar (read)"
                                                                  details:@"Events from your calendars, so the agent can answer questions about your schedule."
                                                                     gate:DSHCapabilityGateSystemPermission
                                                         enabledByDefault:NO
                                                                available:YES]];
    [registry registerCapability:[[DSHCapability alloc] initWithIdentifier:DSHCapabilityRemindersRead
                                                                    title:@"Reminders (read)"
                                                                  details:@"Your reminders and their due dates."
                                                                     gate:DSHCapabilityGateSystemPermission
                                                         enabledByDefault:NO
                                                                available:YES]];

    [bridge registerRoute:@"GET" path:@"/v1/calendar/events" capability:DSHCapabilityCalendarRead
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        DSHHostBridgeResponse *refusal = [self refusalFor:EKEntityTypeEvent name:@"calendar"];
        if (refusal)
            return refusal;
        NSInteger days = [request integerFor:@"days" fallback:7 min:-kMaxDays max:kMaxDays];
        NSInteger limit = [request integerFor:@"limit" fallback:kDefaultLimit min:1 max:kMaxLimit];
        return [DSHHostBridgeResponse ok:[self eventsWithinDays:days limit:limit]];
    }];

    [bridge registerRoute:@"GET" path:@"/v1/reminders" capability:DSHCapabilityRemindersRead
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        DSHHostBridgeResponse *refusal = [self refusalFor:EKEntityTypeReminder name:@"reminders"];
        if (refusal)
            return refusal;
        BOOL includeCompleted = [request.query[@"completed"] isEqualToString:@"true"];
        NSInteger limit = [request integerFor:@"limit" fallback:kDefaultLimit min:1 max:kMaxLimit];
        return [DSHHostBridgeResponse ok:[self remindersIncludingCompleted:includeCompleted limit:limit]];
    }];
}

@end

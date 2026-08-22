//
//  DSHEventKitCapability.m
//  DSH
//

#import "DSHEventKitCapability.h"
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHHarness.h"
#import "DSHCallConfirmation.h"
#import <EventKit/EventKit.h>

NSString *const DSHCapabilityCalendarRead = @"calendar.read";
NSString *const DSHCapabilityRemindersRead = @"reminders.read";
NSString *const DSHCapabilityCalendarWrite = @"calendar.write";
NSString *const DSHCapabilityRemindersWrite = @"reminders.write";

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

/// Writing needs full access; `WriteOnly` is enough here, where it is not for
/// reading.
+ (nullable DSHHostBridgeResponse *)writeRefusalFor:(EKEntityType)type name:(NSString *)name {
    EKAuthorizationStatus status = [self statusFor:type];
    BOOL allowed = status == EKAuthorizationStatusAuthorized;
    if (@available(iOS 17.0, *))
        allowed = allowed || status == EKAuthorizationStatusFullAccess || status == EKAuthorizationStatusWriteOnly;
    if (allowed)
        return nil;
    if (status == EKAuthorizationStatusNotDetermined) {
        [self requestAccessFor:type];
        return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                              message:[NSString stringWithFormat:
                                                       @"iOS has just asked the user for %@ access. Tell them to allow it, then try again.", name]
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

+ (nullable NSDate *)dateFromString:(NSString *)string {
    if (![string isKindOfClass:NSString.class] || string.length == 0)
        return nil;
    static NSISO8601DateFormatter *iso;
    static NSDateFormatter *localMinutes, *localDay;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        iso = [NSISO8601DateFormatter new];
        // A model writing "2026-08-20 14:00" means the user's wall clock, so
        // these two parse in the device's own time zone rather than UTC.
        localMinutes = [NSDateFormatter new];
        localMinutes.dateFormat = @"yyyy-MM-dd HH:mm";
        localMinutes.locale = [NSLocale localeWithLocaleIdentifier:@"en_US_POSIX"];
        localDay = [NSDateFormatter new];
        localDay.dateFormat = @"yyyy-MM-dd";
        localDay.locale = [NSLocale localeWithLocaleIdentifier:@"en_US_POSIX"];
    });
    NSDate *date = [iso dateFromString:string];
    if (date == nil)
        date = [localMinutes dateFromString:string];
    if (date == nil)
        date = [localDay dateFromString:string];
    return date;
}

/// How the confirmation alert and the log line describe a moment.
+ (NSString *)humanDate:(NSDate *)date allDay:(BOOL)allDay {
    NSDateFormatter *formatter = [NSDateFormatter new];
    formatter.dateStyle = NSDateFormatterMediumStyle;
    formatter.timeStyle = allDay ? NSDateFormatterNoStyle : NSDateFormatterShortStyle;
    return [formatter stringFromDate:date];
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
    DSHCapability *calendar = [[DSHCapability alloc] initWithIdentifier:DSHCapabilityCalendarRead
                                                                  title:@"Calendar (read)"
                                                                details:@"Events from your calendars, so the agent can answer questions about your schedule."
                                                                   gate:DSHCapabilityGateSystemPermission
                                                       enabledByDefault:YES
                                                              available:YES];
    calendar.requestSystemPermission = ^{ [self requestAccessFor:EKEntityTypeEvent]; };
    [registry registerCapability:calendar];

    DSHCapability *reminders = [[DSHCapability alloc] initWithIdentifier:DSHCapabilityRemindersRead
                                                                  title:@"Reminders (read)"
                                                                details:@"Your reminders and their due dates."
                                                                   gate:DSHCapabilityGateSystemPermission
                                                       enabledByDefault:YES
                                                              available:YES];
    reminders.requestSystemPermission = ^{ [self requestAccessFor:EKEntityTypeReminder]; };
    [registry registerCapability:reminders];

    [bridge registerRoute:@"GET" path:@"/v1/calendar/events" capability:DSHCapabilityCalendarRead
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        DSHHostBridgeResponse *refusal = [self refusalFor:EKEntityTypeEvent name:@"calendar"];
        if (refusal)
            return refusal;
        NSInteger days = [request integerFor:@"days" fallback:7 min:-kMaxDays max:kMaxDays];
        NSInteger limit = [request integerFor:@"limit" fallback:kDefaultLimit min:1 max:kMaxLimit];
        return [DSHHostBridgeResponse ok:[self eventsWithinDays:days limit:limit]];
    }];

    DSHCapability *calendarWrite = [[DSHCapability alloc] initWithIdentifier:DSHCapabilityCalendarWrite
                                                                       title:@"Calendar (create)"
                                                                     details:@"Lets the agent add events to your calendar."
                                                                        gate:DSHCapabilityGatePerCall
                                                            enabledByDefault:YES
                                                                   available:YES];
    calendarWrite.requestSystemPermission = ^{ [self requestAccessFor:EKEntityTypeEvent]; };
    [registry registerCapability:calendarWrite];

    DSHCapability *remindersWrite = [[DSHCapability alloc] initWithIdentifier:DSHCapabilityRemindersWrite
                                                                       title:@"Reminders (create)"
                                                                     details:@"Lets the agent add reminders."
                                                                        gate:DSHCapabilityGatePerCall
                                                            enabledByDefault:YES
                                                                   available:YES];
    remindersWrite.requestSystemPermission = ^{ [self requestAccessFor:EKEntityTypeReminder]; };
    [registry registerCapability:remindersWrite];

    [bridge registerRoute:@"GET" path:@"/v1/reminders" capability:DSHCapabilityRemindersRead
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        DSHHostBridgeResponse *refusal = [self refusalFor:EKEntityTypeReminder name:@"reminders"];
        if (refusal)
            return refusal;
        BOOL includeCompleted = [request.query[@"completed"] isEqualToString:@"true"];
        NSInteger limit = [request integerFor:@"limit" fallback:kDefaultLimit min:1 max:kMaxLimit];
        return [DSHHostBridgeResponse ok:[self remindersIncludingCompleted:includeCompleted limit:limit]];
    }];

    [bridge registerRoute:@"POST" path:@"/v1/calendar/events" capability:DSHCapabilityCalendarWrite
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        NSString *title = request.json[@"title"];
        if (![title isKindOfClass:NSString.class] || title.length == 0)
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:@"Send a JSON body with at least `title` and `start`."
                                              recoverable:NO];
        NSDate *start = [self dateFromString:request.json[@"start"]];
        if (start == nil)
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:@"`start` must be ISO 8601, or \"YYYY-MM-DD HH:mm\" / \"YYYY-MM-DD\" in the device's time zone."
                                              recoverable:NO];
        BOOL allDay = [request.json[@"allDay"] boolValue];
        NSDate *end = [self dateFromString:request.json[@"end"]];
        if (end == nil)
            end = [start dateByAddingTimeInterval:allDay ? 24 * 60 * 60 : 60 * 60];
        if ([end compare:start] == NSOrderedAscending)
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:@"`end` is before `start`."
                                              recoverable:NO];

        DSHHostBridgeResponse *refusal = [self writeRefusalFor:EKEntityTypeEvent name:@"calendar"];
        if (refusal)
            return refusal;

        EKEventStore *store = [self store];
        EKCalendar *calendar = store.defaultCalendarForNewEvents;
        if (calendar == nil)
            return [DSHHostBridgeResponse errorWithStatus:409 code:@"unavailable"
                                                  message:@"There is no calendar on this device that DSH may write to."
                                              recoverable:NO];

        NSString *location = [request.json[@"location"] isKindOfClass:NSString.class] ? request.json[@"location"] : nil;
        NSMutableString *detail = [NSMutableString stringWithFormat:@"“%@”\n%@",
                                   DSHDisplayValue(title, 120), [self humanDate:start allDay:allDay]];
        if (!allDay) [detail appendFormat:@" – %@", [self humanDate:end allDay:NO]];
        if (location.length) [detail appendFormat:@"\n%@", DSHDisplayValue(location, 80)];
        [detail appendFormat:@"\n\nIn %@.", calendar.title];
        DSHConfirmationOutcome outcome = [DSHCallConfirmation confirmTitle:@"Add this to your calendar?" detail:detail
                                                                capability:DSHCapabilityCalendarWrite];
        DSHHostBridgeResponse *declined = [DSHCallConfirmation refusalFor:outcome
                                                                  action:[NSString stringWithFormat:@"adding “%@” to the calendar", DSHDisplayValue(title, 120)]];
        if (declined)
            return declined;

        EKEvent *event = [EKEvent eventWithEventStore:store];
        event.title = title;
        event.startDate = start;
        event.endDate = end;
        event.allDay = allDay;
        event.calendar = calendar;
        if (location.length) event.location = location;
        if ([request.json[@"notes"] isKindOfClass:NSString.class]) event.notes = request.json[@"notes"];

        NSError *error = nil;
        if (![store saveEvent:event span:EKSpanThisEvent commit:YES error:&error])
            return [DSHHostBridgeResponse errorWithStatus:500 code:@"internal"
                                                  message:[NSString stringWithFormat:@"EventKit refused to save the event: %@", error.localizedDescription]
                                              recoverable:NO];
        [DSHHarness.shared.log append:[NSString stringWithFormat:@"[bridge] created calendar event “%@”", title]];
        return [DSHHostBridgeResponse ok:@{
            @"created": @YES,
            @"title": title,
            @"start": [self isoString:start],
            @"end": [self isoString:end],
            @"allDay": @(allDay),
            @"calendar": calendar.title ?: @"",
        }];
    }];

    [bridge registerRoute:@"POST" path:@"/v1/reminders" capability:DSHCapabilityRemindersWrite
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        NSString *title = request.json[@"title"];
        if (![title isKindOfClass:NSString.class] || title.length == 0)
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:@"Send a JSON body with at least `title`."
                                              recoverable:NO];
        NSString *dueString = request.json[@"due"];
        NSDate *due = dueString ? [self dateFromString:dueString] : nil;
        if (dueString != nil && due == nil)
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:@"`due` must be ISO 8601, or \"YYYY-MM-DD HH:mm\" / \"YYYY-MM-DD\" in the device's time zone."
                                              recoverable:NO];

        DSHHostBridgeResponse *refusal = [self writeRefusalFor:EKEntityTypeReminder name:@"reminders"];
        if (refusal)
            return refusal;

        EKEventStore *store = [self store];
        EKCalendar *list = store.defaultCalendarForNewReminders;
        if (list == nil)
            return [DSHHostBridgeResponse errorWithStatus:409 code:@"unavailable"
                                                  message:@"There is no reminders list on this device that DSH may write to."
                                              recoverable:NO];

        NSMutableString *detail = [NSMutableString stringWithFormat:@"“%@”", DSHDisplayValue(title, 120)];
        if (due) [detail appendFormat:@"\ndue %@", [self humanDate:due allDay:NO]];
        [detail appendFormat:@"\n\nIn %@.", list.title];
        DSHConfirmationOutcome outcome = [DSHCallConfirmation confirmTitle:@"Add this reminder?" detail:detail
                                                                capability:DSHCapabilityRemindersWrite];
        DSHHostBridgeResponse *declined = [DSHCallConfirmation refusalFor:outcome
                                                                  action:[NSString stringWithFormat:@"adding the reminder “%@”", DSHDisplayValue(title, 120)]];
        if (declined)
            return declined;

        EKReminder *reminder = [EKReminder reminderWithEventStore:store];
        reminder.title = title;
        reminder.calendar = list;
        if ([request.json[@"notes"] isKindOfClass:NSString.class]) reminder.notes = request.json[@"notes"];
        if (due) {
            NSCalendarUnit units = NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay |
                                   NSCalendarUnitHour | NSCalendarUnitMinute;
            reminder.dueDateComponents = [NSCalendar.currentCalendar components:units fromDate:due];
            // A due date without an alarm is a date the user never sees, so
            // add the alarm that Reminders itself would.
            [reminder addAlarm:[EKAlarm alarmWithAbsoluteDate:due]];
        }

        NSError *error = nil;
        if (![store saveReminder:reminder commit:YES error:&error])
            return [DSHHostBridgeResponse errorWithStatus:500 code:@"internal"
                                                  message:[NSString stringWithFormat:@"EventKit refused to save the reminder: %@", error.localizedDescription]
                                              recoverable:NO];
        [DSHHarness.shared.log append:[NSString stringWithFormat:@"[bridge] created reminder “%@”", title]];
        NSMutableDictionary *body = [@{ @"created": @YES, @"title": title, @"list": list.title ?: @"" } mutableCopy];
        if (due) body[@"due"] = [self isoString:due];
        return [DSHHostBridgeResponse ok:body];
    }];
}

@end

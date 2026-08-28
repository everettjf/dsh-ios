//
//  DSHHealthCapability.m
//  DSH
//

#import "DSHHealthCapability.h"
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHHarness.h"

NSString *const DSHCapabilityHealthRead = @"health.read";

/// Health data is unbounded; every route caps its window and its rows.
static const NSInteger kDefaultDays = 7;
static const NSInteger kMaxDays = 366;
static const NSInteger kDefaultLimit = 50;
static const NSInteger kMaxLimit = 200;
/// HealthKit queries are asynchronous and the bridge handler is synchronous on
/// a background queue, so each query waits — bounded, so a wedged query answers
/// the agent instead of holding its turn open. The budget matters: the activity
/// route runs three queries back to back, and the guest plugin gives up on the
/// whole request after 20s, so the per-query bound has to leave all three
/// inside that. HealthKit normally answers in milliseconds.
static const int64_t kQueryTimeoutSeconds = 5;

@implementation DSHHealthCapability

+ (HKHealthStore *)store {
    static HKHealthStore *store;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ store = [HKHealthStore new]; });
    return store;
}

+ (NSSet<HKObjectType *> *)readTypes {
    NSMutableSet *types = [NSMutableSet set];
    for (HKQuantityTypeIdentifier identifier in @[HKQuantityTypeIdentifierStepCount,
                                                  HKQuantityTypeIdentifierDistanceWalkingRunning,
                                                  HKQuantityTypeIdentifierActiveEnergyBurned,
                                                  HKQuantityTypeIdentifierHeartRate,
                                                  HKQuantityTypeIdentifierRestingHeartRate]) {
        HKObjectType *type = [HKObjectType quantityTypeForIdentifier:identifier];
        if (type) [types addObject:type];
    }
    HKObjectType *sleep = [HKObjectType categoryTypeForIdentifier:HKCategoryTypeIdentifierSleepAnalysis];
    if (sleep) [types addObject:sleep];
    [types addObject:HKObjectType.workoutType];
    return types;
}

#pragma mark Authorization

/// iOS will not say whether *reading* was allowed, only whether the sheet still
/// has to be shown. `shouldRequest` is therefore the one actionable signal.
+ (nullable DSHHostBridgeResponse *)refusal {
    if (!HKHealthStore.isHealthDataAvailable)
        return [DSHHostBridgeResponse errorWithStatus:501 code:@"unavailable"
                                              message:@"HealthKit is not available on this device."
                                          recoverable:NO];

    __block HKAuthorizationRequestStatus status = HKAuthorizationRequestStatusUnknown;
    dispatch_semaphore_t done = dispatch_semaphore_create(0);
    [[self store] getRequestStatusForAuthorizationToShareTypes:[NSSet set]
                                                    readTypes:[self readTypes]
                                                   completion:^(HKAuthorizationRequestStatus s, NSError *error) {
        status = s;
        dispatch_semaphore_signal(done);
    }];
    if (dispatch_semaphore_wait(done, dispatch_time(DISPATCH_TIME_NOW, kQueryTimeoutSeconds * NSEC_PER_SEC)) != 0)
        return [DSHHostBridgeResponse errorWithStatus:504 code:@"timeout"
                                              message:@"HealthKit did not answer in time; try again."
                                          recoverable:YES];

    if (status == HKAuthorizationRequestStatusShouldRequest) {
        [self requestAuthorization];
        return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                              message:@"iOS has just asked the user for Health access. Tell them to allow the categories they are willing to share, then try again."
                                          recoverable:YES];
    }
    if (status == HKAuthorizationRequestStatusUnknown)
        return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                              message:@"HealthKit would not report its authorization state; the user may need to open Settings ▸ Privacy ▸ Health ▸ DSH."
                                          recoverable:YES];
    return nil;  // asked already: query, and let an empty result speak for itself
}

+ (void)requestAuthorization {
    dispatch_async(dispatch_get_main_queue(), ^{
        [[self store] requestAuthorizationToShareTypes:nil readTypes:[self readTypes]
                                            completion:^(BOOL success, NSError *error) {
            [DSHHarness.shared.log append:[NSString stringWithFormat:@"[bridge] health authorization sheet %@",
                                           success ? @"completed" : @"failed"]];
        }];
    });
}

/// Appended whenever a route returns nothing: iOS gives us no way to tell "no
/// data" from "read access declined", and the model has to know that.
+ (NSString *)emptyNote {
    return @"No samples in this window. iOS does not let an app see whether read access was declined, "
           @"so this may also mean the user did not share this category — ask them to check Settings ▸ Privacy ▸ Health ▸ DSH.";
}

#pragma mark Windows and formatting

+ (NSInteger)clampDays:(NSInteger)days {
    if (days <= 0) days = kDefaultDays;
    return MIN(days, kMaxDays);
}

/// Health is history: the window is always [start of (today - days + 1), now].
+ (NSDate *)startForDays:(NSInteger)days {
    NSCalendar *calendar = NSCalendar.currentCalendar;
    NSDate *today = [calendar startOfDayForDate:NSDate.date];
    return [calendar dateByAddingUnit:NSCalendarUnitDay value:-(days - 1) toDate:today options:0];
}

+ (NSString *)isoString:(NSDate *)date {
    static NSISO8601DateFormatter *formatter;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ formatter = [NSISO8601DateFormatter new]; });
    return date ? [formatter stringFromDate:date] : @"";
}

/// Calendar day as YYYY-MM-DD, which is what the model wants to reason about.
+ (NSString *)dayString:(NSDate *)date {
    static NSDateFormatter *formatter;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        formatter = [NSDateFormatter new];
        formatter.dateFormat = @"yyyy-MM-dd";
        formatter.locale = [NSLocale localeWithLocaleIdentifier:@"en_US_POSIX"];
    });
    return [formatter stringFromDate:date];
}

+ (NSNumber *)rounded:(double)value places:(int)places {
    double factor = pow(10, places);
    return @(round(value * factor) / factor);
}

#pragma mark Queries

/// One statistics-per-day pass over a quantity type. Returns nil on timeout.
+ (nullable HKStatisticsCollection *)dailyStatisticsFor:(HKQuantityTypeIdentifier)identifier
                                                options:(HKStatisticsOptions)options
                                                   days:(NSInteger)days {
    HKQuantityType *type = [HKQuantityType quantityTypeForIdentifier:identifier];
    if (type == nil)
        return nil;
    NSDate *start = [self startForDays:days];
    NSPredicate *predicate = [HKQuery predicateForSamplesWithStartDate:start endDate:NSDate.date
                                                               options:HKQueryOptionStrictStartDate];
    NSDateComponents *interval = [NSDateComponents new];
    interval.day = 1;

    __block HKStatisticsCollection *collection = nil;
    dispatch_semaphore_t done = dispatch_semaphore_create(0);
    HKStatisticsCollectionQuery *query =
        [[HKStatisticsCollectionQuery alloc] initWithQuantityType:type
                                          quantitySamplePredicate:predicate
                                                          options:options
                                                       anchorDate:start
                                               intervalComponents:interval];
    query.initialResultsHandler = ^(HKStatisticsCollectionQuery *q, HKStatisticsCollection *result, NSError *error) {
        collection = result;
        dispatch_semaphore_signal(done);
    };
    [[self store] executeQuery:query];
    if (dispatch_semaphore_wait(done, dispatch_time(DISPATCH_TIME_NOW, kQueryTimeoutSeconds * NSEC_PER_SEC)) != 0) {
        [[self store] stopQuery:query];
        return nil;
    }
    return collection;
}

+ (nullable NSArray<__kindof HKSample *> *)samplesOfType:(HKSampleType *)type
                                                    days:(NSInteger)days
                                                   limit:(NSInteger)limit
                                               descending:(BOOL)descending {
    NSDate *start = [self startForDays:days];
    NSPredicate *predicate = [HKQuery predicateForSamplesWithStartDate:start endDate:NSDate.date options:0];
    NSSortDescriptor *sort = [NSSortDescriptor sortDescriptorWithKey:HKSampleSortIdentifierStartDate
                                                           ascending:!descending];
    __block NSArray *samples = nil;
    dispatch_semaphore_t done = dispatch_semaphore_create(0);
    HKSampleQuery *query = [[HKSampleQuery alloc] initWithSampleType:type predicate:predicate
                                                               limit:(NSUInteger) limit
                                                     sortDescriptors:@[sort]
                                                      resultsHandler:^(HKSampleQuery *q, NSArray<__kindof HKSample *> *results, NSError *error) {
        samples = results;
        dispatch_semaphore_signal(done);
    }];
    [[self store] executeQuery:query];
    if (dispatch_semaphore_wait(done, dispatch_time(DISPATCH_TIME_NOW, kQueryTimeoutSeconds * NSEC_PER_SEC)) != 0) {
        [[self store] stopQuery:query];
        return nil;
    }
    return samples ?: @[];
}

#pragma mark Routes: activity

+ (NSDictionary *)activityForDays:(NSInteger)days {
    days = [self clampDays:days];
    NSDate *start = [self startForDays:days];

    // These independent HealthKit reads used to run serially. On a waking or
    // busy device that could consume 15 seconds of the guest's 20-second
    // bridge budget. Run them together; the same per-query bound still applies.
    __block HKStatisticsCollection *steps;
    __block HKStatisticsCollection *distance;
    __block HKStatisticsCollection *energy;
    dispatch_group_t group = dispatch_group_create();
    dispatch_queue_t queue = dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0);
    dispatch_group_async(group, queue, ^{
        steps = [self dailyStatisticsFor:HKQuantityTypeIdentifierStepCount
                                 options:HKStatisticsOptionCumulativeSum days:days];
    });
    dispatch_group_async(group, queue, ^{
        distance = [self dailyStatisticsFor:HKQuantityTypeIdentifierDistanceWalkingRunning
                                    options:HKStatisticsOptionCumulativeSum days:days];
    });
    dispatch_group_async(group, queue, ^{
        energy = [self dailyStatisticsFor:HKQuantityTypeIdentifierActiveEnergyBurned
                                  options:HKStatisticsOptionCumulativeSum days:days];
    });
    dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
    if (steps == nil)
        return @{ @"metric": @"activity", @"days": @[], @"note": @"HealthKit did not answer in time." };

    NSMutableArray *rows = [NSMutableArray array];
    __block double totalSteps = 0;
    __block BOOL sawAnything = NO;
    NSDate *end = NSDate.date;
    [steps enumerateStatisticsFromDate:start toDate:end withBlock:^(HKStatistics *statistics, BOOL *stop) {
        NSDate *day = statistics.startDate;
        double stepCount = statistics.sumQuantity ? [statistics.sumQuantity doubleValueForUnit:HKUnit.countUnit] : 0;
        totalSteps += stepCount;
        NSMutableDictionary *row = [@{ @"date": [self dayString:day], @"steps": @((NSInteger) stepCount) } mutableCopy];

        HKQuantity *distanceDay = [distance statisticsForDate:day].sumQuantity;
        double km = distanceDay ? [distanceDay doubleValueForUnit:[HKUnit meterUnitWithMetricPrefix:HKMetricPrefixKilo]] : 0;
        if (km > 0) row[@"distanceKm"] = [self rounded:km places:2];

        HKQuantity *energyDay = [energy statisticsForDate:day].sumQuantity;
        double kcal = energyDay ? [energyDay doubleValueForUnit:HKUnit.kilocalorieUnit] : 0;
        if (kcal > 0) row[@"activeEnergyKcal"] = @((NSInteger) round(kcal));

        sawAnything = sawAnything || stepCount > 0 || km > 0 || kcal > 0;
        [rows addObject:row];
    }];

    NSMutableDictionary *body = [@{
        @"metric": @"activity",
        @"from": [self isoString:start],
        @"to": [self isoString:end],
        @"totalSteps": @((NSInteger) totalSteps),
        @"days": rows,
    } mutableCopy];
    // Steps may legitimately be zero while distance or energy are not, so the
    // note keys off "nothing at all", not off steps.
    if (!sawAnything)
        body[@"note"] = [self emptyNote];
    return body;
}

#pragma mark Routes: heart rate

+ (NSDictionary *)heartRateForDays:(NSInteger)days {
    days = [self clampDays:days];
    NSDate *start = [self startForDays:days];
    NSDate *end = NSDate.date;
    HKUnit *bpm = [HKUnit.countUnit unitDividedByUnit:HKUnit.minuteUnit];

    __block HKStatisticsCollection *heart;
    __block HKStatisticsCollection *resting;
    dispatch_group_t group = dispatch_group_create();
    dispatch_queue_t queue = dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0);
    dispatch_group_async(group, queue, ^{
        heart = [self dailyStatisticsFor:HKQuantityTypeIdentifierHeartRate
                                 options:HKStatisticsOptionDiscreteAverage | HKStatisticsOptionDiscreteMin | HKStatisticsOptionDiscreteMax
                                    days:days];
    });
    dispatch_group_async(group, queue, ^{
        resting = [self dailyStatisticsFor:HKQuantityTypeIdentifierRestingHeartRate
                                   options:HKStatisticsOptionDiscreteAverage days:days];
    });
    dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
    if (heart == nil)
        return @{ @"metric": @"heart_rate", @"days": @[], @"note": @"HealthKit did not answer in time." };

    NSMutableArray *rows = [NSMutableArray array];
    [heart enumerateStatisticsFromDate:start toDate:end withBlock:^(HKStatistics *statistics, BOOL *stop) {
        NSDate *day = statistics.startDate;
        double avg = statistics.averageQuantity ? [statistics.averageQuantity doubleValueForUnit:bpm] : 0;
        double minimum = statistics.minimumQuantity ? [statistics.minimumQuantity doubleValueForUnit:bpm] : 0;
        double maximum = statistics.maximumQuantity ? [statistics.maximumQuantity doubleValueForUnit:bpm] : 0;
        HKQuantity *restingDay = [resting statisticsForDate:day].averageQuantity;
        if (avg == 0 && minimum == 0 && maximum == 0 && restingDay == nil)
            return;  // nothing recorded that day: leave the gap visible rather than reporting a zero heart rate
        NSMutableDictionary *row = [@{ @"date": [self dayString:day] } mutableCopy];
        if (avg > 0) row[@"averageBpm"] = @((NSInteger) round(avg));
        if (minimum > 0) row[@"minBpm"] = @((NSInteger) round(minimum));
        if (maximum > 0) row[@"maxBpm"] = @((NSInteger) round(maximum));
        if (restingDay)
            row[@"restingBpm"] = @((NSInteger) round([restingDay doubleValueForUnit:bpm]));
        [rows addObject:row];
    }];

    NSMutableDictionary *body = [@{
        @"metric": @"heart_rate",
        @"unit": @"count/min",
        @"from": [self isoString:start],
        @"to": [self isoString:end],
        @"days": rows,
    } mutableCopy];
    if (rows.count == 0)
        body[@"note"] = [self emptyNote];
    return body;
}

#pragma mark Routes: sleep

/// Asleep in any stage; `inBed` and `awake` are counted separately so a night
/// spent awake in bed does not read as sleep.
+ (BOOL)value:(NSInteger)value meansAsleepIn:(BOOL *)isInBed awake:(BOOL *)isAwake {
    *isInBed = value == HKCategoryValueSleepAnalysisInBed;
    *isAwake = value == HKCategoryValueSleepAnalysisAwake;
    return value == HKCategoryValueSleepAnalysisAsleepUnspecified
        || value == HKCategoryValueSleepAnalysisAsleepCore
        || value == HKCategoryValueSleepAnalysisAsleepDeep
        || value == HKCategoryValueSleepAnalysisAsleepREM;
}

+ (NSDictionary *)sleepSummaryFromSamples:(NSArray<HKCategorySample *> *)samples {
    NSMutableDictionary<NSString *, NSMutableDictionary *> *byNight = [NSMutableDictionary dictionary];
    for (HKCategorySample *sample in samples) {
        // A stretch that starts at 23:40 and ends at 07:00 belongs to the
        // waking day, which is how people talk about "last night".
        NSString *night = [self dayString:sample.endDate];
        NSMutableDictionary *entry = byNight[night];
        if (entry == nil) {
            entry = [@{ @"date": night, @"asleepMinutes": @0, @"inBedMinutes": @0, @"awakeMinutes": @0,
                        @"_start": sample.startDate, @"_end": sample.endDate } mutableCopy];
            byNight[night] = entry;
        }
        double minutes = [sample.endDate timeIntervalSinceDate:sample.startDate] / 60.0;
        BOOL inBed = NO, awake = NO;
        BOOL asleep = [self value:sample.value meansAsleepIn:&inBed awake:&awake];
        NSString *key = asleep ? @"asleepMinutes" : (inBed ? @"inBedMinutes" : (awake ? @"awakeMinutes" : nil));
        if (key)
            entry[key] = @([entry[key] doubleValue] + minutes);
        if ([sample.startDate compare:entry[@"_start"]] == NSOrderedAscending)
            entry[@"_start"] = sample.startDate;
        if ([sample.endDate compare:entry[@"_end"]] == NSOrderedDescending)
            entry[@"_end"] = sample.endDate;
    }

    NSArray *nights = [[byNight allValues] sortedArrayUsingComparator:^NSComparisonResult(NSDictionary *a, NSDictionary *b) {
        return [a[@"date"] compare:b[@"date"]];
    }];
    NSMutableArray *out = [NSMutableArray array];
    for (NSMutableDictionary *night in nights) {
        [out addObject:@{
            @"date": night[@"date"],
            @"asleepMinutes": @((NSInteger) round([night[@"asleepMinutes"] doubleValue])),
            @"inBedMinutes": @((NSInteger) round([night[@"inBedMinutes"] doubleValue])),
            @"awakeMinutes": @((NSInteger) round([night[@"awakeMinutes"] doubleValue])),
            @"start": [self isoString:night[@"_start"]],
            @"end": [self isoString:night[@"_end"]],
        }];
    }
    return @{ @"metric": @"sleep", @"nights": out };
}

+ (NSDictionary *)sleepForDays:(NSInteger)days {
    days = [self clampDays:days];
    HKCategoryType *type = [HKCategoryType categoryTypeForIdentifier:HKCategoryTypeIdentifierSleepAnalysis];
    // A night is many samples (stages); allow generously more rows than nights.
    NSArray *samples = type ? [self samplesOfType:type days:days limit:kMaxLimit * 20 descending:NO] : @[];
    if (samples == nil)
        return @{ @"metric": @"sleep", @"nights": @[], @"note": @"HealthKit did not answer in time." };

    NSMutableDictionary *body = [[self sleepSummaryFromSamples:samples] mutableCopy];
    body[@"from"] = [self isoString:[self startForDays:days]];
    body[@"to"] = [self isoString:NSDate.date];
    if ([body[@"nights"] count] == 0)
        body[@"note"] = [self emptyNote];
    return body;
}

#pragma mark Routes: workouts

+ (NSString *)activityNameFor:(HKWorkoutActivityType)type {
    static NSDictionary<NSNumber *, NSString *> *names;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        names = @{
            @(HKWorkoutActivityTypeWalking): @"Walking",
            @(HKWorkoutActivityTypeRunning): @"Running",
            @(HKWorkoutActivityTypeCycling): @"Cycling",
            @(HKWorkoutActivityTypeSwimming): @"Swimming",
            @(HKWorkoutActivityTypeHiking): @"Hiking",
            @(HKWorkoutActivityTypeYoga): @"Yoga",
            @(HKWorkoutActivityTypeTraditionalStrengthTraining): @"Strength training",
            @(HKWorkoutActivityTypeFunctionalStrengthTraining): @"Functional strength training",
            @(HKWorkoutActivityTypeHighIntensityIntervalTraining): @"HIIT",
            @(HKWorkoutActivityTypeElliptical): @"Elliptical",
            @(HKWorkoutActivityTypeRowing): @"Rowing",
            @(HKWorkoutActivityTypeStairClimbing): @"Stair climbing",
            @(HKWorkoutActivityTypeCoreTraining): @"Core training",
            @(HKWorkoutActivityTypeCardioDance): @"Dance",
            @(HKWorkoutActivityTypeMindAndBody): @"Mind and body",
            @(HKWorkoutActivityTypeTennis): @"Tennis",
            @(HKWorkoutActivityTypeBasketball): @"Basketball",
            @(HKWorkoutActivityTypeSoccer): @"Soccer",
            @(HKWorkoutActivityTypeBadminton): @"Badminton",
            @(HKWorkoutActivityTypeTableTennis): @"Table tennis",
            @(HKWorkoutActivityTypeGolf): @"Golf",
            @(HKWorkoutActivityTypeSkatingSports): @"Skating",
            @(HKWorkoutActivityTypeSnowSports): @"Snow sports",
            @(HKWorkoutActivityTypeMartialArts): @"Martial arts",
            @(HKWorkoutActivityTypeClimbing): @"Climbing",
            @(HKWorkoutActivityTypeOther): @"Other",
        };
    });
    return names[@(type)] ?: [NSString stringWithFormat:@"Activity %lu", (unsigned long) type];
}

+ (NSDictionary *)workoutsForDays:(NSInteger)days limit:(NSInteger)limit {
    days = [self clampDays:days == 0 ? 30 : days];
    limit = MAX(1, MIN(kMaxLimit, limit <= 0 ? kDefaultLimit : limit));
    NSArray<HKWorkout *> *workouts = [self samplesOfType:HKObjectType.workoutType days:days
                                                   limit:limit + 1 descending:YES];
    if (workouts == nil)
        return @{ @"metric": @"workouts", @"workouts": @[], @"truncated": @NO, @"note": @"HealthKit did not answer in time." };

    NSMutableArray *rows = [NSMutableArray array];
    for (HKWorkout *workout in workouts) {
        if (rows.count >= (NSUInteger) limit)
            break;
        NSMutableDictionary *row = [@{
            @"type": [self activityNameFor:workout.workoutActivityType],
            @"start": [self isoString:workout.startDate],
            @"end": [self isoString:workout.endDate],
            @"durationMinutes": @((NSInteger) round(workout.duration / 60.0)),
        } mutableCopy];
        HKQuantity *energy = [workout statisticsForType:[HKQuantityType quantityTypeForIdentifier:HKQuantityTypeIdentifierActiveEnergyBurned]].sumQuantity;
        if (energy)
            row[@"activeEnergyKcal"] = @((NSInteger) round([energy doubleValueForUnit:HKUnit.kilocalorieUnit]));
        HKQuantity *distance = [workout statisticsForType:[HKQuantityType quantityTypeForIdentifier:HKQuantityTypeIdentifierDistanceWalkingRunning]].sumQuantity;
        if (distance)
            row[@"distanceKm"] = [self rounded:[distance doubleValueForUnit:[HKUnit meterUnitWithMetricPrefix:HKMetricPrefixKilo]] places:2];
        if (workout.sourceRevision.source.name.length)
            row[@"source"] = workout.sourceRevision.source.name;
        [rows addObject:row];
    }

    NSMutableDictionary *body = [@{
        @"metric": @"workouts",
        @"from": [self isoString:[self startForDays:days]],
        @"to": [self isoString:NSDate.date],
        @"workouts": rows,
        // A boxed comparison is otherwise NSNumber(int), emitted as JSON 0/1
        // instead of the boolean required by the tool output schema.
        @"truncated": @((BOOL) (workouts.count > rows.count)),
    } mutableCopy];
    if (rows.count == 0)
        body[@"note"] = [self emptyNote];
    return body;
}

#pragma mark Install

+ (void)installOn:(DSHHostBridge *)bridge {
    DSHCapability *health = [[DSHCapability alloc] initWithIdentifier:DSHCapabilityHealthRead
                                                                title:@"Apple Health (read)"
                                                              details:@"Steps, distance, energy, heart rate, sleep and workouts from Health."
                                                                 gate:DSHCapabilityGateSystemPermission
                                                     enabledByDefault:YES
                                                            available:HKHealthStore.isHealthDataAvailable];
    health.requestSystemPermission = ^{ [self requestAuthorization]; };
    [DSHCapabilityRegistry.shared registerCapability:health];

    DSHHostBridgeHandler (^guarded)(DSHHostBridgeResponse *(^)(DSHHostBridgeRequest *)) =
        ^DSHHostBridgeHandler (DSHHostBridgeResponse *(^body)(DSHHostBridgeRequest *)) {
        return ^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
            DSHHostBridgeResponse *refusal = [self refusal];
            return refusal ?: body(request);
        };
    };

    [bridge registerRoute:@"GET" path:@"/v1/health/activity" capability:DSHCapabilityHealthRead
                  handler:guarded(^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        return [DSHHostBridgeResponse ok:[self activityForDays:[request integerFor:@"days" fallback:kDefaultDays min:1 max:kMaxDays]]];
    })];

    [bridge registerRoute:@"GET" path:@"/v1/health/heart_rate" capability:DSHCapabilityHealthRead
                  handler:guarded(^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        return [DSHHostBridgeResponse ok:[self heartRateForDays:[request integerFor:@"days" fallback:kDefaultDays min:1 max:kMaxDays]]];
    })];

    [bridge registerRoute:@"GET" path:@"/v1/health/sleep" capability:DSHCapabilityHealthRead
                  handler:guarded(^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        return [DSHHostBridgeResponse ok:[self sleepForDays:[request integerFor:@"days" fallback:kDefaultDays min:1 max:kMaxDays]]];
    })];

    [bridge registerRoute:@"GET" path:@"/v1/health/workouts" capability:DSHCapabilityHealthRead
                  handler:guarded(^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        return [DSHHostBridgeResponse ok:[self workoutsForDays:[request integerFor:@"days" fallback:30 min:1 max:kMaxDays]
                                                         limit:[request integerFor:@"limit" fallback:kDefaultLimit min:1 max:kMaxLimit]]];
    })];
}

@end

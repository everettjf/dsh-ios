//
//  DSHHealthCapabilityTests.m
//  DSHTests
//
//  Apple Health routes. Like the EventKit suite, this must pass on a device
//  with no health data and no granted permission, so it asserts the contract
//  rather than the contents: off by default, refused before HealthKit is
//  touched, never a hang, and — the part specific to Health — an empty answer
//  always carries the note explaining that iOS hides read denials.
//
//  The night-building logic is pure, so it is tested against injected samples
//  instead of whatever the tester slept last night.
//

#import <XCTest/XCTest.h>
#import <HealthKit/HealthKit.h>
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHHealthCapability.h"

static NSString *const kHealthRead = @"health.read";

@interface DSHHealthCapabilityTests : XCTestCase
@property (nonatomic) DSHHostBridge *bridge;
@end

@implementation DSHHealthCapabilityTests

- (void)setUp {
    [super setUp];
    self.bridge = [DSHHostBridge new];
    XCTAssertTrue([self.bridge start]);
    [DSHHealthCapability installOn:self.bridge];
    // Capabilities ship on now; these suites assert what happens when one is off,
    // with device.info left on as the route that is expected to work.
    [DSHCapabilityRegistry.shared disableAllForTesting];
    [DSHCapabilityRegistry.shared setEnabled:YES forIdentifier:@"device.info"];
    // The switch is persisted in NSUserDefaults and this bundle runs inside the
    // real app, so a previous run (or a curious tester) could have left it on.
    // Start from the shipped state; that the *shipped* state is off is asserted
    // through `enabledByDefault` below.
    [DSHCapabilityRegistry.shared setEnabled:NO forIdentifier:kHealthRead];
}

- (void)tearDown {
    [self.bridge stop];
    [DSHCapabilityRegistry.shared setEnabled:NO forIdentifier:kHealthRead];
    [super tearDown];
}

- (NSDictionary *)get:(NSString *)path status:(NSInteger *)statusOut {
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:
                                    [NSURL URLWithString:[self.bridge.baseURLString stringByAppendingString:path]]];
    [request setValue:[@"Bearer " stringByAppendingString:self.bridge.token] forHTTPHeaderField:@"Authorization"];
    request.timeoutInterval = 45;
    __block NSDictionary *json = nil;
    __block NSInteger status = 0;
    XCTestExpectation *done = [self expectationWithDescription:path];
    [[NSURLSession.sharedSession dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        status = ((NSHTTPURLResponse *) response).statusCode;
        if (data.length)
            json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
        [done fulfill];
    }] resume];
    [self waitForExpectations:@[done] timeout:60];
    if (statusOut) *statusOut = status;
    return json;
}

#pragma mark Gating

- (void)testHealthShipsOnButTheSwitchStillGates {
    DSHCapabilityRegistry *registry = DSHCapabilityRegistry.shared;
    XCTAssertTrue([registry capabilityWithIdentifier:kHealthRead].enabledByDefault,
                  @"health ships on; HealthKit's own dialog is the gate that matters");
    XCTAssertFalse([registry isEnabled:kHealthRead], @"setUp switched everything off");
    DSHCapabilityState state = [registry stateForIdentifier:kHealthRead];
    // Unavailable on a build or device without HealthKit; Disabled otherwise.
    XCTAssertTrue(state == DSHCapabilityStateDisabled || state == DSHCapabilityStateUnavailable,
                  @"unexpected state %ld", (long) state);
}

/// Prints the two facts that decide whether anything Health-related can happen
/// at all. Without them a green run is ambiguous: the data tests skip
/// themselves when HealthKit is unavailable, so "all passed" can mean "nothing
/// was exercised". This is a report, not a gate — it asserts nothing about the
/// tester's own privacy choices.
- (void)testReportHealthAuthorizationState {
    BOOL available = HKHealthStore.isHealthDataAvailable;
    NSLog(@"[dsh-test] HealthKit available on this device: %@", available ? @"YES" : @"NO");
    if (!available)
        return;

    HKHealthStore *store = [HKHealthStore new];
    __block HKAuthorizationRequestStatus status = HKAuthorizationRequestStatusUnknown;
    __block NSError *failure = nil;
    XCTestExpectation *done = [self expectationWithDescription:@"request status"];
    [store getRequestStatusForAuthorizationToShareTypes:[NSSet set]
                                              readTypes:[DSHHealthCapability readTypes]
                                             completion:^(HKAuthorizationRequestStatus s, NSError *error) {
        status = s;
        failure = error;
        [done fulfill];
    }];
    [self waitForExpectations:@[done] timeout:20];
    NSString *name = status == HKAuthorizationRequestStatusShouldRequest ? @"shouldRequest (iOS has never asked)"
                   : status == HKAuthorizationRequestStatusUnnecessary ? @"unnecessary (already asked)"
                   : @"unknown";
    NSLog(@"[dsh-test] HealthKit request status: %@%@", name, failure ? [@" error: " stringByAppendingString:failure.description] : @"");
    if (status != HKAuthorizationRequestStatusUnnecessary)
        return;  // nothing has been granted yet, so the queries would only report the note

    // Shapes only — row counts and whether the "iOS hides read denials" note
    // fired. The values themselves are the tester's health data and have no
    // business in a build log.
    [DSHCapabilityRegistry.shared setEnabled:YES forIdentifier:kHealthRead];
    NSDictionary *shape = @{
        @"/v1/health/activity?days=7": @"days",
        @"/v1/health/heart_rate?days=7": @"days",
        @"/v1/health/sleep?days=7": @"nights",
        @"/v1/health/workouts?days=30": @"workouts",
    };
    for (NSString *path in shape) {
        NSInteger routeStatus = 0;
        NSDictionary *json = [self get:path status:&routeStatus];
        NSString *key = shape[path];
        NSLog(@"[dsh-test] %@ → %ld, %lu %@%@", path, (long) routeStatus,
              (unsigned long) [json[key] count], key,
              json[@"note"] ? @", note present (no data, or the category was declined)" : @"");
    }
}

- (void)testAvailabilityFollowsHealthKit {
    DSHCapability *capability = [DSHCapabilityRegistry.shared capabilityWithIdentifier:kHealthRead];
    XCTAssertNotNil(capability);
    XCTAssertEqual(capability.available, HKHealthStore.isHealthDataAvailable);
    XCTAssertEqual(capability.gate, DSHCapabilityGateSystemPermission);
    XCTAssertTrue(capability.enabledByDefault);
}

- (void)testEveryHealthRouteIsRefusedWhileTheCapabilityIsOff {
    for (NSString *path in @[@"/v1/health/activity", @"/v1/health/heart_rate",
                             @"/v1/health/sleep", @"/v1/health/workouts"]) {
        NSInteger status = 0;
        NSDictionary *json = [self get:path status:&status];
        XCTAssertTrue(status == 403 || status == 501, @"%@ gave %ld", path, (long) status);
        XCTAssertNotNil(json[@"error"][@"code"], @"%@ must answer with an error envelope", path);
    }
}

#pragma mark Routes

/// Enabled, the answer depends on what the user shared. Either shape is fine;
/// what must not happen is a hang, a crash, or an empty answer with no note.
- (void)testEnabledRoutesAnswerOrRefuseRecoverably {
    if (!HKHealthStore.isHealthDataAvailable)
        return;  // simulator without Health, or an unsupported device
    [DSHCapabilityRegistry.shared setEnabled:YES forIdentifier:kHealthRead];

    NSDictionary *expectedKey = @{
        @"/v1/health/activity?days=3": @"days",
        @"/v1/health/heart_rate?days=3": @"days",
        @"/v1/health/sleep?days=3": @"nights",
        @"/v1/health/workouts?days=3&limit=5": @"workouts",
    };
    for (NSString *path in expectedKey) {
        NSInteger status = 0;
        NSDictionary *json = [self get:path status:&status];
        if (status != 200) {
            XCTAssertEqual(status, 403, @"%@ gave %ld", path, (long) status);
            XCTAssertEqualObjects(json[@"error"][@"code"], @"permission_denied");
            XCTAssertEqualObjects(json[@"error"][@"recoverable"], @YES);
            continue;
        }
        NSString *key = expectedKey[path];
        XCTAssertNotNil(json[key], @"%@ should carry %@", path, key);
        XCTAssertNotNil(json[@"metric"]);
        if ([json[key] count] == 0)
            XCTAssertNotNil(json[@"note"],
                            @"%@ came back empty and must explain that iOS hides read denials", path);
    }
}

- (void)testWorkoutLimitIsCappedServerSide {
    if (!HKHealthStore.isHealthDataAvailable)
        return;
    [DSHCapabilityRegistry.shared setEnabled:YES forIdentifier:kHealthRead];
    NSInteger status = 0;
    NSDictionary *json = [self get:@"/v1/health/workouts?days=99999&limit=99999" status:&status];
    XCTAssertTrue(status == 200 || status == 403, @"unexpected status %ld", (long) status);
    if (status == 200)
        XCTAssertLessThanOrEqual([json[@"workouts"] count], 200u);
}

#pragma mark Sleep aggregation (pure)

/// Dates are given in *local* time ("2026-03-01 23:00"), because nights are
/// bucketed by local calendar day — which is what a user means by "last
/// night", and what keeps this test passing in any time zone.
- (HKCategorySample *)sleepSample:(NSInteger)value from:(NSString *)start to:(NSString *)end {
    static NSDateFormatter *formatter;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        formatter = [NSDateFormatter new];
        formatter.dateFormat = @"yyyy-MM-dd HH:mm";
        formatter.locale = [NSLocale localeWithLocaleIdentifier:@"en_US_POSIX"];
    });
    HKCategoryType *type = [HKCategoryType categoryTypeForIdentifier:HKCategoryTypeIdentifierSleepAnalysis];
    NSDate *from = [formatter dateFromString:start], *to = [formatter dateFromString:end];
    XCTAssertNotNil(from, @"could not parse %@", start);
    XCTAssertNotNil(to, @"could not parse %@", end);
    return [HKCategorySample categorySampleWithType:type value:value startDate:from endDate:to];
}

/// A night that starts before midnight and ends after it is one night, counted
/// on the day the user woke up — the way people talk about "last night".
- (void)testSleepAcrossMidnightIsOneNightOnTheWakingDay {
    NSArray *samples = @[
        [self sleepSample:HKCategoryValueSleepAnalysisInBed from:@"2026-03-01 23:00" to:@"2026-03-02 07:30"],
        [self sleepSample:HKCategoryValueSleepAnalysisAsleepCore from:@"2026-03-01 23:20" to:@"2026-03-02 02:00"],
        [self sleepSample:HKCategoryValueSleepAnalysisAsleepDeep from:@"2026-03-02 02:00" to:@"2026-03-02 03:00"],
        [self sleepSample:HKCategoryValueSleepAnalysisAwake from:@"2026-03-02 03:00" to:@"2026-03-02 03:15"],
        [self sleepSample:HKCategoryValueSleepAnalysisAsleepREM from:@"2026-03-02 03:15" to:@"2026-03-02 07:00"],
    ];
    NSArray *nights = [DSHHealthCapability sleepSummaryFromSamples:samples][@"nights"];
    XCTAssertEqual(nights.count, 1u, @"stages of one night must not become several nights");

    NSDictionary *night = nights.firstObject;
    // 160 core + 60 deep + 225 REM = 445 minutes asleep; awake and in-bed are
    // tracked apart so time awake in bed is not counted as sleep.
    XCTAssertEqualObjects(night[@"asleepMinutes"], @445);
    XCTAssertEqualObjects(night[@"awakeMinutes"], @15);
    XCTAssertEqualObjects(night[@"inBedMinutes"], @510);
}

- (void)testSeparateNightsStaySeparateAndSorted {
    NSArray *samples = @[
        [self sleepSample:HKCategoryValueSleepAnalysisAsleepUnspecified from:@"2026-03-03 23:00" to:@"2026-03-04 06:00"],
        [self sleepSample:HKCategoryValueSleepAnalysisAsleepUnspecified from:@"2026-03-01 23:00" to:@"2026-03-02 06:00"],
    ];
    NSArray *nights = [DSHHealthCapability sleepSummaryFromSamples:samples][@"nights"];
    XCTAssertEqual(nights.count, 2u);
    XCTAssertEqualObjects(nights[0][@"date"], @"2026-03-02", @"nights must come back oldest first");
    XCTAssertEqualObjects(nights[1][@"date"], @"2026-03-04");
    XCTAssertEqualObjects(nights[0][@"asleepMinutes"], @420);
}

- (void)testNoSamplesGiveNoNights {
    XCTAssertEqual([[DSHHealthCapability sleepSummaryFromSamples:@[]][@"nights"] count], 0u);
}

#pragma mark Misc

- (void)testWorkoutNamesAreReadableAndUnknownOnesKeepTheirNumber {
    XCTAssertEqualObjects([DSHHealthCapability activityNameFor:HKWorkoutActivityTypeRunning], @"Running");
    XCTAssertEqualObjects([DSHHealthCapability activityNameFor:HKWorkoutActivityTypeTraditionalStrengthTraining],
                          @"Strength training");
    XCTAssertTrue([[DSHHealthCapability activityNameFor:(HKWorkoutActivityType) 60000] containsString:@"60000"],
                  @"an unmapped activity must stay identifiable to the model");
}

/// The settings screen asks iOS the moment the user opts in, which only works
/// if the capability carries its own request.
- (void)testCapabilityCanAskForItsSystemPermission {
    DSHCapability *capability = [DSHCapabilityRegistry.shared capabilityWithIdentifier:kHealthRead];
    XCTAssertNotNil(capability.requestSystemPermission,
                    @"a system-permission capability must be able to trigger its own dialog");
}

/// One sheet, not seven: everything the routes read is requested together.
- (void)testReadTypesCoverEveryRoute {
    NSSet<HKObjectType *> *types = [DSHHealthCapability readTypes];
    for (HKQuantityTypeIdentifier identifier in @[HKQuantityTypeIdentifierStepCount,
                                                  HKQuantityTypeIdentifierDistanceWalkingRunning,
                                                  HKQuantityTypeIdentifierActiveEnergyBurned,
                                                  HKQuantityTypeIdentifierHeartRate,
                                                  HKQuantityTypeIdentifierRestingHeartRate])
        XCTAssertTrue([types containsObject:[HKObjectType quantityTypeForIdentifier:identifier]],
                      @"%@ is read by a route but not requested", identifier);
    XCTAssertTrue([types containsObject:[HKObjectType categoryTypeForIdentifier:HKCategoryTypeIdentifierSleepAnalysis]]);
    XCTAssertTrue([types containsObject:HKObjectType.workoutType]);
}

/// App Store validation rejects the archive without both keys. Linking HealthKit is
/// enough to require the write string, even though `toShare` is always nil — the check
/// reads the framework's API surface, not ours, so nothing at build or run time catches it.
- (void)testHealthUsageDescriptionsArePresent {
    NSDictionary *info = NSBundle.mainBundle.infoDictionary;
    for (NSString *key in @[@"NSHealthShareUsageDescription", @"NSHealthUpdateUsageDescription"]) {
        NSString *purpose = info[key];
        XCTAssertGreaterThan(purpose.length, 0, @"%@ is missing; the archive will be rejected", key);
    }
}

@end

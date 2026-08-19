//
//  DSHEventKitCapabilityTests.m
//  DSHTests
//
//  Calendar and Reminders routes. The suite must not depend on the tester's
//  actual calendar or on a permission dialog, so it asserts the *contract*:
//  the capability is off by default, a disabled capability is refused before
//  any EventKit call, and an unauthorized one is refused recoverably.
//

#import <XCTest/XCTest.h>
#import <EventKit/EventKit.h>
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHEventKitCapability.h"

// The identifiers are part of the bridge's public contract (they appear in
// /v1/capabilities and in the plugin), so the tests spell them out rather than
// borrowing the app's constants.
static NSString *const kCalendarRead = @"calendar.read";
static NSString *const kRemindersRead = @"reminders.read";

@interface DSHEventKitCapabilityTests : XCTestCase
@property (nonatomic) DSHHostBridge *bridge;
@end

@implementation DSHEventKitCapabilityTests

- (void)setUp {
    [super setUp];
    self.bridge = [DSHHostBridge new];
    XCTAssertTrue([self.bridge start]);
    [DSHEventKitCapability installOn:self.bridge];
}

- (void)tearDown {
    [self.bridge stop];
    [DSHCapabilityRegistry.shared setEnabled:NO forIdentifier:kCalendarRead];
    [DSHCapabilityRegistry.shared setEnabled:NO forIdentifier:kRemindersRead];
    [super tearDown];
}

- (NSDictionary *)get:(NSString *)path status:(NSInteger *)statusOut {
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:
                                    [NSURL URLWithString:[self.bridge.baseURLString stringByAppendingString:path]]];
    [request setValue:[@"Bearer " stringByAppendingString:self.bridge.token] forHTTPHeaderField:@"Authorization"];
    request.timeoutInterval = 30;
    __block NSDictionary *json = nil;
    __block NSInteger status = 0;
    XCTestExpectation *done = [self expectationWithDescription:path];
    [[NSURLSession.sharedSession dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        status = ((NSHTTPURLResponse *) response).statusCode;
        if (data.length)
            json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
        [done fulfill];
    }] resume];
    [self waitForExpectations:@[done] timeout:40];
    if (statusOut) *statusOut = status;
    return json;
}

- (void)testBothCapabilitiesAreOffByDefault {
    DSHCapabilityRegistry *registry = DSHCapabilityRegistry.shared;
    // Sensitive capabilities must never be on without the user saying so.
    XCTAssertFalse([registry isEnabled:kCalendarRead]);
    XCTAssertFalse([registry isEnabled:kRemindersRead]);
    XCTAssertEqual([registry stateForIdentifier:kCalendarRead], DSHCapabilityStateDisabled);
    XCTAssertEqual([registry stateForIdentifier:kRemindersRead], DSHCapabilityStateDisabled);
}

- (void)testCapabilitiesAreAdvertisedWithTheSystemPermissionGate {
    NSArray *summary = DSHCapabilityRegistry.shared.stateSummary;
    NSMutableDictionary *byId = [NSMutableDictionary dictionary];
    for (NSDictionary *entry in summary)
        byId[entry[@"id"]] = entry;
    XCTAssertEqualObjects(byId[kCalendarRead][@"gate"], @"system-permission");
    XCTAssertEqualObjects(byId[kRemindersRead][@"gate"], @"system-permission");
}

- (void)testDisabledCapabilityIsRefusedBeforeTouchingEventKit {
    NSInteger status = 0;
    NSDictionary *json = [self get:@"/v1/calendar/events?days=1" status:&status];
    XCTAssertEqual(status, 403);
    XCTAssertEqualObjects(json[@"error"][@"code"], @"permission_denied");
    XCTAssertEqualObjects(json[@"error"][@"recoverable"], @YES);
    XCTAssertTrue([json[@"error"][@"message"] containsString:@"settings"],
                  @"the message should tell the model what the user has to do: %@", json[@"error"][@"message"]);
}

/// With the switch on, the answer depends on iOS's own permission state: either
/// data, or a recoverable refusal naming the missing access. Both are correct;
/// what must never happen is a hang or an opaque error.
- (void)testEnabledCapabilityEitherAnswersOrRefusesRecoverably {
    [DSHCapabilityRegistry.shared setEnabled:YES forIdentifier:kCalendarRead];
    NSInteger status = 0;
    NSDictionary *json = [self get:@"/v1/calendar/events?days=1&limit=5" status:&status];
    if (status == 200) {
        XCTAssertNotNil(json[@"events"]);
        XCTAssertNotNil(json[@"from"]);
        XCTAssertLessThanOrEqual([json[@"events"] count], 5u, @"limit must be honoured");
    } else {
        XCTAssertEqual(status, 403);
        XCTAssertEqualObjects(json[@"error"][@"code"], @"permission_denied");
        XCTAssertEqualObjects(json[@"error"][@"recoverable"], @YES);
        XCTAssertTrue([json[@"error"][@"message"] containsString:@"calendar"]);
    }
}

- (void)testRemindersRouteBehavesTheSameWay {
    [DSHCapabilityRegistry.shared setEnabled:YES forIdentifier:kRemindersRead];
    NSInteger status = 0;
    NSDictionary *json = [self get:@"/v1/reminders?limit=3" status:&status];
    if (status == 200) {
        XCTAssertNotNil(json[@"reminders"]);
        XCTAssertLessThanOrEqual([json[@"reminders"] count], 3u);
    } else {
        XCTAssertEqual(status, 403);
        XCTAssertEqualObjects(json[@"error"][@"code"], @"permission_denied");
        XCTAssertEqualObjects(json[@"error"][@"recoverable"], @YES);
    }
}

/// Guards the limits the model relies on: a huge `limit` or `days` must be
/// clamped rather than passed through to EventKit.
- (void)testOutOfRangeArgumentsAreClamped {
    [DSHCapabilityRegistry.shared setEnabled:YES forIdentifier:kCalendarRead];
    NSInteger status = 0;
    NSDictionary *json = [self get:@"/v1/calendar/events?days=99999&limit=99999" status:&status];
    XCTAssertTrue(status == 200 || status == 403, @"unexpected status %ld", (long) status);
    if (status == 200)
        XCTAssertLessThanOrEqual([json[@"events"] count], 200u, @"limit must be capped server-side");
}

@end

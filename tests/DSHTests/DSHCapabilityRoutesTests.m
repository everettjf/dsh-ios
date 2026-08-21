//
//  DSHCapabilityRoutesTests.m
//  DSHTests
//
//  The capabilities added alongside the write gate: power, location, contacts,
//  notifications, files, shortcuts, and the EventKit write routes.
//
//  None of these may depend on the tester's own data, permissions or taps, so
//  what is asserted is the contract: off by default, refused before the
//  framework is touched, arguments validated before anything happens, and —
//  for everything that writes — nothing at all without a confirmation.
//

#import <XCTest/XCTest.h>
#import <netinet/in.h>
#import <sys/socket.h>
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHCallConfirmation.h"
#import "DSHDeviceCapability.h"
#import "DSHLocationCapability.h"
#import "DSHContactsCapability.h"
#import <Contacts/Contacts.h>
#import "DSHNotificationCapability.h"
#import "DSHFilesCapability.h"
#import "DSHShortcutsCapability.h"
#import "DSHEventKitCapability.h"

@interface DSHCapabilityRoutesTests : XCTestCase
@property (nonatomic) DSHHostBridge *bridge;
@end

@implementation DSHCapabilityRoutesTests

- (void)setUp {
    [super setUp];
    self.bridge = [DSHHostBridge new];
    XCTAssertTrue([self.bridge start]);
    [DSHDeviceCapability installOn:self.bridge];
    [DSHLocationCapability installOn:self.bridge];
    [DSHContactsCapability installOn:self.bridge];
    [DSHNotificationCapability installOn:self.bridge];
    [DSHFilesCapability installOn:self.bridge];
    [DSHShortcutsCapability installOn:self.bridge];
    [DSHEventKitCapability installOn:self.bridge];
    // Capabilities ship on now; these suites assert what happens when one is off,
    // with device.info left on as the route that is expected to work.
    [DSHCapabilityRegistry.shared disableAllForTesting];
    [DSHCapabilityRegistry.shared setEnabled:YES forIdentifier:@"device.info"];
}

- (void)tearDown {
    [self.bridge stop];
    DSHCallConfirmation.automaticallyApproveForTesting = NO;
    DSHCallConfirmation.automaticallyDeclineForTesting = NO;
    for (NSString *identifier in @[@"location.read", @"contacts.read",
                                   @"notifications.post", @"files.import", @"files.export", @"shortcuts.run",
                                   @"calendar.write", @"reminders.write"])
        [DSHCapabilityRegistry.shared setEnabled:NO forIdentifier:identifier];
    [super tearDown];
}

#pragma mark Helpers

- (NSDictionary *)send:(NSString *)method path:(NSString *)path body:(nullable NSDictionary *)body status:(NSInteger *)statusOut {
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:
                                    [NSURL URLWithString:[self.bridge.baseURLString stringByAppendingString:path]]];
    request.HTTPMethod = method;
    [request setValue:[@"Bearer " stringByAppendingString:self.bridge.token] forHTTPHeaderField:@"Authorization"];
    if (body) {
        [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
        request.HTTPBody = [NSJSONSerialization dataWithJSONObject:body options:0 error:nil];
    }
    request.timeoutInterval = 60;
    __block NSDictionary *json = nil;
    __block NSInteger status = 0;
    XCTestExpectation *done = [self expectationWithDescription:path];
    [[NSURLSession.sharedSession dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        status = ((NSHTTPURLResponse *) response).statusCode;
        if (data.length)
            json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
        [done fulfill];
    }] resume];
    [self waitForExpectations:@[done] timeout:90];
    if (statusOut) *statusOut = status;
    return json;
}

- (void)enable:(NSString *)identifier {
    [DSHCapabilityRegistry.shared setEnabled:YES forIdentifier:identifier];
}

#pragma mark Defaults

/// Capabilities ship on, so every one of them has to carry a real gate underneath:
/// a switch on its own protects nothing once the switch starts out closed.
- (void)testEveryCapabilityThatShipsOnHasAGateUnderTheSwitch {
    // device.info returns no user data. files.import cannot return anything at all
    // until the user picks a file in the system document picker, so the interaction
    // is the gate even though the enum has no name for it.
    NSArray *gatedByTheirOwnInteraction = @[@"device.info", @"files.import"];
    for (DSHCapability *capability in DSHCapabilityRegistry.shared.capabilities) {
        if (!capability.enabledByDefault) continue;
        if ([gatedByTheirOwnInteraction containsObject:capability.identifier]) continue;
        XCTAssertNotEqual(capability.gate, DSHCapabilityGateEnabledOnly,
                          @"%@ ships on with nothing but the switch in front of it",
                          capability.identifier);
    }
}

/// The switch is the only control the user has over a capability that ships on,
/// so switching one off has to actually stop it — for every capability, not just
/// the ones with a suite of their own.
- (void)testSwitchingAnyCapabilityOffRefusesIt {
    DSHCapabilityRegistry *registry = DSHCapabilityRegistry.shared;
    for (DSHCapability *capability in registry.capabilities) {
        if (!capability.available) continue;
        [registry setEnabled:YES forIdentifier:capability.identifier];
        XCTAssertNotEqual([registry stateForIdentifier:capability.identifier],
                          DSHCapabilityStateDisabled,
                          @"%@ stayed disabled after being switched on", capability.identifier);

        [registry setEnabled:NO forIdentifier:capability.identifier];
        XCTAssertFalse([registry isEnabled:capability.identifier],
                       @"%@ ignored being switched off", capability.identifier);
        XCTAssertEqual([registry stateForIdentifier:capability.identifier],
                       DSHCapabilityStateDisabled,
                       @"%@ still reports usable after being switched off", capability.identifier);
    }
}

/// ...and the refusal has to happen at the route, before the framework is touched.
- (void)testARouteWhoseCapabilityIsOffIsRefused {
    DSHCapabilityRegistry *registry = DSHCapabilityRegistry.shared;
    [registry setEnabled:NO forIdentifier:@"device.info"];
    NSInteger status = 0;
    [self send:@"GET" path:@"/v1/device" body:nil status:&status];
    XCTAssertEqual(status, 403, @"a switched-off capability must refuse at the route");
    [registry setEnabled:YES forIdentifier:@"device.info"];
    [self send:@"GET" path:@"/v1/device" body:nil status:&status];
    XCTAssertEqual(status, 200, @"switching it back on must restore it");
}

/// Everything that changes something outside the app has to be per-call, or
/// the confirmation gate is decoration.
- (void)testEverythingThatWritesIsGatedPerCall {
    for (NSString *identifier in @[@"files.export", @"shortcuts.run",
                                   @"calendar.write", @"reminders.write"])
        XCTAssertEqual([DSHCapabilityRegistry.shared capabilityWithIdentifier:identifier].gate,
                       DSHCapabilityGatePerCall, @"%@ must ask every time", identifier);
    for (NSString *identifier in @[@"location.read", @"contacts.read", @"notifications.post"])
        XCTAssertEqual([DSHCapabilityRegistry.shared capabilityWithIdentifier:identifier].gate,
                       DSHCapabilityGateSystemPermission, @"%@ needs iOS's own dialog", identifier);
}

- (void)testDisabledCapabilitiesAreRefusedBeforeAnythingHappens {
    NSArray *calls = @[@[@"GET", @"/v1/location"],
                       @[@"GET", @"/v1/contacts?q=x"], @[@"POST", @"/v1/notify"],
                       @[@"POST", @"/v1/files/import"], @[@"POST", @"/v1/shortcut/run"]];
    for (NSArray *call in calls) {
        NSInteger status = 0;
        BOOL isPost = [call[0] isEqualToString:@"POST"];
        NSDictionary *json = [self send:call[0] path:call[1] body:(isPost ? @{} : nil) status:&status];
        XCTAssertEqual(status, 403, @"%@ %@", call[0], call[1]);
        XCTAssertEqualObjects(json[@"error"][@"code"], @"permission_denied");
    }
}

/// A client whose headers promise a body it never sends used to get silence:
/// the bridge waited for the missing bytes, hit the socket's receive timeout
/// and closed without a word, which from the caller's side is indistinguishable
/// from a hang. It now answers.
///
/// This has to be driven with a raw socket. The obvious way to provoke it —
/// a GET carrying a JSON body — never reaches the bridge at all, because
/// NSURLSession refuses that request locally; a first version of this test was
/// written that way and "failed" without a single byte crossing the socket.
///
/// Slow on purpose: the answer arrives only once the receive timeout expires,
/// and the point is that it arrives.
- (void)testARequestThatPromisesABodyItNeverSendsIsAnswered {
    int client = socket(AF_INET, SOCK_STREAM, 0);
    XCTAssertGreaterThanOrEqual(client, 0);
    struct sockaddr_in address = {0};
    address.sin_family = AF_INET;
    address.sin_port = htons(self.bridge.port);
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    XCTAssertEqual(connect(client, (struct sockaddr *) &address, sizeof(address)), 0);

    // Content-Length announces 50 bytes that never follow.
    NSString *request = [NSString stringWithFormat:
                         @"GET /v1/device/power HTTP/1.1\r\nHost: 127.0.0.1\r\nAuthorization: Bearer %@\r\n"
                         @"Content-Length: 50\r\n\r\n", self.bridge.token];
    NSData *bytes = [request dataUsingEncoding:NSUTF8StringEncoding];
    XCTAssertEqual(send(client, bytes.bytes, bytes.length, 0), (ssize_t) bytes.length);

    struct timeval timeout = { .tv_sec = 40 };
    setsockopt(client, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    NSMutableData *received = [NSMutableData data];
    char chunk[2048];
    ssize_t n;
    while ((n = recv(client, chunk, sizeof(chunk), 0)) > 0)
        [received appendBytes:chunk length:n];
    close(client);

    NSString *answer = [[NSString alloc] initWithData:received encoding:NSUTF8StringEncoding];
    XCTAssertGreaterThan(received.length, 0u, @"a stalled request must not be closed in silence");
    XCTAssertTrue([answer containsString:@"400"], @"expected a 400, got:\n%@", answer);
    XCTAssertTrue([answer containsString:@"invalid_request"], @"expected an error envelope, got:\n%@", answer);

    // And the bridge is still serving: one bad client must not take it down.
    NSInteger status = 0;
    NSDictionary *after = [self send:@"GET" path:@"/v1/device/power" body:nil status:&status];
    XCTAssertEqual(status, 200);
    XCTAssertNotNil(after[@"thermalState"]);
}

#pragma mark Power

- (void)testPowerRouteAnswersAndAdvisesOnExpensiveWork {
    NSInteger status = 0;
    NSDictionary *json = [self send:@"GET" path:@"/v1/device/power" body:nil status:&status];
    XCTAssertEqual(status, 200, @"device.info is on by default");
    XCTAssertNotNil(json[@"thermalState"]);
    XCTAssertNotNil(json[@"shouldDeferExpensiveWork"]);

    NSDictionary *snapshot = [DSHDeviceCapability powerSnapshot];
    BOOL hot = [snapshot[@"thermalState"] isEqualToString:@"serious"] || [snapshot[@"thermalState"] isEqualToString:@"critical"];
    XCTAssertEqual([snapshot[@"shouldDeferExpensiveWork"] boolValue],
                   hot || [snapshot[@"lowPowerMode"] boolValue],
                   @"the advice must follow the thermal state and low power mode");
}

#pragma mark Contacts

/// The absence of a "list everyone" route is a design decision, so it is worth
/// a test: no query, no answer.
- (void)testContactsRequiresAQuery {
    [self enable:@"contacts.read"];
    NSInteger status = 0;
    NSDictionary *json = [self send:@"GET" path:@"/v1/contacts" body:nil status:&status];
    XCTAssertEqual(status, 400);
    XCTAssertTrue([json[@"error"][@"message"] containsString:@"every contact"],
                  @"the message should say why: %@", json[@"error"][@"message"]);
}

/// A search that matches nobody exercises none of the formatting, so this is
/// asserted directly: without the formatter's own descriptor, the first real
/// match raises "a property was not requested" and the route 500s. It did,
/// on a device with contacts, after every contract test had passed.
- (void)testContactKeysIncludeTheFormattersOwnRequirements {
    NSArray<id<CNKeyDescriptor>> *keys = [DSHContactsCapability keysToFetch];
    id<CNKeyDescriptor> formatterKeys = [CNContactFormatter descriptorForRequiredKeysForStyle:CNContactFormatterStyleFullName];
    XCTAssertTrue([keys containsObject:formatterKeys],
                  @"the formatter's keys must be fetched, or formatting a match raises");
    for (NSString *key in @[CNContactPhoneNumbersKey, CNContactEmailAddressesKey,
                            CNContactPostalAddressesKey, CNContactBirthdayKey])
        XCTAssertTrue([keys containsObject:key], @"%@ is returned by the route but not fetched", key);
}

- (void)testContactsSearchAnswersOrRefusesRecoverably {
    [self enable:@"contacts.read"];
    NSInteger status = 0;
    NSDictionary *json = [self send:@"GET" path:@"/v1/contacts?q=zzzznobody&limit=3" body:nil status:&status];
    if (status == 200) {
        XCTAssertNotNil(json[@"contacts"]);
        XCTAssertLessThanOrEqual([json[@"contacts"] count], 3u);
    } else {
        XCTAssertEqual(status, 403);
        XCTAssertEqualObjects(json[@"error"][@"recoverable"], @YES);
    }
}

#pragma mark Notifications

- (void)testNotifyValidatesTitleBeforeTouchingTheSystem {
    [self enable:@"notifications.post"];
    NSInteger status = 0;
    NSDictionary *json = [self send:@"POST" path:@"/v1/notify" body:@{ @"body": @"no title" } status:&status];
    XCTAssertEqual(status, 400);
    XCTAssertEqualObjects(json[@"error"][@"code"], @"invalid_request");
}

/// The rate limit is what stops a looping agent owning the lock screen, so it
/// is asserted directly rather than through the route.
- (void)testNotificationRateLimitRefusesAfterTen {
    [DSHNotificationCapability resetRateLimitForTesting];
    NSUInteger remaining = 0;
    for (int i = 0; i < 10; i++)
        XCTAssertTrue([DSHNotificationCapability takeRateLimitSlot:&remaining], @"call %d should fit", i);
    XCTAssertEqual(remaining, 0u);
    XCTAssertFalse([DSHNotificationCapability takeRateLimitSlot:&remaining], @"the eleventh must be refused");
    [DSHNotificationCapability resetRateLimitForTesting];
    XCTAssertTrue([DSHNotificationCapability takeRateLimitSlot:&remaining]);
    [DSHNotificationCapability resetRateLimitForTesting];
}

#pragma mark Files

- (void)testExportValidatesBeforeAsking {
    [self enable:@"files.export"];
    NSUInteger before = DSHCallConfirmation.presentedCount;
    NSInteger status = 0;
    [self send:@"POST" path:@"/v1/files/export" body:@{ @"name": @"x.txt" } status:&status];
    XCTAssertEqual(status, 400, @"missing contents");
    [self send:@"POST" path:@"/v1/files/export" body:@{ @"name": @"x.txt", @"base64": @"not base64!!" } status:&status];
    XCTAssertEqual(status, 400, @"undecodable contents");
    XCTAssertEqual(DSHCallConfirmation.presentedCount, before, @"neither may reach the user");
}

- (void)testExportIsRefusedWhenTheUserDeclines {
    [self enable:@"files.export"];
    DSHCallConfirmation.automaticallyDeclineForTesting = YES;
    NSInteger status = 0;
    NSDictionary *json = [self send:@"POST" path:@"/v1/files/export"
                               body:@{ @"name": @"notes.txt", @"base64": @"aGVsbG8=" } status:&status];
    XCTAssertEqual(status, 403);
    XCTAssertEqualObjects(json[@"error"][@"code"], @"permission_denied");
}

- (void)testExportRejectsOversizedPayloads {
    [self enable:@"files.export"];
    NSUInteger bytes = [DSHFilesCapability maximumBytes] + 1024;
    NSString *base64 = [[NSMutableData dataWithLength:bytes] base64EncodedStringWithOptions:0];
    NSInteger status = 0;
    NSDictionary *json = [self send:@"POST" path:@"/v1/files/export"
                               body:@{ @"name": @"big.bin", @"base64": base64 } status:&status];
    XCTAssertEqual(status, 413);
    XCTAssertEqualObjects(json[@"error"][@"code"], @"invalid_request");
}

#pragma mark Shortcuts

/// A shortcut name comes from the model; it must not be able to smuggle extra
/// x-callback-url parameters through it.
- (void)testShortcutURLEncodingCannotInjectParameters {
    NSURL *url = [DSHShortcutsCapability urlForShortcut:@"Evil&x-error=http://x&name=Other" input:nil];
    NSString *string = url.absoluteString;
    XCTAssertNotNil(url);
    NSUInteger nameOccurrences = [string componentsSeparatedByString:@"name="].count - 1;
    XCTAssertEqual(nameOccurrences, 1u, @"the name must not introduce another parameter: %@", string);
    XCTAssertFalse([string containsString:@"x-error="], @"unescaped & would add a callback: %@", string);

    XCTAssertNil([DSHShortcutsCapability urlForShortcut:@"" input:nil]);
    NSURL *withInput = [DSHShortcutsCapability urlForShortcut:@"Log" input:@"a b&c"];
    XCTAssertTrue([withInput.absoluteString containsString:@"input=text"]);
    XCTAssertFalse([withInput.absoluteString containsString:@"b&c"], @"input must be escaped too");
}

- (void)testShortcutRunValidatesAndAsks {
    [self enable:@"shortcuts.run"];
    NSUInteger before = DSHCallConfirmation.presentedCount;
    NSInteger status = 0;
    [self send:@"POST" path:@"/v1/shortcut/run" body:@{} status:&status];
    XCTAssertEqual(status, 400, @"a missing name must not prompt");
    XCTAssertEqual(DSHCallConfirmation.presentedCount, before);

    DSHCallConfirmation.automaticallyDeclineForTesting = YES;
    NSDictionary *json = [self send:@"POST" path:@"/v1/shortcut/run" body:@{ @"name": @"Nonexistent" } status:&status];
    XCTAssertEqual(status, 403);
    XCTAssertEqualObjects(json[@"error"][@"recoverable"], @NO);
}

#pragma mark EventKit writes

- (void)testEventCreationValidatesDatesBeforeAsking {
    [self enable:@"calendar.write"];
    NSUInteger before = DSHCallConfirmation.presentedCount;
    NSInteger status = 0;
    [self send:@"POST" path:@"/v1/calendar/events" body:@{ @"start": @"2026-08-20 10:00" } status:&status];
    XCTAssertEqual(status, 400, @"a missing title");
    [self send:@"POST" path:@"/v1/calendar/events" body:@{ @"title": @"x", @"start": @"whenever" } status:&status];
    XCTAssertEqual(status, 400, @"an unparseable start");
    [self send:@"POST" path:@"/v1/calendar/events"
          body:@{ @"title": @"x", @"start": @"2026-08-20 10:00", @"end": @"2026-08-20 09:00" } status:&status];
    XCTAssertEqual(status, 400, @"an end before the start");
    XCTAssertEqual(DSHCallConfirmation.presentedCount, before, @"none of those may reach the user");
}

/// The date formats a model actually writes have to work, in the device's own
/// time zone — an event at "14:00" must not land at 14:00 UTC.
- (void)testDateParsingAcceptsWhatAModelWrites {
    NSDate *iso = [DSHEventKitCapability dateFromString:@"2026-08-20T14:00:00Z"];
    XCTAssertNotNil(iso);

    NSDate *local = [DSHEventKitCapability dateFromString:@"2026-08-20 14:00"];
    XCTAssertNotNil(local);
    NSDateComponents *parts = [NSCalendar.currentCalendar components:NSCalendarUnitHour | NSCalendarUnitMinute | NSCalendarUnitDay
                                                           fromDate:local];
    XCTAssertEqual(parts.hour, 14, @"a bare time means the device's wall clock");
    XCTAssertEqual(parts.minute, 0);
    XCTAssertEqual(parts.day, 20);

    NSDate *day = [DSHEventKitCapability dateFromString:@"2026-08-20"];
    XCTAssertNotNil(day);
    XCTAssertNil([DSHEventKitCapability dateFromString:@"next tuesday"]);
    XCTAssertNil([DSHEventKitCapability dateFromString:@""]);
}

- (void)testReminderCreationIsRefusedWhenTheUserDeclines {
    [self enable:@"reminders.write"];
    DSHCallConfirmation.automaticallyDeclineForTesting = YES;
    NSInteger status = 0;
    NSDictionary *json = [self send:@"POST" path:@"/v1/reminders"
                               body:@{ @"title": @"DSH test reminder", @"due": @"2026-12-31 09:00" } status:&status];
    // Either the confirmation refused it, or EventKit has no permission yet —
    // both are refusals, and neither may create anything.
    XCTAssertTrue(status == 403, @"unexpected status %ld", (long) status);
    XCTAssertEqualObjects(json[@"error"][@"code"], @"permission_denied");
}

@end

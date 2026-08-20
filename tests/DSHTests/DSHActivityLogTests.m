//
//  DSHActivityLogTests.m
//  DSHTests
//
//  The record of what the agent did. Two things are being protected here: that
//  it captures enough to be worth reading, and that it does not become a copy
//  of the data the capabilities returned — a log of the user's contacts would
//  be a worse leak than the capability it exists to make auditable.
//

#import <XCTest/XCTest.h>
#import "DSHActivityLog.h"
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHCallConfirmation.h"
#import "DSHActivityCapability.h"
#import "DSHDeviceCapability.h"
#import "DSHContactsCapability.h"

@interface DSHActivityLogTests : XCTestCase
@property (nonatomic) DSHHostBridge *bridge;
@end

@implementation DSHActivityLogTests

- (void)setUp {
    [super setUp];
    [DSHActivityLog.shared resetForTesting];
    self.bridge = [DSHHostBridge new];
    XCTAssertTrue([self.bridge start]);
    [DSHDeviceCapability installOn:self.bridge];
    [DSHContactsCapability installOn:self.bridge];
    [DSHActivityCapability installOn:self.bridge];
}

- (void)tearDown {
    [self.bridge stop];
    [DSHCapabilityRegistry.shared setEnabled:NO forIdentifier:@"contacts.read"];
    [DSHActivityLog.shared resetForTesting];
    [super tearDown];
}

- (NSDictionary *)send:(NSString *)method path:(NSString *)path body:(nullable NSDictionary *)body status:(NSInteger *)statusOut {
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:
                                    [NSURL URLWithString:[self.bridge.baseURLString stringByAppendingString:path]]];
    request.HTTPMethod = method;
    [request setValue:[@"Bearer " stringByAppendingString:self.bridge.token] forHTTPHeaderField:@"Authorization"];
    if (body) {
        [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
        request.HTTPBody = [NSJSONSerialization dataWithJSONObject:body options:0 error:nil];
    }
    request.timeoutInterval = 30;
    __block NSDictionary *json = nil;
    __block NSInteger status = 0;
    XCTestExpectation *done = [self expectationWithDescription:path];
    [[NSURLSession.sharedSession dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        status = ((NSHTTPURLResponse *) response).statusCode;
        if (data.length) json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
        [done fulfill];
    }] resume];
    [self waitForExpectations:@[done] timeout:60];
    if (statusOut) *statusOut = status;
    return json;
}

/// Entries are appended asynchronously, so a test that reads immediately would
/// race the queue.
- (nullable DSHActivityEntry *)waitForEntryNamed:(NSString *)name {
    NSDate *deadline = [NSDate dateWithTimeIntervalSinceNow:5];
    while ([deadline timeIntervalSinceNow] > 0) {
        for (DSHActivityEntry *entry in DSHActivityLog.shared.entries)
            if ([entry.name isEqualToString:name])
                return entry;
        [NSRunLoop.currentRunLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.05]];
    }
    return nil;
}

#pragma mark What gets recorded

- (void)testACapabilityCallIsRecordedWithItsOutcome {
    NSInteger status = 0;
    [self send:@"GET" path:@"/v1/device/power" body:nil status:&status];
    XCTAssertEqual(status, 200);

    DSHActivityEntry *entry = [self waitForEntryNamed:@"device.info"];
    XCTAssertNotNil(entry, @"the call should be in the record");
    XCTAssertEqual(entry.source, DSHActivitySourceCapability);
    XCTAssertEqual(entry.outcome, DSHActivityOutcomeOK);
    XCTAssertNotNil(entry.result, @"the shape of the answer should be recorded");
}

- (void)testARefusedCallIsRecordedAsRefused {
    NSInteger status = 0;
    [self send:@"GET" path:@"/v1/contacts?q=x" body:nil status:&status];
    XCTAssertEqual(status, 403, @"contacts is off by default");

    DSHActivityEntry *entry = [self waitForEntryNamed:@"contacts.read"];
    XCTAssertNotNil(entry);
    XCTAssertEqual(entry.outcome, DSHActivityOutcomeRefused,
                   @"a refusal is exactly what someone opens this screen to find");
}

/// The heart of the privacy policy: what a read *returned* must not be in the
/// log. A contact search is the sharpest case — the query is arguably the
/// user's own words, but the names that came back are other people's.
- (void)testAReadsContentsNeverReachTheRecord {
    [DSHCapabilityRegistry.shared setEnabled:YES forIdentifier:@"contacts.read"];
    NSInteger status = 0;
    [self send:@"GET" path:@"/v1/contacts?q=zzzznobodyzzzz&limit=3" body:nil status:&status];

    DSHActivityEntry *entry = [self waitForEntryNamed:@"contacts.read"];
    XCTAssertNotNil(entry);
    if (status == 200) {
        // Shape only: "0 contacts", never a name.
        XCTAssertTrue([entry.result containsString:@"contacts"],
                      @"expected a count, got: %@", entry.result);
        XCTAssertFalse([entry.result containsString:@"\"name\""], @"the payload leaked into the log");
    }
    XCTAssertTrue([entry.detail containsString:@"q=zzzznobodyzzzz"],
                  @"the query is what makes the row meaningful: %@", entry.detail);
}

- (void)testConfirmationsRecordWhatWasAskedAndAnswered {
    DSHCallConfirmation.automaticallyDeclineForTesting = YES;
    [DSHCallConfirmation confirmTitle:@"Add this reminder?" detail:@"“buy milk”, due Friday"];
    DSHCallConfirmation.automaticallyDeclineForTesting = NO;

    DSHActivityEntry *entry = [self waitForEntryNamed:@"Add this reminder?"];
    XCTAssertNotNil(entry);
    XCTAssertEqual(entry.source, DSHActivitySourceConfirmation);
    XCTAssertEqual(entry.outcome, DSHActivityOutcomeDeclined);
    XCTAssertTrue([entry.detail containsString:@"buy milk"],
                  @"the effect the user saw is the point of the row");
}

#pragma mark The guest's own tools

- (void)testTheGuestCanReportToolsThatNeverTouchTheBridge {
    NSInteger status = 0;
    NSDictionary *json = [self send:@"POST" path:@"/v1/activity" body:@{ @"events": @[
        @{ @"name": @"bash", @"detail": @"ls -la /root", @"outcome": @"started" },
        @{ @"name": @"bash", @"outcome": @"ok", @"duration": @0.42 },
    ] } status:&status];
    XCTAssertEqual(status, 200);
    XCTAssertEqualObjects(json[@"accepted"], @2);

    DSHActivityEntry *entry = [self waitForEntryNamed:@"bash"];
    XCTAssertNotNil(entry, @"a tool that never reaches iOS still belongs in the record");
    XCTAssertEqual(entry.source, DSHActivitySourceGuestTool);
}

- (void)testMalformedReportsAreIgnoredRatherThanRejected {
    NSInteger status = 0;
    NSDictionary *json = [self send:@"POST" path:@"/v1/activity" body:@{ @"events": @[
        @{ @"detail": @"no name" }, @"not an object", @{ @"name": @"web_search", @"outcome": @"ok" },
    ] } status:&status];
    // A reporting path that 400s on one bad row would drop the good ones with
    // it, and the guest has no way to fix them.
    XCTAssertEqual(status, 200);
    XCTAssertEqualObjects(json[@"accepted"], @1);
}

#pragma mark Shape of the record itself

- (void)testDetailIsFlattenedAndBounded {
    NSMutableString *huge = [NSMutableString string];
    for (int i = 0; i < 200; i++) [huge appendString:@"line of output\n"];
    [DSHActivityLog.shared recordSource:DSHActivitySourceGuestTool name:@"bash" detail:huge
                                 result:nil outcome:DSHActivityOutcomeOK duration:0];

    DSHActivityEntry *entry = [self waitForEntryNamed:@"bash"];
    XCTAssertNotNil(entry);
    XCTAssertLessThan(entry.detail.length, 400u, @"one tool must not be able to fill the log");
    XCTAssertFalse([entry.detail containsString:@"\n"], @"a row is one line");
}

- (void)testNewestFirstAndCountedForRepeatDetection {
    for (int i = 0; i < 4; i++)
        [DSHActivityLog.shared recordSource:DSHActivitySourceCapability name:@"calendar.write"
                                     detail:[NSString stringWithFormat:@"call %d", i]
                                     result:nil outcome:DSHActivityOutcomeOK duration:0];
    [self waitForEntryNamed:@"calendar.write"];

    XCTAssertEqualObjects(DSHActivityLog.shared.entries.firstObject.detail, @"call 3",
                          @"newest first");
    XCTAssertEqual([DSHActivityLog.shared countOf:@"calendar.write" within:600], 4u,
                   @"this count is what lets a confirmation say “the fifth time in ten minutes”");
    XCTAssertEqual([DSHActivityLog.shared countOf:@"calendar.write" within:0], 0u);
}

/// "Last used" on the Capabilities screen must mean what it says: a call that
/// was refused never reached the framework and is not a use.
- (void)testLastUseIgnoresRefusals {
    [DSHActivityLog.shared recordSource:DSHActivitySourceCapability name:@"location.read" detail:nil
                                 result:nil outcome:DSHActivityOutcomeRefused duration:0];
    [self waitForEntryNamed:@"location.read"];
    XCTAssertNil([DSHActivityLog.shared lastUseOf:@"location.read"]);

    [DSHActivityLog.shared recordSource:DSHActivitySourceCapability name:@"location.read" detail:nil
                                 result:nil outcome:DSHActivityOutcomeOK duration:0];
    NSDate *deadline = [NSDate dateWithTimeIntervalSinceNow:5];
    while ([DSHActivityLog.shared lastUseOf:@"location.read"] == nil && [deadline timeIntervalSinceNow] > 0)
        [NSRunLoop.currentRunLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.05]];
    XCTAssertNotNil([DSHActivityLog.shared lastUseOf:@"location.read"]);
}

- (void)testClearingLeavesNothingBehind {
    [DSHActivityLog.shared recordSource:DSHActivitySourceGuestTool name:@"bash" detail:@"whoami"
                                 result:nil outcome:DSHActivityOutcomeOK duration:0];
    [self waitForEntryNamed:@"bash"];
    [DSHActivityLog.shared clear];
    NSDate *deadline = [NSDate dateWithTimeIntervalSinceNow:5];
    while (DSHActivityLog.shared.entries.count > 0 && [deadline timeIntervalSinceNow] > 0)
        [NSRunLoop.currentRunLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.05]];
    XCTAssertEqual(DSHActivityLog.shared.entries.count, 0u);
    XCTAssertEqualObjects(DSHActivityLog.shared.plainText, @"");
}

@end

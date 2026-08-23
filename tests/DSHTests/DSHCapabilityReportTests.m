//
//  DSHCapabilityReportTests.m
//  DSHTests
//
//  A report, not a gate.
//
//  Every other suite asserts the contract — off by default, refused when
//  declined — and passes on a device where nothing has ever been granted. That
//  is what makes them portable, and also what lets a green run hide the fact
//  that no capability was ever actually exercised.
//
//  This one enables each read capability, calls its route, and prints what came
//  back: status, and the shape of the answer. Counts and lengths only, never
//  values — the contents are the tester's contacts, calendar and location, and
//  they have no business in a build log.
//
//  First run on a device triggers the system prompts and reports refusals;
//  answer them and run it again to see the real shapes.
//

#import <XCTest/XCTest.h>
#import <CoreLocation/CoreLocation.h>
#import <Contacts/Contacts.h>
#import <EventKit/EventKit.h>
#import <UserNotifications/UserNotifications.h>
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHCallConfirmation.h"
#import "DSHDeviceCapability.h"
#import "DSHLocationCapability.h"
#import "DSHContactsCapability.h"
#import "DSHNotificationCapability.h"
#import "DSHFilesCapability.h"
#import "DSHShortcutsCapability.h"
#import "DSHEventKitCapability.h"
#import "DSHHealthCapability.h"
#import "ISHShellExecutor.h"
#import "DSHHarness.h"

@interface DSHCapabilityReportTests : XCTestCase
@property (nonatomic) DSHHostBridge *bridge;
@property (nonatomic) NSMutableArray<NSString *> *enabled;
@end

@implementation DSHCapabilityReportTests

- (void)setUp {
    [super setUp];
    self.enabled = [NSMutableArray array];
    self.bridge = [DSHHostBridge new];
    XCTAssertTrue([self.bridge start]);
    [DSHDeviceCapability installOn:self.bridge];
    [DSHLocationCapability installOn:self.bridge];
    [DSHContactsCapability installOn:self.bridge];
    [DSHNotificationCapability installOn:self.bridge];
    [DSHFilesCapability installOn:self.bridge];
    [DSHShortcutsCapability installOn:self.bridge];
    [DSHEventKitCapability installOn:self.bridge];
    [DSHHealthCapability installOn:self.bridge];
}

- (void)tearDown {
    // Leave the device exactly as it was found.
    for (NSString *identifier in self.enabled)
        [DSHCapabilityRegistry.shared setEnabled:NO forIdentifier:identifier];
    [self.bridge stop];
    [super tearDown];
}

- (void)enable:(NSString *)identifier {
    [DSHCapabilityRegistry.shared setEnabled:YES forIdentifier:identifier];
    [self.enabled addObject:identifier];
}

- (NSDictionary *)get:(NSString *)path status:(NSInteger *)statusOut {
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:
                                    [NSURL URLWithString:[self.bridge.baseURLString stringByAppendingString:path]]];
    [request setValue:[@"Bearer " stringByAppendingString:self.bridge.token] forHTTPHeaderField:@"Authorization"];
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

/// One line per route: what happened, in a form that says whether the
/// capability really worked without saying what it saw.
/// Blocks until the guest is up, the way DSHGuestIntegrationTests does.
- (void)waitForHarnessReady {
    DSHHarness *harness = DSHHarness.shared;
    if (harness.state == DSHHarnessStateReady)
        return;
    XCTestExpectation *ready = [self expectationForNotification:DSHHarnessStateDidChangeNotification
                                                         object:harness
                                                        handler:^BOOL(NSNotification *note) {
        return harness.state == DSHHarnessStateReady;
    }];
    [self waitForExpectations:@[ready] timeout:300];
}

- (void)report:(NSString *)path shape:(NSString *(^)(NSDictionary *))shape {
    NSInteger status = 0;
    NSDictionary *json = [self get:path status:&status];
    if (status == 200)
        NSLog(@"[dsh-report] %@ → 200, %@", path, shape(json));
    else
        NSLog(@"[dsh-report] %@ → %ld %@: %@", path, (long) status,
              json[@"error"][@"code"] ?: @"(no code)", json[@"error"][@"message"] ?: @"(no message)");
}

- (void)testReportEveryReadCapabilityOnThisDevice {
    NSLog(@"[dsh-report] ---- capability report ----");

    // Permission states first, so a refusal below has an explanation next to it.
    // Do not call +locationServicesEnabled from this main-thread XCTest. The
    // location route checks it on a worker queue before requesting a fix.
    NSLog(@"[dsh-report] location authorization: %ld",
          (long) [CLLocationManager new].authorizationStatus);
    NSLog(@"[dsh-report] contacts authorization: %ld",
          (long) [CNContactStore authorizationStatusForEntityType:CNEntityTypeContacts]);
    NSLog(@"[dsh-report] calendar authorization: %ld, reminders: %ld",
          (long) [EKEventStore authorizationStatusForEntityType:EKEntityTypeEvent],
          (long) [EKEventStore authorizationStatusForEntityType:EKEntityTypeReminder]);
    NSLog(@"[dsh-report] notifications authorization: %ld", (long) [DSHNotificationCapability authorizationStatus]);

    [self report:@"/v1/device/power" shape:^NSString *(NSDictionary *json) {
        return [NSString stringWithFormat:@"battery %@%%, %@, thermal %@, defer %@",
                json[@"batteryLevel"] ?: @"?", json[@"batteryState"] ?: @"?",
                json[@"thermalState"], json[@"shouldDeferExpensiveWork"]];
    }];

    [self enable:@"location.read"];
    [self report:@"/v1/location" shape:^NSString *(NSDictionary *json) {
        // Accuracy and age prove a real fix without recording where the tester is.
        return [NSString stringWithFormat:@"a fix, accuracy ±%@ m, timestamp present: %@",
                json[@"accuracyMeters"], json[@"timestamp"] ? @"YES" : @"NO"];
    }];

    [self enable:@"contacts.read"];
    // Two probes: a letter almost every address book matches, and a string
    // almost none does. Counts only — no names reach the log.
    [self report:@"/v1/contacts?q=a&limit=25" shape:^NSString *(NSDictionary *json) {
        return [NSString stringWithFormat:@"%lu matches for “a”, truncated %@",
                (unsigned long) [json[@"contacts"] count], json[@"truncated"]];
    }];
    [self report:@"/v1/contacts?q=zzzznobodyzzzz" shape:^NSString *(NSDictionary *json) {
        return [NSString stringWithFormat:@"%lu matches for a nonsense name (expected 0)",
                (unsigned long) [json[@"contacts"] count]];
    }];

    [self enable:@"calendar.read"];
    [self report:@"/v1/calendar/events?days=7" shape:^NSString *(NSDictionary *json) {
        return [NSString stringWithFormat:@"%lu events in the next 7 days, truncated %@",
                (unsigned long) [json[@"events"] count], json[@"truncated"]];
    }];

    [self enable:@"reminders.read"];
    [self report:@"/v1/reminders?limit=50" shape:^NSString *(NSDictionary *json) {
        return [NSString stringWithFormat:@"%lu open reminders", (unsigned long) [json[@"reminders"] count]];
    }];

    [self enable:@"health.read"];
    [self report:@"/v1/health/activity?days=7" shape:^NSString *(NSDictionary *json) {
        return [NSString stringWithFormat:@"%lu daily rows%@",
                (unsigned long) [json[@"days"] count], json[@"note"] ? @", note present" : @""];
    }];

    NSLog(@"[dsh-report] ---- end ----");
}

/// Sends one real notification, so the tester can see whether the whole path
/// works — which is the only way to check it. When iOS has never been asked,
/// this asks (and sends nothing this run): a report that silently skips is how
/// the notification path stayed unverified in the first place.
- (void)testSendOneRealNotificationIfAllowed {
    UNAuthorizationStatus authorization = [DSHNotificationCapability authorizationStatus];
    if (authorization == UNAuthorizationStatusNotDetermined) {
        [DSHNotificationCapability requestAuthorization];
        NSLog(@"[dsh-report] notifications: asked iOS just now — answer the prompt and re-run");
        // Give the prompt time to appear while the app is still foreground.
        [NSThread sleepForTimeInterval:8];
        return;
    }
    if (authorization != UNAuthorizationStatusAuthorized) {
        NSLog(@"[dsh-report] notifications refused in iOS Settings — nothing sent");
        return;
    }
    [DSHNotificationCapability resetRateLimitForTesting];
    [self enable:@"notifications.post"];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:
                                    [NSURL URLWithString:[self.bridge.baseURLString stringByAppendingString:@"/v1/notify"]]];
    request.HTTPMethod = @"POST";
    [request setValue:[@"Bearer " stringByAppendingString:self.bridge.token] forHTTPHeaderField:@"Authorization"];
    [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    request.HTTPBody = [NSJSONSerialization dataWithJSONObject:@{
        @"title": @"DSH bridge test",
        @"body": @"If you can see this, the notify capability works end to end.",
    } options:0 error:nil];

    __block NSInteger status = 0;
    __block NSDictionary *json = nil;
    XCTestExpectation *done = [self expectationWithDescription:@"notify"];
    [[NSURLSession.sharedSession dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        status = ((NSHTTPURLResponse *) response).statusCode;
        if (data.length) json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
        [done fulfill];
    }] resume];
    [self waitForExpectations:@[done] timeout:60];
    NSLog(@"[dsh-report] /v1/notify → %ld %@", (long) status,
          status == 200 ? @"delivered — check the device" : (json[@"error"][@"message"] ?: @""));
    [DSHNotificationCapability resetRateLimitForTesting];
}

/// The bridge must be the *only* way out of the guest.
///
/// iSH registers character devices for the pasteboard and for CoreLocation and
/// mknods them world-readable at boot. DSH links that code, so until this was
/// found, any process in the guest could `cat /dev/clipboard` and get the
/// user's clipboard with no switch, no confirmation and no log entry —
/// bypassing everything this app does to gate capabilities. DSH now skips that
/// registration, and since the clipboard is no longer offered as a capability
/// at all, this node is the *only* way the guest could still reach the
/// pasteboard: the assertion matters more now, not less.
///
/// Skipping the mknod was not enough on its own: the node is a real file in
/// the guest's filesystem and survives reboots, so every install that had ever
/// run an earlier build kept its backdoor. DSH now unlinks both at boot, and
/// this is the test that caught the difference.
///
/// It asserts rather than reports — a backdoor reopening should fail the suite,
/// not print a line somebody has to notice — and deliberately does not read the
/// nodes even if they exist, because reading the pasteboard is what raises
/// iOS's paste prompt and a test has no business doing that.
- (void)testISHDeviceNodesDoNotBypassTheBridge {
    // Running a guest command before the guest exists takes the whole test host
    // down. On a device that has run DSH before, the image is already imported
    // and the harness is up within a second, so this looks unnecessary — it is
    // not: a fresh install spends its first launch importing the root
    // filesystem, and this test crashed the run on an iPhone that had never
    // seen the app.
    [self waitForHarnessReady];

    XCTestExpectation *done = [self expectationWithDescription:@"guest"];
    NSMutableString *out = [NSMutableString string];
    [ISHShellExecutor executeCommand:@"ls /dev/clipboard /dev/location 2>&1 || true"
                        lineCallback:^(NSString *line, BOOL isStdErr) {
        [out appendFormat:@"%@\n", line];
    } completion:^(ISHShellExecutionResult *result) {
        [done fulfill];
    }];
    [self waitForExpectations:@[done] timeout:120];
    NSLog(@"[dsh-report] iSH device nodes in the guest: %@",
          [out stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceAndNewlineCharacterSet]);

    // `ls` prints a path only when it exists, so any bare path here is a node
    // that is still reachable from the guest.
    XCTAssertFalse([out containsString:@"/dev/clipboard"] && ![out containsString:@"clipboard: No such"],
                   @"/dev/clipboard is still there, and it bypasses every capability gate:\n%@", out);
    XCTAssertFalse([out containsString:@"/dev/location"] && ![out containsString:@"location: No such"],
                   @"/dev/location is still there, and it bypasses every capability gate:\n%@", out);
}

/// Removing the nodes is the visible half of that fix. The load-bearing half is
/// that the drivers are never registered: dyn_open answers ENXIO for a minor
/// with no dev_ops behind it, so a guest that recreates the node itself — which
/// it can, mknod writes a real file into the image — still opens nothing. This
/// asserts the half that a later change is more likely to undo by accident.
- (void)testRecreatingTheDeviceNodesGetsTheGuestNothing {
    [self waitForHarnessReady];

    XCTestExpectation *done = [self expectationWithDescription:@"mknod"];
    NSMutableString *out = [NSMutableString string];
    NSString *command = @"mknod /tmp/clip c 240 0 2>/dev/null; "
                        @"mknod /tmp/loc c 240 1 2>/dev/null; "
                        @"for n in clip loc; do "
                        @"  cat /tmp/$n >/dev/null 2>&1; echo \"READ-$n:$?\"; "
                        @"done; rm -f /tmp/clip /tmp/loc";
    [ISHShellExecutor executeCommand:command lineCallback:^(NSString *line, BOOL isStdErr) {
        [out appendFormat:@"%@\n", line];
    } completion:^(ISHShellExecutionResult *result) {
        [done fulfill];
    }];
    [self waitForExpectations:@[done] timeout:120];
    NSLog(@"[dsh-report] recreated dyn-dev nodes: %@",
          [out stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceAndNewlineCharacterSet]);

    // Assert the markers arrived before asserting what they say: every check
    // below is a negative, and a command that produced no output at all would
    // satisfy all of them without testing anything.
    for (NSString *name in @[@"clip", @"loc"]) {
        NSString *marker = [NSString stringWithFormat:@"READ-%@:", name];
        XCTAssertTrue([out containsString:marker],
                      @"no result for the %@ node — the probe did not run:\n%@", name, out);
    }
    XCTAssertFalse([out containsString:@"READ-clip:0"],
                   @"a recreated clipboard node was readable:\n%@", out);
    XCTAssertFalse([out containsString:@"READ-loc:0"],
                   @"a recreated location node was readable:\n%@", out);
}

@end

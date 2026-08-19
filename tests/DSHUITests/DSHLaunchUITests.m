//
//  DSHLaunchUITests.m
//  DSHUITests
//
//  End-to-end checks on a real device/simulator: the app boots the Linux
//  guest, dsh-serve comes up, the WKWebView shows the DeepSeek Harness UI,
//  and the native controls (terminal, log, menu) work.
//

#import <XCTest/XCTest.h>

static const NSTimeInterval kBootTimeout = 300;   // first launch imports the rootfs

@interface DSHLaunchUITests : XCTestCase
@property (nonatomic) XCUIApplication *app;
@end

@implementation DSHLaunchUITests

- (void)setUp {
    self.continueAfterFailure = NO;
    self.app = [[XCUIApplication alloc] init];
    [self.app launch];
}

- (void)attachScreenshot:(NSString *)name {
    XCTAttachment *att = [XCTAttachment attachmentWithScreenshot:[XCUIScreen.mainScreen screenshot]];
    att.name = name;
    att.lifetime = XCTAttachmentLifetimeKeepAlways;
    [self addAttachment:att];
}

/// Waits until the harness overlay is gone (server answered and page loaded).
- (void)waitForHarnessReady {
    XCUIElement *overlay = self.app.staticTexts[@"dsh.overlay.message"];
    XCUIElement *dot = self.app.otherElements[@"dsh.statusdot"];
    NSPredicate *gone = [NSPredicate predicateWithFormat:@"exists == NO OR hittable == NO"];
    XCTestExpectation *e = [self expectationForPredicate:gone evaluatedWithObject:overlay handler:nil];
    [self waitForExpectations:@[e] timeout:kBootTimeout];
    if (dot.exists)
        XCTAssertEqualObjects(dot.value, @"ready", @"status dot should report ready");
}

- (void)testHarnessBootsAndShowsWebUI {
    // While starting, the overlay shows a progress bar and an elapsed/ETA line.
    XCUIElement *progress = self.app.progressIndicators[@"dsh.overlay.progress"];
    XCUIElement *elapsed = self.app.staticTexts[@"dsh.overlay.elapsed"];
    if ([progress waitForExistenceWithTimeout:5]) {
        XCTAssertTrue([elapsed waitForExistenceWithTimeout:5]);
        NSPredicate *hasEta = [NSPredicate predicateWithFormat:@"label CONTAINS 'elapsed'"];
        XCTestExpectation *e = [self expectationForPredicate:hasEta evaluatedWithObject:elapsed handler:nil];
        [self waitForExpectations:@[e] timeout:10];
    }
    [self attachScreenshot:@"01-launch"];
    [self waitForHarnessReady];
    [self attachScreenshot:@"02-ready"];

    XCUIElement *web = self.app.webViews.firstMatch;
    XCTAssertTrue([web waitForExistenceWithTimeout:30], @"web view should exist");

    // The DSH web app renders a sidebar with a "New Session" button (or the
    // first-run notice with a Continue button) once its client bundle ran.
    NSPredicate *uiUp = [NSPredicate predicateWithFormat:@"exists == YES"];
    XCUIElementQuery *markers = [[web descendantsMatchingType:XCUIElementTypeAny]
        matchingPredicate:[NSPredicate predicateWithFormat:@"label CONTAINS[c] 'New Session' OR label CONTAINS[c] 'Continue' OR label CONTAINS[c] 'DeepSeek'"]];
    XCTestExpectation *e = [self expectationForPredicate:uiUp evaluatedWithObject:markers.firstMatch handler:nil];
    [self waitForExpectations:@[e] timeout:90];
    [self attachScreenshot:@"03-web-ui"];

    // Title shows the port the server listens on.
    XCUIElement *title = self.app.staticTexts[@"dsh.title"];
    XCTAssertTrue(title.exists);
    XCTAssertTrue([title.label containsString:@":30"], @"title should show the port, got %@", title.label);
}

- (void)testServerLogIsReachableFromMenu {
    [self waitForHarnessReady];
    XCUIElement *menu = self.app.buttons[@"dsh.menu"];
    XCTAssertTrue([menu waitForExistenceWithTimeout:10]);
    [menu tap];
    XCUIElement *logItem = self.app.buttons[@"Server Log"];
    XCTAssertTrue([logItem waitForExistenceWithTimeout:5], @"menu should list Server Log");
    [logItem tap];
    XCUIElement *logView = self.app.textViews[@"dsh.logview"];
    XCTAssertTrue([logView waitForExistenceWithTimeout:10]);
    NSString *text = (NSString *) logView.value;
    XCTAssertTrue([text containsString:@"server answered"], @"log should record readiness, got: %@", text);
    XCTAssertTrue([text containsString:@"dsh web: http://127.0.0.1:"], @"log should carry dsh's own banner, got: %@", text);
    [self attachScreenshot:@"04-log"];
    [self.app.buttons[@"Done"] tap];
}

/// The capabilities screen is the only way a user can turn a bridge capability
/// on, so the switch has to be reachable, honest about what it grants, and
/// actually persisted.
- (void)testCapabilitiesScreenTogglesHealth {
    [self waitForHarnessReady];
    XCUIElement *menu = self.app.buttons[@"dsh.menu"];
    XCTAssertTrue([menu waitForExistenceWithTimeout:10]);
    [menu tap];
    XCUIElement *item = self.app.buttons[@"Capabilities"];
    XCTAssertTrue([item waitForExistenceWithTimeout:5], @"menu should list Capabilities");
    [item tap];

    XCUIElement *table = self.app.tables[@"dsh.capabilities"];
    XCTAssertTrue([table waitForExistenceWithTimeout:10]);
    XCUIElement *health = self.app.switches[@"dsh.capability.switch.health.read"];
    XCTAssertTrue([health waitForExistenceWithTimeout:10], @"Apple Health should be listed");
    XCTAssertEqualObjects(health.value, @"0", @"capabilities ship off");
    [self attachScreenshot:@"05-capabilities"];

    [health tap];
    // Turning one on names what is being handed over before it takes effect.
    XCUIElement *allow = self.app.alerts.buttons[@"Allow"];
    XCTAssertTrue([allow waitForExistenceWithTimeout:5], @"enabling should ask first");
    [allow tap];
    NSPredicate *on = [NSPredicate predicateWithFormat:@"value == '1'"];
    [self waitForExpectations:@[[self expectationForPredicate:on evaluatedWithObject:health handler:nil]] timeout:10];

    // And back off, so the suite leaves the device as it found it.
    [health tap];
    NSPredicate *off = [NSPredicate predicateWithFormat:@"value == '0'"];
    [self waitForExpectations:@[[self expectationForPredicate:off evaluatedWithObject:health handler:nil]] timeout:10];
    [self.app.buttons[@"Done"] tap];
}

- (void)testLandscapeKeepsWebViewAndBar {
    [self waitForHarnessReady];
    XCUIDevice.sharedDevice.orientation = UIDeviceOrientationLandscapeLeft;
    sleep(2);
    XCUIElement *web = self.app.webViews.firstMatch;
    XCTAssertTrue([web waitForExistenceWithTimeout:10]);
    CGRect frame = web.frame;
    XCTAssertGreaterThan(frame.size.width, frame.size.height, @"web view should be wider than tall in landscape (%@)", NSStringFromCGRect(frame));
    XCTAssertTrue(self.app.buttons[@"dsh.menu"].isHittable, @"control bar stays reachable in landscape");
    [self attachScreenshot:@"06-landscape"];
    XCUIDevice.sharedDevice.orientation = UIDeviceOrientationPortrait;
    sleep(1);
    XCTAssertTrue(self.app.webViews.firstMatch.exists);
}

- (void)testTerminalOpensAndDismisses {
    [self waitForHarnessReady];
    XCUIElement *terminal = self.app.buttons[@"dsh.terminal"];
    XCTAssertTrue([terminal waitForExistenceWithTimeout:10]);
    [terminal tap];
    // The iSH terminal is an hterm web view inside a sheet.
    XCUIElement *termWeb = [self.app.webViews elementBoundByIndex:1];
    XCTAssertTrue([termWeb waitForExistenceWithTimeout:20], @"terminal sheet should present a second web view");
    sleep(3);
    [self attachScreenshot:@"05-terminal"];
    // Swipe the sheet down to dismiss; the main web view is still there.
    [termWeb swipeDown];
    sleep(1);
    XCTAssertTrue(self.app.webViews.firstMatch.exists);
}

@end

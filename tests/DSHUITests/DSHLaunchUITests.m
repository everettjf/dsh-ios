#import <XCTest/XCTest.h>

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
    XCTAttachment *attachment = [XCTAttachment attachmentWithScreenshot:XCUIScreen.mainScreen.screenshot];
    attachment.name = name;
    attachment.lifetime = XCTAttachmentLifetimeKeepAlways;
    [self addAttachment:attachment];
}

- (void)testNativeAgentLaunchesImmediatelyWithoutWebHarness {
    XCTAssertTrue([self.app.navigationBars[@"DeepSeek"] waitForExistenceWithTimeout:5]);
    XCTAssertTrue([self.app.buttons[@"dsh.native.settings"] waitForExistenceWithTimeout:2]);
    XCTAssertTrue([self.app.textFields[@"dsh.native.composer"] waitForExistenceWithTimeout:2]);
    XCTAssertTrue([self.app.buttons[@"dsh.native.attach"] waitForExistenceWithTimeout:2]);
    XCTAssertEqual(self.app.webViews.count, 0u, @"the primary agent UI must be native");
    XCTAssertFalse(self.app.staticTexts[@"dsh.overlay.message"].exists, @"launch must not wait for Linux");
    [self attachScreenshot:@"01-native-agent"];
}

- (void)testSettingsExposeEndpointKeyAndModel {
    [self.app.buttons[@"dsh.native.settings"] tap];
    XCTAssertTrue([self.app.navigationBars[@"Agent Settings"] waitForExistenceWithTimeout:3]);
    XCTAssertTrue(self.app.textFields[@"dsh.native.endpoint"].exists);
    XCTAssertTrue(self.app.secureTextFields[@"dsh.native.apikey"].exists);
    XCTAssertTrue(self.app.textFields[@"dsh.native.model"].exists);
    XCTAssertTrue(self.app.buttons[@"dsh.native.settings.save"].isHittable);
    [self attachScreenshot:@"02-settings"];
    [self.app.buttons[@"Cancel"] tap];
}

- (void)testBlankComposerKeepsSendDisabled {
    XCUIElement *send = self.app.buttons[@"dsh.native.send"];
    XCTAssertTrue([send waitForExistenceWithTimeout:3]);
    XCTAssertFalse(send.isEnabled);
    XCUIElement *composer = self.app.textFields[@"dsh.native.composer"];
    [composer tap];
    [composer typeText:@"Hello"];
    XCTAssertTrue(send.isEnabled);
}

- (void)testNewConversationControlIsReachable {
    XCUIElement *newSession = self.app.buttons[@"dsh.native.new-session"];
    XCTAssertTrue([newSession waitForExistenceWithTimeout:3]);
    XCTAssertTrue(newSession.isHittable);
    [newSession tap];
    XCTAssertTrue(self.app.otherElements[@"dsh.native.empty"].exists ||
                  self.app.staticTexts[@"DeepSeek Agent"].exists);
}

- (void)testConversationBrowserIsNativeAndCanCreateSession {
    XCUIElement *conversations = self.app.buttons[@"dsh.native.sessions"];
    XCTAssertTrue([conversations waitForExistenceWithTimeout:3]);
    [conversations tap];
    XCTAssertTrue([self.app.navigationBars[@"Conversations"] waitForExistenceWithTimeout:3]);
    XCTAssertTrue(self.app.staticTexts[@"No Conversations"].exists || self.app.buttons[@"New"].exists);
    XCTAssertEqual(self.app.webViews.count, 0u);
    [self.app.buttons[@"New"] tap];
    XCTAssertTrue([self.app.navigationBars[@"DeepSeek"] waitForExistenceWithTimeout:3]);
}

- (void)testLandscapeKeepsNativeControlsReachable {
    XCUIDevice.sharedDevice.orientation = UIDeviceOrientationLandscapeLeft;
    sleep(1);
    XCTAssertTrue(self.app.buttons[@"dsh.native.settings"].isHittable);
    XCTAssertTrue(self.app.textFields[@"dsh.native.composer"].isHittable);
    XCTAssertEqual(self.app.webViews.count, 0u);
    [self attachScreenshot:@"03-landscape"];
    XCUIDevice.sharedDevice.orientation = UIDeviceOrientationPortrait;
}

- (void)testOpeningSettingsDoesNotStartGuest {
    [self.app.buttons[@"dsh.native.settings"] tap];
    XCTAssertTrue([self.app.navigationBars[@"Agent Settings"] waitForExistenceWithTimeout:3]);
    XCTAssertFalse(self.app.staticTexts[@"Preparing the Linux environment…"].exists);
    XCTAssertFalse(self.app.progressIndicators[@"dsh.overlay.progress"].exists);
}

@end

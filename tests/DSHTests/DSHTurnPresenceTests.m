//
//  DSHTurnPresenceTests.m
//  DSHTests
//
//  A turn does not survive the app being suspended. These are about the two
//  things DSH can honestly do about that: hold the extra seconds iOS grants on
//  the way out, and explain the stall on the way back.
//

#import <XCTest/XCTest.h>
#import <UIKit/UIKit.h>
#import "DSHTurnPresence.h"
#import "DSHActivityLog.h"

@interface DSHTurnPresenceTests : XCTestCase
@end

@implementation DSHTurnPresenceTests

- (void)setUp {
    [super setUp];
    [DSHActivityLog.shared resetForTesting];
    [DSHTurnPresence.shared start];
    [DSHTurnPresence.shared resetForTesting];
}

- (void)tearDown {
    [DSHActivityLog.shared resetForTesting];
    [super tearDown];
}

- (void)recordGuestToolCall {
    [DSHActivityLog.shared recordSource:DSHActivitySourceGuestTool
                                   name:@"bash"
                                 detail:@"sleep 30"
                                 result:nil
                                outcome:DSHActivityOutcomeOK
                               duration:0];
    // The log posts its change notification on the main queue.
    [self waitForMainQueue];
}

- (void)waitForMainQueue {
    XCTestExpectation *drained = [self expectationWithDescription:@"main queue"];
    dispatch_async(dispatch_get_main_queue(), ^{ [drained fulfill]; });
    [self waitForExpectations:@[drained] timeout:5];
}

/// A shell command in the guest is a turn in progress. Only capability calls
/// light the privacy indicator, but for this question the guest counts too —
/// the agent grinding through `npm install` is exactly the case that dies.
- (void)testGuestActivityCountsAsWorking {
    XCTAssertFalse(DSHTurnPresence.shared.isWorking, @"nothing has happened yet");
    [self recordGuestToolCall];
    XCTAssertTrue(DSHTurnPresence.shared.isWorking, @"a guest tool call is a turn in progress");
}

/// Leaving while idle must not claim a turn was interrupted, or the notice
/// means nothing the first time it is true.
- (void)testLeavingWhileIdleSaysNothingOnTheWayBack {
    __block BOOL notified = NO;
    id token = [NSNotificationCenter.defaultCenter addObserverForName:DSHTurnWasInterruptedNotification
                                                               object:nil queue:nil
                                                           usingBlock:^(NSNotification *n) { notified = YES; }];

    [NSNotificationCenter.defaultCenter postNotificationName:UIApplicationDidEnterBackgroundNotification object:nil];
    XCTAssertFalse(DSHTurnPresence.shared.leftMidTurn);
    [NSNotificationCenter.defaultCenter postNotificationName:UIApplicationDidBecomeActiveNotification object:nil];
    [self waitForMainQueue];

    XCTAssertFalse(notified, @"an idle app that went away has nothing to explain");
    [NSNotificationCenter.defaultCenter removeObserver:token];
}

- (void)testLeavingMidTurnIsExplainedOnTheWayBack {
    [self recordGuestToolCall];

    XCTestExpectation *interrupted = [self expectationForNotification:DSHTurnWasInterruptedNotification
                                                               object:nil handler:nil];
    [NSNotificationCenter.defaultCenter postNotificationName:UIApplicationDidEnterBackgroundNotification object:nil];
    XCTAssertTrue(DSHTurnPresence.shared.leftMidTurn, @"the app left while the agent was working");
    [NSNotificationCenter.defaultCenter postNotificationName:UIApplicationDidBecomeActiveNotification object:nil];

    [self waitForExpectations:@[interrupted] timeout:5];
    XCTAssertFalse(DSHTurnPresence.shared.leftMidTurn, @"said once, not on every return after");
}

/// Coming back a second time must be silent — the notice belongs to the trip
/// that interrupted something, not to every foreground after it.
- (void)testTheNoticeIsNotRepeatedOnTheNextReturn {
    [self recordGuestToolCall];
    [NSNotificationCenter.defaultCenter postNotificationName:UIApplicationDidEnterBackgroundNotification object:nil];
    [NSNotificationCenter.defaultCenter postNotificationName:UIApplicationDidBecomeActiveNotification object:nil];
    [self waitForMainQueue];

    __block BOOL notifiedAgain = NO;
    id token = [NSNotificationCenter.defaultCenter addObserverForName:DSHTurnWasInterruptedNotification
                                                               object:nil queue:nil
                                                           usingBlock:^(NSNotification *n) { notifiedAgain = YES; }];
    [NSNotificationCenter.defaultCenter postNotificationName:UIApplicationDidBecomeActiveNotification object:nil];
    [self waitForMainQueue];
    XCTAssertFalse(notifiedAgain);
    [NSNotificationCenter.defaultCenter removeObserver:token];
}

@end

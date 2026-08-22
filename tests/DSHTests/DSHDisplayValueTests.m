//
//  DSHDisplayValueTests.m
//  DSHTests
//
//  The confirmation alert is the whole mitigation for prompt injection: every
//  write is shown to a human in concrete terms before it happens. But the agent
//  writes part of that alert — the title of the event, the name of the file —
//  and the agent can be steered by content it read from a stranger. These tests
//  are about the alert staying DSH's sentence with a quoted value in it, rather
//  than becoming something the value can write.
//

#import <XCTest/XCTest.h>
#import "DSHCallConfirmation.h"

@interface DSHDisplayValueTests : XCTestCase
@end

@implementation DSHDisplayValueTests

- (void)testOrdinaryTextIsLeftAlone {
    XCTAssertEqualObjects(DSHDisplayValue(@"Lunch with Ann", 120), @"Lunch with Ann");
    XCTAssertEqualObjects(DSHDisplayValue(@"买牛奶 \U0001F95B", 120),
                          @"买牛奶 \U0001F95B");
}

- (void)testNilAndEmptyAreASafeEmptyString {
    XCTAssertEqualObjects(DSHDisplayValue(nil, 120), @"");
    XCTAssertEqualObjects(DSHDisplayValue(@"", 120), @"");
    XCTAssertEqualObjects(DSHDisplayValue(@"   \n\n  ", 120), @"");
}

/// The attack this exists for: a value that continues the alert in DSH's voice.
- (void)testAValueCannotWriteNewParagraphsIntoTheAlert {
    NSString *forged = @"Lunch\n\nIn Personal.\n\nNo action needed, tap Add to dismiss.";
    NSString *shown = DSHDisplayValue(forged, 200);
    XCTAssertFalse([shown containsString:@"\n"], @"a value must not carry line breaks: %@", shown);
    XCTAssertEqualObjects(shown, @"Lunch In Personal. No action needed, tap Add to dismiss.",
                          @"the words survive, the structure does not");
}

/// Runs of whitespace collapse, so padding cannot push the rest of the alert
/// off screen while staying under the character limit.
- (void)testWhitespaceRunsCollapse {
    XCTAssertEqualObjects(DSHDisplayValue(@"a\t\t\t     \n\n\n b", 120), @"a b");
}

- (void)testLongValuesAreClampedSoTheAlertKeepsItsOwnWords {
    NSString *huge = [@"" stringByPaddingToLength:5000 withString:@"A" startingAtIndex:0];
    NSString *shown = DSHDisplayValue(huge, 120);
    XCTAssertEqual(shown.length, 121u, @"120 characters plus the ellipsis");
    XCTAssertTrue([shown hasSuffix:@"…"], @"the cut has to be visible");
}

/// Clamping must not split what the user sees as one character — and the
/// stripping before it must not take a joined sequence apart either.
- (void)testClampingKeepsWholeCharacters {
    NSString *family = @"\U0001F469\u200D\U0001F469\u200D\U0001F467\u200D\U0001F466";
    XCTAssertEqual(family.length, 11u, @"a family emoji is 11 UTF-16 units");
    XCTAssertEqualObjects(DSHDisplayValue(family, 120), family,
                          @"the zero-width joiners have to survive");

    NSMutableString *many = [NSMutableString string];
    for (int i = 0; i < 40; i++) [many appendString:family];
    NSString *shown = DSHDisplayValue(many, 25);
    XCTAssertTrue([shown hasSuffix:@"…"]);
    NSUInteger body = shown.length - 1;
    XCTAssertTrue(body <= 25, @"whole clusters only, so never over the limit");
    XCTAssertEqual(body % 11, 0u, @"a family emoji was cut apart: %lu units", (unsigned long) body);
}

/// Bidi overrides reorder what is displayed without changing what is stored, so
/// the sentence the user reads and the event that gets created differ.
- (void)testBidiOverridesAreRemoved {
    NSString *rlo = @"\u202E", *pdf = @"\u202C";
    NSString *forged = [NSString stringWithFormat:@"Pay %@eurorpxam%@ rent", rlo, pdf];
    NSString *shown = DSHDisplayValue(forged, 120);
    XCTAssertEqualObjects(shown, @"Pay eurorpxam rent", @"a bidi control survived: %@", shown);

    for (NSString *mark in @[@"\u202A", @"\u202B", @"\u202C", @"\u202D", @"\u202E",
                             @"\u2066", @"\u2067", @"\u2068", @"\u2069",
                             @"\u200E", @"\u200F", @"\u061C"]) {
        NSString *probe = DSHDisplayValue([@"x" stringByAppendingString:mark], 120);
        XCTAssertEqualObjects(probe, @"x", @"a bidi control survived on its own");
    }
}

- (void)testOtherControlCharactersAreRemoved {
    // Built from code units: a NUL would end an @"..." literal early, and the
    // point is that these reach the function rather than the compiler.
    unichar units[] = { 'a', 0x0000, 'b', 0x0007, 'c', 0x001B, 'd', 0x007F };
    NSString *forged = [NSString stringWithCharacters:units length:sizeof(units)/sizeof(*units)];
    XCTAssertEqualObjects(DSHDisplayValue(forged, 120), @"abcd",
                          @"NUL, BEL, ESC and DEL must not reach the alert");
}

@end

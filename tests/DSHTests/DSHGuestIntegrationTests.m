//
//  DSHGuestIntegrationTests.m
//  DSHTests
//
//  Runs inside the DSH host app (device or simulator) and talks to the real
//  Linux guest: waits for the supervised dsh-serve to answer, fetches the web
//  UI, and executes the guest-side self test through ISHShellExecutor.
//

#import <XCTest/XCTest.h>
#import "DSHHarness.h"
#import "ISHShellExecutor.h"
#import "DSHRootUpgrader.h"

@interface DSHGuestIntegrationTests : XCTestCase
@end

@implementation DSHGuestIntegrationTests

- (void)waitForReady {
    DSHHarness *h = DSHHarness.shared;
    if (h.state == DSHHarnessStateReady)
        return;
    XCTestExpectation *ready = [self expectationForNotification:DSHHarnessStateDidChangeNotification object:h handler:^BOOL(NSNotification *n) {
        return h.state == DSHHarnessStateReady;
    }];
    [self waitForExpectations:@[ready] timeout:300];
}

- (void)testHarnessServesWebUI {
    [self waitForReady];
    DSHHarness *h = DSHHarness.shared;
    XCTAssertEqual(h.state, DSHHarnessStateReady);
    XCTAssertNotNil(h.baseURL);
    XCTAssertGreaterThan(h.guestPid, 0);

    XCTestExpectation *fetched = [self expectationWithDescription:@"index"];
    [[NSURLSession.sharedSession dataTaskWithURL:h.baseURL completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        XCTAssertNil(error);
        XCTAssertEqual(((NSHTTPURLResponse *) response).statusCode, 200);
        NSString *html = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
        XCTAssertTrue([html containsString:@"__DSH_BOOT__"], @"index should carry the DSH boot manifest");
        [fetched fulfill];
    }] resume];
    [self waitForExpectations:@[fetched] timeout:30];
}

- (void)testGuestSelfTestPasses {
    [self waitForReady];
    XCTestExpectation *done = [self expectationWithDescription:@"selftest"];
    NSMutableString *out = [NSMutableString string];
    int pid = [ISHShellExecutor executeCommand:@"/usr/local/bin/dsh-selftest 2>&1"
                                  lineCallback:^(NSString *line, BOOL isStdErr) { [out appendFormat:@"%@\n", line]; }
                                    completion:^(ISHShellExecutionResult *result) {
        XCTAssertEqual(result.error, ISHShellExecutorErrorNone);
        XCTAssertEqual(result.exitCode, 0, @"dsh-selftest failed:\n%@\nstdout:%@\nstderr:%@", out, result.output, result.errorOutput);
        XCTAssertTrue([out containsString:@"SELFTEST OK"], @"output: %@", out);
        [done fulfill];
    }];
    XCTAssertGreaterThan(pid, 0);
    [self waitForExpectations:@[done] timeout:180];
}

- (void)testBundledRootImageIsTheInstalledOne {
    // After launch the imported root must match the image in the bundle and
    // no user-data migration may be left pending.
    DSHRootUpgrader *u = DSHRootUpgrader.shared;
    XCTAssertNotNil(u.bundledRootHash, @"root.tar.gz.sha256 must be in the bundle");
    XCTAssertEqualObjects(u.installedRootHash, u.bundledRootHash);
    [self waitForReady];
    XCTAssertNil(u.pendingMigrationRoot);
    // The guest carries the marker the rootfs build wrote for the RootfsPatch overlay.
    XCTestExpectation *done = [self expectationWithDescription:@"overlay"];
    NSMutableString *out = [NSMutableString string];
    [ISHShellExecutor executeCommand:@"cat /ish/overlay-version" lineCallback:^(NSString *line, BOOL isStdErr) {
        [out appendString:line];
    } completion:^(ISHShellExecutionResult *result) {
        XCTAssertEqual(result.exitCode, 0);
        XCTAssertTrue(out.intValue >= 4, @"overlay version %@", out);
        [done fulfill];
    }];
    [self waitForExpectations:@[done] timeout:60];
}

- (void)testGuestNodeAndDshVersions {
    [self waitForReady];
    XCTestExpectation *done = [self expectationWithDescription:@"versions"];
    NSMutableString *out = [NSMutableString string];
    [ISHShellExecutor executeCommand:@"node -v; dsh --version" lineCallback:^(NSString *line, BOOL isStdErr) {
        if (![line containsString:@"expose_wasm"]) [out appendFormat:@"%@\n", line];
    } completion:^(ISHShellExecutionResult *result) {
        XCTAssertEqual(result.exitCode, 0);
        XCTAssertTrue([out containsString:@"v22."], @"node 22 expected: %@", out);
        XCTAssertTrue([out containsString:@"0.1."], @"dsh 0.1.x expected: %@", out);
        [done fulfill];
    }];
    [self waitForExpectations:@[done] timeout:120];
}

@end

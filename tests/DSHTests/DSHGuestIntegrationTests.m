//
//  DSHGuestIntegrationTests.m
//  DSHTests
//
//  Runs inside the DSH host app (device or simulator) and talks to the real
//  Linux guest: waits for the supervised dsh-serve to answer, fetches the web
//  UI, and executes the guest-side self test through ISHShellExecutor.
//

#import <XCTest/XCTest.h>
#import <UIKit/UIKit.h>
#import "DSHHarness.h"
#import "ISHShellExecutor.h"
#import "DSHRootUpgrader.h"
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import <HealthKit/HealthKit.h>
#import "DSHMockLLMServer.h"
#import "DSHBootCoordinator.h"
#import "DSHGuestRuntime.h"

@interface DSHGuestIntegrationTests : XCTestCase
@end

@implementation DSHGuestIntegrationTests

- (void)waitForReady {
    DSHBootCoordinator *boot = DSHBootCoordinator.shared;
    if (boot.phase != DSHBootPhaseReady) {
        XCTestExpectation *booted = [self expectationForNotification:DSHBootStateDidChangeNotification object:boot handler:^BOOL(NSNotification *n) {
            return boot.phase == DSHBootPhaseReady || boot.phase == DSHBootPhaseFailed;
        }];
        [boot start];
        [self waitForExpectations:@[booted] timeout:300];
        XCTAssertEqual(boot.phase, DSHBootPhaseReady, @"guest boot failed: %@", boot.statusMessage);
    }
    DSHHarness *h = DSHHarness.shared;
    if (h.state == DSHHarnessStateReady)
        return;
    XCTestExpectation *ready = [self expectationForNotification:DSHHarnessStateDidChangeNotification object:h handler:^BOOL(NSNotification *n) {
        return h.state == DSHHarnessStateReady;
    }];
    [h start];
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

- (void)testBinaryDataStreamsIntoGuestWithoutEnteringCommandArguments {
    [self waitForReady];
    NSMutableData *payload = [NSMutableData dataWithLength:1024 * 1024];
    uint8_t *bytes = payload.mutableBytes;
    for (NSUInteger index = 0; index < payload.length; index++) bytes[index] = (uint8_t)(index % 251);
    NSString *path = [NSString stringWithFormat:@"/root/workspace/attachments/%@", NSUUID.UUID.UUIDString];
    XCTestExpectation *written = [self expectationWithDescription:@"binary attachment written"];
    [DSHGuestRuntime writeData:payload toPath:path timeout:60 completion:^(NSData *jsonData) {
        NSDictionary *result = [NSJSONSerialization JSONObjectWithData:jsonData options:0 error:nil];
        XCTAssertEqual([result[@"exit_code"] integerValue], 0, @"write failed: %@", result);
        [written fulfill];
    }];
    [self waitForExpectations:@[written] timeout:90];

    NSString *command = [NSString stringWithFormat:
        @"bytes=$(wc -c < '%@'); rm -f '%@'; [ \"$bytes\" -eq %lu ]",
        path, path, (unsigned long)payload.length];
    XCTestExpectation *verified = [self expectationWithDescription:@"binary attachment verified"];
    [ISHShellExecutor executeCommand:command lineCallback:nil completion:^(ISHShellExecutionResult *result) {
        XCTAssertEqual(result.exitCode, 0, @"binary payload size mismatch: %@ %@", result.output, result.errorOutput);
        [verified fulfill];
    }];
    [self waitForExpectations:@[verified] timeout:60];
}

- (void)testBundledRootImageIsTheInstalledOne {
    // After launch the imported root must match the image in the bundle and
    // no user-data migration may be left pending.
    // The import runs in the background now, so wait for the guest to be up
    // before asking which image is installed.
    [self waitForReady];
    DSHRootUpgrader *u = DSHRootUpgrader.shared;
    XCTAssertNotNil(u.bundledRootHash, @"root.tar.gz.sha256 must be in the bundle");
    XCTAssertEqualObjects(u.installedRootHash, u.bundledRootHash);
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

/// The real end-to-end path: the guest reaches the app's bridge over loopback
/// and gets this device's facts back.
- (void)testGuestReachesTheHostBridge {
    [self waitForReady];
    DSHHostBridge *bridge = DSHHostBridge.shared;
    XCTAssertTrue(bridge.running, @"the bridge should be listening once the harness started");
    XCTAssertNotNil(bridge.baseURLString);

    NSString *command = [NSString stringWithFormat:
        @"node -e \"fetch('%@/v1/device',{headers:{authorization:'Bearer %@'}})"
        @".then(r=>r.text()).then(t=>console.log('BRIDGE:'+t))"
        @".catch(e=>console.log('BRIDGE-ERR:'+e.message))\" 2>&1",
        bridge.baseURLString, bridge.token];
    XCTestExpectation *done = [self expectationWithDescription:@"bridge"];
    NSMutableString *out = [NSMutableString string];
    [ISHShellExecutor executeCommand:command lineCallback:^(NSString *line, BOOL isStdErr) {
        if (![line containsString:@"expose_wasm"]) [out appendFormat:@"%@\n", line];
    } completion:^(ISHShellExecutionResult *result) {
        XCTAssertEqual(result.exitCode, 0, @"guest fetch failed: %@", out);
        XCTAssertTrue([out containsString:@"BRIDGE:"], @"no bridge answer: %@", out);
        XCTAssertTrue([out containsString:@"systemVersion"], @"unexpected payload: %@", out);
        XCTAssertTrue([out containsString:UIDevice.currentDevice.systemVersion],
                      @"the guest should see this device's iOS version: %@", out);
        [done fulfill];
    }];
    [self waitForExpectations:@[done] timeout:180];
}

/// A guest process without the token must be refused, so the bridge is not an
/// open door for anything else running in the Linux image.
- (void)testGuestWithoutTokenIsRefusedByTheBridge {
    [self waitForReady];
    DSHHostBridge *bridge = DSHHostBridge.shared;
    NSString *command = [NSString stringWithFormat:
        @"node -e \"fetch('%@/v1/device').then(r=>console.log('STATUS:'+r.status))"
        @".catch(e=>console.log('ERR:'+e.message))\" 2>&1", bridge.baseURLString];
    XCTestExpectation *done = [self expectationWithDescription:@"unauthorized"];
    NSMutableString *out = [NSMutableString string];
    [ISHShellExecutor executeCommand:command lineCallback:^(NSString *line, BOOL isStdErr) {
        if (![line containsString:@"expose_wasm"]) [out appendFormat:@"%@\n", line];
    } completion:^(ISHShellExecutionResult *result) {
        XCTAssertTrue([out containsString:@"STATUS:401"], @"expected 401, got: %@", out);
        [done fulfill];
    }];
    [self waitForExpectations:@[done] timeout:180];
}

/// dsh must have been handed the bridge coordinates, otherwise the plugin
/// registers no tools.
- (void)testHarnessEnvironmentCarriesBridgeCoordinates {
    [self waitForReady];
    NSDictionary *env = DSHHarness.shared.extraEnvironment;
    XCTAssertEqualObjects(env[@"DSH_HOST_BRIDGE_URL"], DSHHostBridge.shared.baseURLString);
    XCTAssertEqualObjects(env[@"DSH_HOST_BRIDGE_TOKEN"], DSHHostBridge.shared.token);
}

/// The whole path, on this device, with no network: an in-app mock model asks
/// for `device_info`, the guest plugin calls the app's bridge, and this
/// device's real facts come back to the model.
- (void)testAgentCallsDeviceInfoThroughTheBridge {
    [self waitForReady];
    DSHMockLLMServer *model = [DSHMockLLMServer new];
    XCTAssertNotNil(model, @"mock model server should bind a port");
    model.requestTool = @"device_info";

    DSHHostBridge *bridge = DSHHostBridge.shared;
    // A fresh guest process does not inherit dsh-serve's environment, so pass
    // the bridge coordinates (and the mock model) explicitly.
    NSString *command = [NSString stringWithFormat:
        @"cd /root/workspace && HOME=/root DEEPSEEK_API_KEY=test DEEPSEEK_BASE_URL=%@ "
        @"DSH_HOST_BRIDGE_URL=%@ DSH_HOST_BRIDGE_TOKEN=%@ "
        @"node --expose-internals /usr/local/lib/node_modules/@deepseek-ai/dsh/lib/bin.js "
        @"--profile headless 'What device is this?' 2>&1 | tail -20",
        model.baseURLString, bridge.baseURLString, bridge.token];

    XCTestExpectation *done = [self expectationWithDescription:@"agent"];
    NSMutableString *out = [NSMutableString string];
    [ISHShellExecutor executeCommand:command lineCallback:^(NSString *line, BOOL isStdErr) {
        if (![line containsString:@"expose_wasm"]) [out appendFormat:@"%@\n", line];
    } completion:^(ISHShellExecutionResult *result) {
        [done fulfill];
    }];
    [self waitForExpectations:@[done] timeout:300];
    [model stop];

    XCTAssertGreaterThanOrEqual(model.requestCount, 2u, @"the harness should have called the model at least twice");
    BOOL offered = NO;
    for (NSString *tools in model.offeredToolsPerRequest)
        offered = offered || [tools containsString:@"device_info"];
    XCTAssertTrue(offered, @"device_info was never offered to the model — the plugin did not register it. Output:\n%@", out);
    XCTAssertTrue([out containsString:@"TOOL-RESULT-BEGIN"], @"the tool result never reached the model:\n%@", out);
    XCTAssertTrue([out containsString:@"systemVersion"], @"no device facts in the answer:\n%@", out);
    XCTAssertTrue([out containsString:UIDevice.currentDevice.systemVersion],
                  @"the model should see this device's iOS version (%@):\n%@", UIDevice.currentDevice.systemVersion, out);
}

/// The same whole path for a capability that is off by default and needs iOS's
/// own permission. On a test device neither grant is guaranteed, so this asserts
/// what must hold either way: the tool is offered, the call completes, and the
/// model is told something actionable instead of the turn hanging on a dialog.
- (void)testAgentCallsHealthThroughTheBridge {
    [self waitForReady];
    if (!HKHealthStore.isHealthDataAvailable)
        return;
    DSHMockLLMServer *model = [DSHMockLLMServer new];
    XCTAssertNotNil(model);
    model.requestTool = @"health_query";
    model.toolArguments = @"{\"metric\":\"activity\",\"days\":3}";
    [DSHCapabilityRegistry.shared setEnabled:YES forIdentifier:@"health.read"];

    DSHHostBridge *bridge = DSHHostBridge.shared;
    NSString *command = [NSString stringWithFormat:
        @"cd /root/workspace && HOME=/root DEEPSEEK_API_KEY=test DEEPSEEK_BASE_URL=%@ "
        @"DSH_HOST_BRIDGE_URL=%@ DSH_HOST_BRIDGE_TOKEN=%@ "
        @"node --expose-internals /usr/local/lib/node_modules/@deepseek-ai/dsh/lib/bin.js "
        @"--profile headless 'How active have I been?' 2>&1 | tail -25",
        model.baseURLString, bridge.baseURLString, bridge.token];

    XCTestExpectation *done = [self expectationWithDescription:@"health agent"];
    NSMutableString *out = [NSMutableString string];
    [ISHShellExecutor executeCommand:command lineCallback:^(NSString *line, BOOL isStdErr) {
        if (![line containsString:@"expose_wasm"]) [out appendFormat:@"%@\n", line];
    } completion:^(ISHShellExecutionResult *result) {
        [done fulfill];
    }];
    // Generous, but far below a hang: the point is that a missing permission
    // ends the turn quickly rather than blocking on a system dialog.
    [self waitForExpectations:@[done] timeout:300];
    [model stop];
    [DSHCapabilityRegistry.shared setEnabled:NO forIdentifier:@"health.read"];

    BOOL offered = NO;
    for (NSString *tools in model.offeredToolsPerRequest)
        offered = offered || [tools containsString:@"health_query"];
    XCTAssertTrue(offered, @"health_query was never offered to the model:\n%@", out);

    BOOL answered = [out containsString:@"Activity "] || [out containsString:@"steps"];
    BOOL refusedClearly = [out containsString:@"Health access"] || [out containsString:@"permission_denied"]
        || [out containsString:@"Settings"];
    XCTAssertTrue(answered || refusedClearly,
                  @"the model got neither health data nor an actionable refusal:\n%@", out);
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

/// iSH lets the guest mount a real iOS directory with `mount -t ios`, and
/// sys_mount checks no privilege, so any process in the image can ask. The
/// picker is genuine consent the first time, but the grant is then saved as a
/// bookmark and silently restored at every launch, where nothing in DSH knows
/// about it or can take it back. DSH does not register the filesystem, so the
/// mount fails at the type lookup, before any picker is raised.
- (void)testTheGuestCannotMountTheHostFilesystem {
    [self waitForReady];
    XCTestExpectation *done = [self expectationWithDescription:@"mount"];
    NSMutableString *out = [NSMutableString string];
    // An unregistered filesystem type fails in sys_mount's type lookup with
    // EINVAL, before iosfs_mount runs and before any picker is raised.
    NSString *command = @"mkdir -p /mnt/probe; "
                        @"for t in ios ios-unsafe; do "
                        @"  mount -t $t none /mnt/probe >/dev/null 2>&1; "
                        @"  echo \"RC-$t:$?\"; "
                        @"done; "
                        @"echo \"IOSMOUNTS:$(awk '$3 ~ /^ios/' /proc/mounts | wc -l)\"";
    [ISHShellExecutor executeCommand:command lineCallback:^(NSString *line, BOOL isStdErr) {
        [out appendFormat:@"%@\n", line];
    } completion:^(ISHShellExecutionResult *result) {
        for (NSString *type in @[@"ios", @"ios-unsafe"]) {
            NSString *marker = [NSString stringWithFormat:@"RC-%@:", type];
            XCTAssertTrue([out containsString:marker],
                          @"no result for -t %@ — the probe did not run: %@", type, out);
        }
        XCTAssertTrue([out containsString:@"IOSMOUNTS:0"],
                      @"an ios filesystem is mounted in the guest: %@", out);
        XCTAssertFalse([out containsString:@"RC-ios:0"],
                       @"`mount -t ios` succeeded: %@", out);
        XCTAssertFalse([out containsString:@"RC-ios-unsafe:0"],
                       @"`mount -t ios-unsafe` succeeded: %@", out);
        [done fulfill];
    }];
    [self waitForExpectations:@[done] timeout:180];
}

@end

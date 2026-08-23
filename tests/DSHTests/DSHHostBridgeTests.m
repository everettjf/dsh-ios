//
//  DSHHostBridgeTests.m
//  DSHTests
//
//  Unit tests for the host bridge: authentication, capability gating, routing,
//  and the device snapshot's contract with the guest plugin.
//

#import <XCTest/XCTest.h>
#import <arpa/inet.h>
#import <sys/socket.h>
#import <unistd.h>
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHDeviceCapability.h"

@interface DSHHostBridgeTests : XCTestCase
@property (nonatomic) DSHHostBridge *bridge;
@end

@implementation DSHHostBridgeTests

- (void)setUp {
    [super setUp];
    self.bridge = [DSHHostBridge new];   // a private instance, not the shared one
    XCTAssertTrue([self.bridge start], @"bridge should bind a loopback port");
    [DSHDeviceCapability installOn:self.bridge];
    // Capabilities ship on now; these suites assert what happens when one is off,
    // with device.info left on as the route that is expected to work.
    [DSHCapabilityRegistry.shared disableAllForTesting];
    [DSHCapabilityRegistry.shared setEnabled:YES forIdentifier:@"device.info"];
}

- (void)tearDown {
    [self.bridge stop];
    [super tearDown];
}

#pragma mark Helpers

/// Performs one request against the bridge and returns status + parsed JSON.
- (NSDictionary *)get:(NSString *)path token:(NSString *)token status:(NSInteger *)statusOut {
    return [self request:@"GET" path:path token:token body:nil host:nil status:statusOut];
}

- (NSDictionary *)request:(NSString *)method
                     path:(NSString *)path
                    token:(nullable NSString *)token
                     body:(nullable NSDictionary *)body
                     host:(nullable NSString *)host
                   status:(NSInteger *)statusOut {
    NSURL *url = [NSURL URLWithString:[self.bridge.baseURLString stringByAppendingString:path]];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    request.HTTPMethod = method;
    request.timeoutInterval = 10;
    if (token)
        [request setValue:[@"Bearer " stringByAppendingString:token] forHTTPHeaderField:@"Authorization"];
    if (host)
        [request setValue:host forHTTPHeaderField:@"Host"];
    if (body) {
        request.HTTPBody = [NSJSONSerialization dataWithJSONObject:body options:0 error:nil];
        [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    }
    __block NSDictionary *json = nil;
    __block NSInteger status = 0;
    XCTestExpectation *done = [self expectationWithDescription:path];
    [[NSURLSession.sharedSession dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        status = ((NSHTTPURLResponse *) response).statusCode;
        if (data.length)
            json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
        [done fulfill];
    }] resume];
    [self waitForExpectations:@[done] timeout:15];
    if (statusOut)
        *statusOut = status;
    return json;
}

#pragma mark Tests

- (void)testBridgeBindsLoopbackAndPublishesGuestEnvironment {
    XCTAssertTrue(self.bridge.running);
    XCTAssertGreaterThan(self.bridge.port, 0);
    XCTAssertTrue([self.bridge.baseURLString hasPrefix:@"http://127.0.0.1:"]);
    NSDictionary *env = self.bridge.guestEnvironment;
    XCTAssertEqualObjects(env[@"DSH_HOST_BRIDGE_URL"], self.bridge.baseURLString);
    XCTAssertEqual(self.bridge.token.length, 64u, @"32 random bytes as hex");
    XCTAssertEqualObjects(env[@"DSH_HOST_BRIDGE_TOKEN"], self.bridge.token);
}

- (void)testEveryLaunchGetsItsOwnToken {
    DSHHostBridge *other = [DSHHostBridge new];
    XCTAssertNotEqualObjects(other.token, self.bridge.token);
}

- (void)testRequestWithoutTokenIsRefused {
    NSInteger status = 0;
    NSDictionary *json = [self get:@"/v1/device" token:nil status:&status];
    XCTAssertEqual(status, 401);
    XCTAssertEqualObjects(json[@"error"][@"code"], @"unauthorized");
}

- (void)testRequestWithWrongTokenIsRefused {
    NSInteger status = 0;
    NSDictionary *json = [self get:@"/v1/device" token:@"not-the-token" status:&status];
    XCTAssertEqual(status, 401);
    XCTAssertEqualObjects(json[@"error"][@"code"], @"unauthorized");
}

- (void)testNonLoopbackHostHeaderIsRefused {
    NSInteger status = 0;
    NSDictionary *json = [self request:@"GET" path:@"/v1/device" token:self.bridge.token body:nil host:@"example.com" status:&status];
    XCTAssertEqual(status, 403);
    XCTAssertEqualObjects(json[@"error"][@"code"], @"unauthorized");
}

- (void)testUnknownRouteIsNotFound {
    NSInteger status = 0;
    NSDictionary *json = [self get:@"/v1/nope" token:self.bridge.token status:&status];
    XCTAssertEqual(status, 404);
    XCTAssertEqualObjects(json[@"error"][@"code"], @"invalid_request");
}

- (void)testCapabilitiesRouteListsDeviceInfo {
    NSInteger status = 0;
    NSDictionary *json = [self get:@"/v1/capabilities" token:self.bridge.token status:&status];
    XCTAssertEqual(status, 200);
    NSArray *capabilities = json[@"capabilities"];
    NSDictionary *device = nil;
    for (NSDictionary *capability in capabilities)
        if ([capability[@"id"] isEqualToString:@"device.info"])
            device = capability;
    XCTAssertNotNil(device, @"device.info must be advertised");
    XCTAssertEqualObjects(device[@"state"], @"granted");
    XCTAssertEqualObjects(device[@"gate"], @"enabled-only");
}

- (void)testDeviceRouteReturnsASnapshot {
    NSInteger status = 0;
    NSDictionary *json = [self get:@"/v1/device" token:self.bridge.token status:&status];
    XCTAssertEqual(status, 200);
    XCTAssertGreaterThan([json[@"model"] length], 0u);
    XCTAssertGreaterThan([json[@"systemVersion"] length], 0u);
    XCTAssertNotNil(json[@"thermalState"]);
    XCTAssertGreaterThan([json[@"processorCount"] integerValue], 0);
}

- (void)testDisabledCapabilityIsRefusedWithARecoverableError {
    [DSHCapabilityRegistry.shared setEnabled:NO forIdentifier:@"device.info"];
    NSInteger status = 0;
    NSDictionary *json = [self get:@"/v1/device" token:self.bridge.token status:&status];
    [DSHCapabilityRegistry.shared setEnabled:YES forIdentifier:@"device.info"];
    XCTAssertEqual(status, 403);
    XCTAssertEqualObjects(json[@"error"][@"code"], @"permission_denied");
    XCTAssertEqualObjects(json[@"error"][@"recoverable"], @YES);
}

- (void)testCapabilityStateFollowsTheSwitch {
    DSHCapabilityRegistry *registry = DSHCapabilityRegistry.shared;
    XCTAssertEqual([registry stateForIdentifier:@"device.info"], DSHCapabilityStateGranted);
    [registry setEnabled:NO forIdentifier:@"device.info"];
    XCTAssertEqual([registry stateForIdentifier:@"device.info"], DSHCapabilityStateDisabled);
    [registry setEnabled:YES forIdentifier:@"device.info"];
    XCTAssertEqual([registry stateForIdentifier:@"device.info"], DSHCapabilityStateGranted);
    // Deliberately not a real identifier: an unknown capability must read as
    // unavailable, not as denied, so the model can tell "never built" from
    // "switched off". (Do not reuse a shipping id here — it will start passing
    // for the wrong reason the day that capability lands.)
    XCTAssertEqual([registry stateForIdentifier:@"nonexistent.capability"], DSHCapabilityStateUnavailable,
                   @"a capability this build does not ship is unavailable, not denied");
}

/// The guest plugin declares `additionalProperties: false`, so a key the app
/// adds without updating the plugin's schema would make every tool call fail
/// validation. Keep the two in sync — this test is the tripwire.
- (void)testDeviceSnapshotMatchesThePluginSchema {
    NSSet *declared = [NSSet setWithArray:@[
        @"model", @"deviceClass", @"idiom", @"systemName", @"systemVersion",
        @"locale", @"timeZone", @"processorCount", @"physicalMemoryMB",
        @"batteryLevel", @"batteryState", @"thermalState", @"lowPowerMode", @"appVersion",
    ]];
    NSSet *actual = [NSSet setWithArray:DSHDeviceCapability.snapshot.allKeys];
    XCTAssertTrue([actual isSubsetOfSet:declared],
                  @"snapshot has keys the plugin schema does not declare: %@",
                  ({ NSMutableSet *extra = [actual mutableCopy]; [extra minusSet:declared]; extra; }));
}

- (void)testBodyLargerThanTheLimitIsRefused {
    // Announce an oversized body without uploading 12 MB. The bridge must
    // reject from Content-Length before waiting for or allocating the body.
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address = { .sin_len = sizeof(address), .sin_family = AF_INET,
        .sin_port = htons(self.bridge.port), .sin_addr.s_addr = htonl(INADDR_LOOPBACK) };
    XCTAssertEqual(connect(fd, (struct sockaddr *) &address, sizeof(address)), 0);
    NSString *head = [NSString stringWithFormat:
        @"POST /v1/device HTTP/1.1\r\nHost: 127.0.0.1\r\nAuthorization: Bearer %@\r\nContent-Length: 12582913\r\n\r\n",
        self.bridge.token];
    NSData *bytes = [head dataUsingEncoding:NSUTF8StringEncoding];
    XCTAssertEqual(send(fd, bytes.bytes, bytes.length, 0), (ssize_t) bytes.length);
    char response[512] = {0};
    ssize_t count = recv(fd, response, sizeof(response) - 1, 0);
    close(fd);
    XCTAssertGreaterThan(count, 0);
    XCTAssertNotEqual(strstr(response, "HTTP/1.1 413"), NULL);
}

- (void)testStopClosesThePort {
    NSString *base = self.bridge.baseURLString;
    [self.bridge stop];
    XCTAssertFalse(self.bridge.running);
    XCTAssertNil(self.bridge.baseURLString);
    XCTAssertEqualObjects(self.bridge.guestEnvironment, @{});
    // A request to the old port must now fail to connect.
    XCTestExpectation *done = [self expectationWithDescription:@"refused"];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:[base stringByAppendingString:@"/v1/device"]]];
    request.timeoutInterval = 5;
    [[NSURLSession.sharedSession dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        XCTAssertNotNil(error);
        [done fulfill];
    }] resume];
    [self waitForExpectations:@[done] timeout:10];
}

@end

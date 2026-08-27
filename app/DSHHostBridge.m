//
//  DSHHostBridge.m
//  DSH
//

#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHActivityLog.h"
#import "DSHHarness.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <unistd.h>

// An 8 MB exported file expands to about 10.7 MB as base64 inside JSON. Keep
// the transport ceiling above the capability ceiling while still bounding
// memory before JSON parsing.
static const NSUInteger kMaxRequestBytes = 12 * 1024 * 1024;
static const NSTimeInterval kSocketTimeout = 15;

#pragma mark - Response

@interface DSHHostBridgeResponse ()
@property (nonatomic, readwrite) NSInteger status;
@property (nonatomic, readwrite, copy) NSDictionary *body;
@property (nonatomic, readwrite, copy, nullable) NSData *rawBody;
@property (nonatomic, readwrite, copy) NSString *contentType;
@end

@implementation DSHHostBridgeResponse

+ (instancetype)ok:(NSDictionary *)body {
    return [self status:200 body:body];
}

+ (instancetype)status:(NSInteger)status body:(NSDictionary *)body {
    DSHHostBridgeResponse *response = [DSHHostBridgeResponse new];
    response.status = status;
    response.body = body ?: @{};
    response.contentType = @"application/json";
    return response;
}

+ (instancetype)status:(NSInteger)status contentType:(NSString *)contentType rawBody:(NSData *)rawBody {
    DSHHostBridgeResponse *response = [DSHHostBridgeResponse new];
    response.status = status;
    response.body = @{};
    response.rawBody = rawBody;
    response.contentType = contentType;
    return response;
}

+ (instancetype)errorWithStatus:(NSInteger)status code:(NSString *)code message:(NSString *)message recoverable:(BOOL)recoverable {
    return [self status:status body:@{ @"error": @{
        @"code": code,
        @"message": message,
        @"recoverable": @(recoverable),
    }}];
}

@end

#pragma mark - Request

@interface DSHHostBridgeRequest ()
@property (nonatomic, readwrite, copy) NSString *method;
@property (nonatomic, readwrite, copy) NSString *path;
@property (nonatomic, readwrite, copy) NSDictionary<NSString *, NSString *> *query;
@property (nonatomic, readwrite, copy) NSDictionary<NSString *, NSString *> *headers;
@property (nonatomic, readwrite, copy, nullable) NSDictionary *json;
@end

@implementation DSHHostBridgeRequest

- (NSInteger)integerFor:(NSString *)key fallback:(NSInteger)fallback min:(NSInteger)min max:(NSInteger)max {
    id value = self.query[key] ?: self.json[key];
    if (value == nil)
        return fallback;
    NSInteger parsed = [value respondsToSelector:@selector(integerValue)] ? [value integerValue] : fallback;
    return MAX(min, MIN(max, parsed));
}

@end

#pragma mark - Bridge

@interface DSHHostBridge ()
@property (nonatomic, readwrite) uint16_t port;
@property (nonatomic, readwrite, copy) NSString *token;
@property (nonatomic, readwrite, getter=isRunning) BOOL running;
@property (nonatomic, readwrite) NSUInteger requestCount;
@property (nonatomic) int listenFD;
@property (nonatomic) dispatch_source_t acceptSource;
@property (nonatomic) dispatch_queue_t queue;
@property (nonatomic) NSMutableDictionary<NSString *, NSDictionary *> *routes;   // "GET /v1/device" -> {capability, handler}
@end

@implementation DSHHostBridge

+ (instancetype)shared {
    static DSHHostBridge *shared;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ shared = [DSHHostBridge new]; });
    return shared;
}

- (instancetype)init {
    if (self = [super init]) {
        _listenFD = -1;
        _routes = [NSMutableDictionary dictionary];
        _queue = dispatch_queue_create("app.dsh.hostbridge", DISPATCH_QUEUE_CONCURRENT);
        _token = [self freshToken];
        [self registerBuiltInRoutes];
    }
    return self;
}

- (NSString *)freshToken {
    uint8_t bytes[32];
    if (SecRandomCopyBytes(kSecRandomDefault, sizeof(bytes), bytes) != errSecSuccess)
        arc4random_buf(bytes, sizeof(bytes));
    NSMutableString *hex = [NSMutableString stringWithCapacity:sizeof(bytes) * 2];
    for (size_t i = 0; i < sizeof(bytes); i++)
        [hex appendFormat:@"%02x", bytes[i]];
    return hex;
}

#pragma mark Routes

- (void)registerRoute:(NSString *)method path:(NSString *)path capability:(NSString *)capability handler:(DSHHostBridgeHandler)handler {
    NSString *key = [NSString stringWithFormat:@"%@ %@", method.uppercaseString, path];
    @synchronized (self.routes) {
        self.routes[key] = capability ? @{ @"capability": capability, @"handler": [handler copy] }
                                      : @{ @"handler": [handler copy] };
    }
}

- (void)registerBuiltInRoutes {
    // Discovery: always reachable with a valid token, so the guest can tell the
    // difference between "capability off" and "bridge missing".
    [self registerRoute:@"GET" path:@"/v1/capabilities" capability:nil handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        return [DSHHostBridgeResponse ok:@{ @"capabilities": DSHCapabilityRegistry.shared.stateSummary }];
    }];
}

- (DSHHostBridgeResponse *)invokeNativeMethod:(NSString *)method
                                         path:(NSString *)path
                                        query:(NSDictionary<NSString *,NSString *> *)query
                                         json:(NSDictionary *)json {
    NSDictionary *route;
    @synchronized (self.routes) {
        route = self.routes[[NSString stringWithFormat:@"%@ %@", method.uppercaseString, path]];
    }
    if (route == nil)
        return [DSHHostBridgeResponse errorWithStatus:404 code:@"invalid_request"
                                              message:[NSString stringWithFormat:@"no route for %@ %@", method, path]
                                          recoverable:NO];

    NSString *capability = route[@"capability"];
    if (capability) {
        DSHCapabilityState state = [DSHCapabilityRegistry.shared stateForIdentifier:capability];
        if (state == DSHCapabilityStateUnavailable)
            return [DSHHostBridgeResponse errorWithStatus:501 code:@"unavailable"
                                                  message:[NSString stringWithFormat:@"%@ is not available on this device", capability]
                                              recoverable:NO];
        if (state == DSHCapabilityStateDisabled)
            return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                                  message:[NSString stringWithFormat:@"%@ is switched off in DSH's settings; ask the user to enable it", capability]
                                              recoverable:YES];
    }

    DSHHostBridgeRequest *request = [DSHHostBridgeRequest new];
    request.method = method.uppercaseString;
    request.path = path;
    request.query = query ?: @{};
    request.headers = @{};
    request.json = json;

    DSHHostBridgeHandler handler = route[@"handler"];
    @try {
        return handler(request);
    } @catch (NSException *exception) {
        return [DSHHostBridgeResponse errorWithStatus:500 code:@"internal"
                                              message:exception.reason ?: @"handler failed"
                                          recoverable:NO];
    }
}

#pragma mark Lifecycle

- (BOOL)start {
    @synchronized (self) {
        if (self.running)
            return YES;
        int fd = socket(AF_INET, SOCK_STREAM, 0);
        if (fd < 0)
            return NO;
        int one = 1;
        setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));
        setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &one, sizeof(one));
        struct sockaddr_in addr = {
            .sin_len = sizeof(addr),
            .sin_family = AF_INET,
            .sin_port = 0,                                  // kernel picks a free port
            .sin_addr.s_addr = htonl(INADDR_LOOPBACK),      // loopback only, never the network
        };
        if (bind(fd, (struct sockaddr *) &addr, sizeof(addr)) < 0 || listen(fd, 8) < 0) {
            close(fd);
            return NO;
        }
        socklen_t len = sizeof(addr);
        getsockname(fd, (struct sockaddr *) &addr, &len);
        self.port = ntohs(addr.sin_port);
        self.listenFD = fd;

        __weak typeof(self) weakSelf = self;
        self.acceptSource = dispatch_source_create(DISPATCH_SOURCE_TYPE_READ, fd, 0, self.queue);
        dispatch_source_set_event_handler(self.acceptSource, ^{ [weakSelf acceptOne]; });
        dispatch_resume(self.acceptSource);
        self.running = YES;
        [DSHHarness.shared.log append:[NSString stringWithFormat:@"[dsh-ios] host bridge listening on 127.0.0.1:%u", self.port]];
        return YES;
    }
}

- (void)stop {
    @synchronized (self) {
        if (!self.running)
            return;
        self.running = NO;
        if (self.acceptSource) {
            dispatch_source_cancel(self.acceptSource);
            self.acceptSource = nil;
        }
        if (self.listenFD >= 0) {
            close(self.listenFD);
            self.listenFD = -1;
        }
    }
}

- (NSString *)baseURLString {
    return self.running ? [NSString stringWithFormat:@"http://127.0.0.1:%u", self.port] : nil;
}

- (NSDictionary<NSString *, NSString *> *)guestEnvironment {
    NSString *base = self.baseURLString;
    if (base == nil)
        return @{};
    return @{ @"DSH_HOST_BRIDGE_URL": base, @"DSH_HOST_BRIDGE_TOKEN": self.token };
}

#pragma mark Serving

- (void)acceptOne {
    int client = accept(self.listenFD, NULL, NULL);
    if (client < 0)
        return;
    struct timeval tv = { .tv_sec = (int) kSocketTimeout };
    setsockopt(client, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
    setsockopt(client, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
    dispatch_async(self.queue, ^{ [self serveConnection:client]; });
}

- (void)serveConnection:(int)fd {
    NSMutableData *buffer = [NSMutableData data];
    NSData *headerEnd = [@"\r\n\r\n" dataUsingEncoding:NSUTF8StringEncoding];
    NSRange split = NSMakeRange(NSNotFound, 0);
    char chunk[4096];
    // 1. Read until the end of the header block.
    while (split.location == NSNotFound) {
        ssize_t n = recv(fd, chunk, sizeof(chunk), 0);
        if (n <= 0) { close(fd); return; }
        [buffer appendBytes:chunk length:n];
        if (buffer.length > kMaxRequestBytes) {
            [self sendResponse:[DSHHostBridgeResponse errorWithStatus:413 code:@"invalid_request" message:@"request too large" recoverable:NO] to:fd];
            [self finishConnection:fd];
            return;
        }
        split = [buffer rangeOfData:headerEnd options:0 range:NSMakeRange(0, buffer.length)];
    }
    NSString *head = [[NSString alloc] initWithData:[buffer subdataWithRange:NSMakeRange(0, split.location)] encoding:NSUTF8StringEncoding];
    if (head == nil) { close(fd); return; }

    // 2. Parse request line and headers.
    NSArray<NSString *> *lines = [head componentsSeparatedByString:@"\r\n"];
    NSArray<NSString *> *requestLine = [lines.firstObject componentsSeparatedByString:@" "];
    if (requestLine.count < 2) {
        [self sendResponse:[DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request" message:@"malformed request line" recoverable:NO] to:fd];
        [self finishConnection:fd];
        return;
    }
    NSMutableDictionary<NSString *, NSString *> *headers = [NSMutableDictionary dictionary];
    for (NSUInteger i = 1; i < lines.count; i++) {
        NSRange colon = [lines[i] rangeOfString:@":"];
        if (colon.location == NSNotFound)
            continue;
        NSString *name = [lines[i] substringToIndex:colon.location].lowercaseString;
        NSString *value = [[lines[i] substringFromIndex:colon.location + 1] stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceCharacterSet];
        headers[name] = value;
    }

    // 3. Read the body, if the request has one.
    NSUInteger contentLength = (NSUInteger) [headers[@"content-length"] integerValue];
    NSUInteger bodyStart = split.location + split.length;
    if (contentLength > kMaxRequestBytes) {
        [self sendResponse:[DSHHostBridgeResponse errorWithStatus:413 code:@"invalid_request" message:@"body too large" recoverable:NO] to:fd];
        [self finishConnection:fd];
        return;
    }
    while (buffer.length - bodyStart < contentLength) {
        ssize_t n = recv(fd, chunk, sizeof(chunk), 0);
        if (n <= 0) {
            // The headers promised a body that never arrived: a stalled client,
            // or one that dropped the body but kept Content-Length — which is
            // exactly what NSURLSession does to a GET. Closing silently here
            // looks like a hang from the other end, so answer instead. The
            // socket's receive timeout is what bounds the wait.
            [self sendResponse:[DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                              message:@"the request announced a body it did not send"
                                                          recoverable:NO] to:fd];
            [self finishConnection:fd];
            return;
        }
        [buffer appendBytes:chunk length:n];
    }
    NSData *body = contentLength ? [buffer subdataWithRange:NSMakeRange(bodyStart, contentLength)] : nil;

    DSHHostBridgeResponse *response = [self handleMethod:requestLine[0] target:requestLine[1] headers:headers body:body];
    [self sendResponse:response to:fd];
    [self finishConnection:fd];
}

- (DSHHostBridgeResponse *)handleMethod:(NSString *)method target:(NSString *)target headers:(NSDictionary<NSString *, NSString *> *)headers body:(NSData *)body {
    self.requestCount++;

    // Loopback only: refuse anything that did not address 127.0.0.1/localhost,
    // so a misconfigured proxy can never expose this to the network.
    NSString *host = headers[@"host"] ?: @"";
    NSString *hostName = [host componentsSeparatedByString:@":"].firstObject;
    if (hostName.length && ![hostName isEqualToString:@"127.0.0.1"] && ![hostName isEqualToString:@"localhost"] && ![hostName isEqualToString:@"::1"])
        return [DSHHostBridgeResponse errorWithStatus:403 code:@"unauthorized" message:@"loopback only" recoverable:NO];

    NSString *authorization = headers[@"authorization"] ?: @"";
    NSString *presented = [authorization hasPrefix:@"Bearer "] ? [authorization substringFromIndex:7] : @"";
    if (![self tokenMatches:presented]) {
        [self log:method target:target outcome:@"unauthorized"];
        return [DSHHostBridgeResponse errorWithStatus:401 code:@"unauthorized" message:@"missing or wrong bridge token" recoverable:NO];
    }

    // Split path and query.
    NSArray<NSString *> *parts = [target componentsSeparatedByString:@"?"];
    NSString *path = parts.firstObject;
    NSMutableDictionary<NSString *, NSString *> *query = [NSMutableDictionary dictionary];
    if (parts.count > 1) {
        for (NSString *pair in [parts[1] componentsSeparatedByString:@"&"]) {
            NSArray<NSString *> *kv = [pair componentsSeparatedByString:@"="];
            if (kv.count == 2)
                query[kv[0].stringByRemovingPercentEncoding ?: kv[0]] = kv[1].stringByRemovingPercentEncoding ?: kv[1];
        }
    }

    NSDictionary *route;
    @synchronized (self.routes) {
        route = self.routes[[NSString stringWithFormat:@"%@ %@", method.uppercaseString, path]];
    }
    if (route == nil) {
        [self log:method target:path outcome:@"not_found"];
        return [DSHHostBridgeResponse errorWithStatus:404 code:@"invalid_request" message:[NSString stringWithFormat:@"no route for %@ %@", method, path] recoverable:NO];
    }

    NSString *capability = route[@"capability"];
    if (capability) {
        DSHCapabilityState state = [DSHCapabilityRegistry.shared stateForIdentifier:capability];
        if (state == DSHCapabilityStateUnavailable) {
            [self log:method target:path outcome:@"unavailable"];
            [DSHActivityLog.shared recordSource:DSHActivitySourceCapability name:capability
                                         detail:path result:@"not available on this device"
                                        outcome:DSHActivityOutcomeRefused duration:0];
            return [DSHHostBridgeResponse errorWithStatus:501 code:@"unavailable"
                                                  message:[NSString stringWithFormat:@"%@ is not available on this device", capability] recoverable:NO];
        }
        if (state == DSHCapabilityStateDisabled) {
            [self log:method target:path outcome:@"denied (capability off)"];
            [DSHActivityLog.shared recordSource:DSHActivitySourceCapability name:capability
                                         detail:path result:@"switched off"
                                        outcome:DSHActivityOutcomeRefused duration:0];
            return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                                  message:[NSString stringWithFormat:@"%@ is switched off in DSH's settings; ask the user to enable it", capability] recoverable:YES];
        }
    }

    NSDictionary *json = nil;
    if (body.length) {
        id parsed = [NSJSONSerialization JSONObjectWithData:body options:0 error:nil];
        if (![parsed isKindOfClass:NSDictionary.class])
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request" message:@"body must be a JSON object" recoverable:NO];
        json = parsed;
    }

    DSHHostBridgeRequest *request = [DSHHostBridgeRequest new];
    request.method = method.uppercaseString;
    request.path = path;
    request.query = query;
    request.headers = headers;
    request.json = json;

    DSHHostBridgeHandler handler = route[@"handler"];
    DSHHostBridgeResponse *response;
    NSDate *started = NSDate.date;
    @try {
        response = handler(request);
    } @catch (NSException *exception) {
        response = [DSHHostBridgeResponse errorWithStatus:500 code:@"internal" message:exception.reason ?: @"handler failed" recoverable:NO];
    }
    [self log:method target:path outcome:[NSString stringWithFormat:@"%ld", (long) response.status]];
    if (capability)
        [DSHActivityLog.shared recordSource:DSHActivitySourceCapability
                                       name:capability
                                     detail:[self describeRequest:request]
                                     result:[self describeResponse:response]
                                    outcome:[self outcomeForStatus:response.status]
                                   duration:-started.timeIntervalSinceNow];
    return response;
}

#pragma mark Describing a call for the activity log

/// The query, or for a body the keys it carried — enough to tell two calls
/// apart, without copying what was sent.
- (nullable NSString *)describeRequest:(DSHHostBridgeRequest *)request {
    if (request.query.count) {
        NSMutableArray *pairs = [NSMutableArray array];
        for (NSString *key in [request.query.allKeys sortedArrayUsingSelector:@selector(compare:)])
            [pairs addObject:[NSString stringWithFormat:@"%@=%@", key, request.query[key]]];
        return [pairs componentsJoinedByString:@" "];
    }
    if (request.json.count) {
        NSArray *keys = [request.json.allKeys sortedArrayUsingSelector:@selector(compare:)];
        return [NSString stringWithFormat:@"{%@}", [keys componentsJoinedByString:@", "]];
    }
    return nil;
}

/// The shape of the answer, never its contents: the point of the log is that
/// it can be read without leaking what the capability returned.
- (nullable NSString *)describeResponse:(DSHHostBridgeResponse *)response {
    if (response.status >= 400)
        return response.body[@"error"][@"message"];
    NSMutableArray *parts = [NSMutableArray array];
    for (NSString *key in [response.body.allKeys sortedArrayUsingSelector:@selector(compare:)]) {
        id value = response.body[key];
        if ([value isKindOfClass:NSArray.class])
            [parts addObject:[NSString stringWithFormat:@"%lu %@", (unsigned long) [value count], key]];
        else if ([value isKindOfClass:NSNumber.class] || [key isEqualToString:@"metric"])
            [parts addObject:[NSString stringWithFormat:@"%@ %@", key, value]];
    }
    return parts.count ? [parts componentsJoinedByString:@", "] : @"ok";
}

- (DSHActivityOutcome)outcomeForStatus:(NSInteger)status {
    if (status < 400) return DSHActivityOutcomeOK;
    if (status == 408) return DSHActivityOutcomeTimedOut;
    if (status == 403 || status == 409 || status == 429) return DSHActivityOutcomeRefused;
    return DSHActivityOutcomeError;
}

/// Constant-time comparison so a wrong token cannot be found byte by byte.
- (BOOL)tokenMatches:(NSString *)presented {
    NSData *a = [presented dataUsingEncoding:NSUTF8StringEncoding] ?: NSData.data;
    NSData *b = [self.token dataUsingEncoding:NSUTF8StringEncoding];
    if (a.length != b.length)
        return NO;
    const uint8_t *pa = a.bytes, *pb = b.bytes;
    uint8_t diff = 0;
    for (NSUInteger i = 0; i < b.length; i++)
        diff |= pa[i] ^ pb[i];
    return diff == 0;
}

- (void)log:(NSString *)method target:(NSString *)target outcome:(NSString *)outcome {
    [DSHHarness.shared.log append:[NSString stringWithFormat:@"[bridge] %@ %@ → %@", method.uppercaseString, target, outcome]];
}

/// Ends a connection after a response. Closing while the client is still
/// sending (a refused oversized body) makes it see a reset instead of our
/// answer, so half-close and drain what is left first.
- (void)finishConnection:(int)fd {
    shutdown(fd, SHUT_WR);
    char scratch[4096];
    NSUInteger drained = 0;
    while (drained < 4 * 1024 * 1024) {
        ssize_t n = recv(fd, scratch, sizeof(scratch), 0);
        if (n <= 0)
            break;
        drained += (NSUInteger) n;
    }
    close(fd);
}

- (void)sendResponse:(DSHHostBridgeResponse *)response to:(int)fd {
    NSData *json = response.rawBody ?: [NSJSONSerialization dataWithJSONObject:response.body options:0 error:nil]
                   ?: [@"{\"error\":{\"code\":\"internal\",\"message\":\"unserialisable response\"}}" dataUsingEncoding:NSUTF8StringEncoding];
    NSString *head = [NSString stringWithFormat:
                      @"HTTP/1.1 %ld %@\r\nContent-Type: %@\r\nContent-Length: %lu\r\nCache-Control: no-store\r\nConnection: close\r\n\r\n",
                      (long) response.status,
                      response.status == 200 ? @"OK" : @"Error",
                      response.contentType ?: @"application/json",
                      (unsigned long) json.length];
    NSMutableData *out = [[head dataUsingEncoding:NSUTF8StringEncoding] mutableCopy];
    [out appendData:json];
    const uint8_t *bytes = out.bytes;
    NSUInteger sent = 0;
    while (sent < out.length) {
        ssize_t n = send(fd, bytes + sent, out.length - sent, 0);
        if (n <= 0)
            break;
        sent += n;
    }
}

@end

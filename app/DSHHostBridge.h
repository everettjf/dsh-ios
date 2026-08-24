//
//  DSHHostBridge.h
//  DSH
//
//  A loopback HTTP listener inside the app that the Linux guest calls to reach
//  iOS capabilities (see docs/host-bridge.md). The guest's sockets are
//  pass-through host sockets, so `fetch('http://127.0.0.1:<port>/v1/…')` from a
//  dsh tool lands here.
//
//  The bearer token keeps *other apps on the device* out; it cannot keep the
//  agent out (it runs as root in the guest and inherits the environment we
//  hand to dsh-serve), so every capability is additionally gated by
//  DSHCapabilityRegistry — that gate lives here, in the app.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DSHHostBridgeRequest;

/// A route's answer: either a JSON object, or an error to render.
@interface DSHHostBridgeResponse : NSObject
@property (nonatomic, readonly) NSInteger status;
@property (nonatomic, readonly, copy) NSDictionary *body;
@property (nonatomic, readonly, copy, nullable) NSData *rawBody;
@property (nonatomic, readonly, copy) NSString *contentType;
+ (instancetype)ok:(NSDictionary *)body;
+ (instancetype)status:(NSInteger)status body:(NSDictionary *)body;
+ (instancetype)status:(NSInteger)status contentType:(NSString *)contentType rawBody:(NSData *)rawBody;
/// `{ "error": { "code": …, "message": …, "recoverable": … } }` with a status.
+ (instancetype)errorWithStatus:(NSInteger)status
                           code:(NSString *)code
                        message:(NSString *)message
                    recoverable:(BOOL)recoverable;
@end

/// One parsed request. Handlers run on a background queue; anything touching
/// UIKit must hop to the main queue itself.
@interface DSHHostBridgeRequest : NSObject
@property (nonatomic, readonly, copy) NSString *method;
@property (nonatomic, readonly, copy) NSString *path;          // without the query
@property (nonatomic, readonly, copy) NSDictionary<NSString *, NSString *> *query;
@property (nonatomic, readonly, copy) NSDictionary<NSString *, NSString *> *headers;
@property (nonatomic, readonly, copy, nullable) NSDictionary *json;  // parsed body, if any
/// Query or body value as a bounded integer (`fallback` when absent/invalid).
- (NSInteger)integerFor:(NSString *)key fallback:(NSInteger)fallback min:(NSInteger)min max:(NSInteger)max;
@end

typedef DSHHostBridgeResponse *_Nonnull (^DSHHostBridgeHandler)(DSHHostBridgeRequest *request);

@interface DSHHostBridge : NSObject

+ (instancetype)shared;

/// Binds 127.0.0.1 on a free port and starts serving. Idempotent; returns NO
/// when the socket could not be opened.
- (BOOL)start;
- (void)stop;

@property (nonatomic, readonly, getter=isRunning) BOOL running;
@property (nonatomic, readonly) uint16_t port;
/// Random per launch; handed to the guest through the harness environment.
@property (nonatomic, readonly, copy) NSString *token;
/// e.g. http://127.0.0.1:49213 — nil until started.
@property (nonatomic, readonly, nullable) NSString *baseURLString;
/// Environment for dsh-serve: DSH_HOST_BRIDGE_URL / _TOKEN (empty when stopped).
@property (nonatomic, readonly, copy) NSDictionary<NSString *, NSString *> *guestEnvironment;

/// Registers a route. `capability` may be nil for infrastructure routes
/// (`/v1/capabilities`); otherwise the registry must report it granted or the
/// call is refused before the handler runs.
- (void)registerRoute:(NSString *)method
                 path:(NSString *)path
           capability:(nullable NSString *)capability
              handler:(DSHHostBridgeHandler)handler;

/// Number of requests served since start (for tests and the log).
@property (nonatomic, readonly) NSUInteger requestCount;

@end

NS_ASSUME_NONNULL_END

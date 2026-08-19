//
//  DSHMockLLMServer.h
//  DSHTests
//
//  A DeepSeek-compatible chat-completions server inside the test host, so an
//  on-device test can drive a whole agent turn — including a tool call — with
//  no network and no real model. The guest reaches it over loopback exactly
//  like it reaches the real API.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DSHMockLLMServer : NSObject

/// Binds 127.0.0.1 on a free port. Returns nil when the socket fails.
- (nullable instancetype)init;

@property (nonatomic, readonly) uint16_t port;
@property (nonatomic, readonly) NSString *baseURLString;   // http://127.0.0.1:<port>

/// When set, the first completion that is offered this tool asks for it; once
/// the tool's result is in the conversation, the reply quotes it between
/// TOOL-RESULT-BEGIN/END markers.
@property (atomic, copy, nullable) NSString *requestTool;
/// Plain reply used when no tool is requested.
@property (atomic, copy) NSString *reply;

/// Names of the tools the harness offered, per request (for assertions).
@property (atomic, readonly, copy) NSArray<NSString *> *offeredToolsPerRequest;
@property (atomic, readonly) NSUInteger requestCount;

- (void)stop;

@end

NS_ASSUME_NONNULL_END

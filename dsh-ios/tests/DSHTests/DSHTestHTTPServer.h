//
//  DSHTestHTTPServer.h
//  DSHTests
//
//  Tiny loopback HTTP server (answers every request with 200) so unit tests
//  can drive DSHReadinessProbe / DSHHarness without the Linux guest.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DSHTestHTTPServer : NSObject
/// Binds 127.0.0.1:port (0 = ephemeral) and starts accepting. Returns nil on failure.
- (nullable instancetype)initWithPort:(uint16_t)port;
@property (nonatomic, readonly) uint16_t port;
@property (nonatomic, readonly) NSURL *baseURL;
@property (atomic) NSInteger statusCode;   // default 200
@property (atomic, readonly) NSUInteger requestCount;
- (void)stop;
@end

NS_ASSUME_NONNULL_END

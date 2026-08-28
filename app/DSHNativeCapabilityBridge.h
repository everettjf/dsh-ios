#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Codable boundary between Swift-native tools and the existing iOS framework
/// adapters. The returned JSON is `{status, body}`.
@interface DSHNativeCapabilityBridge : NSObject
+ (NSData *)invokeMethod:(NSString *)method
                    path:(NSString *)path
                   query:(NSDictionary<NSString *, NSString *> *)query
                    json:(nullable NSDictionary *)json;
@end

NS_ASSUME_NONNULL_END

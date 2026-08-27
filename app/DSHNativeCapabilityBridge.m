#import "DSHNativeCapabilityBridge.h"
#import "DSHHostBridge.h"

@implementation DSHNativeCapabilityBridge

+ (NSData *)invokeMethod:(NSString *)method
                    path:(NSString *)path
                   query:(NSDictionary<NSString *,NSString *> *)query
                    json:(NSDictionary *)json {
    DSHHostBridgeResponse *response = [DSHHostBridge.shared invokeNativeMethod:method path:path query:query json:json];
    NSDictionary *envelope = @{ @"status": @(response.status), @"body": response.body ?: @{} };
    NSError *error;
    NSData *data = [NSJSONSerialization dataWithJSONObject:envelope options:0 error:&error];
    if (data != nil)
        return data;
    return [NSJSONSerialization dataWithJSONObject:@{
        @"status": @500,
        @"body": @{ @"error": @{ @"code": @"internal", @"message": error.localizedDescription ?: @"Could not encode native capability response", @"recoverable": @NO } }
    } options:0 error:nil];
}

@end

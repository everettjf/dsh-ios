#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DSHNativeToolAudit : NSObject
+ (void)recordStarted:(NSString *)name detail:(nullable NSString *)detail correlationID:(NSString *)correlationID;
+ (void)recordFinished:(NSString *)name
                 detail:(nullable NSString *)detail
                 result:(nullable NSString *)result
                outcome:(NSString *)outcome
               duration:(NSTimeInterval)duration
          correlationID:(NSString *)correlationID;
@end

NS_ASSUME_NONNULL_END

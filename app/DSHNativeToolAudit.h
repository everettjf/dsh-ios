#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DSHNativeToolAudit : NSObject
+ (void)recordStartedWithSource:(NSString *)source name:(NSString *)name detail:(nullable NSString *)detail correlationID:(NSString *)correlationID;
+ (void)recordFinishedWithSource:(NSString *)source name:(NSString *)name detail:(nullable NSString *)detail result:(nullable NSString *)result outcome:(NSString *)outcome duration:(NSTimeInterval)duration correlationID:(NSString *)correlationID;
+ (void)recordStarted:(NSString *)name detail:(nullable NSString *)detail correlationID:(NSString *)correlationID;
+ (void)recordFinished:(NSString *)name
                 detail:(nullable NSString *)detail
                 result:(nullable NSString *)result
                outcome:(NSString *)outcome
               duration:(NSTimeInterval)duration
          correlationID:(NSString *)correlationID;
+ (NSString *)diagnosticReport;
@end

NS_ASSUME_NONNULL_END

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Narrow Objective-C façade used by the Swift lazy guest manager.
@interface DSHGuestRuntime : NSObject
+ (void)ensureReady:(void (^)(NSError *_Nullable error))completion;
+ (void)executeCommand:(NSString *)command
                timeout:(NSTimeInterval)timeout
             completion:(void (^)(NSData *jsonResult))completion;
+ (void)streamCommand:(NSString *)command
           executionID:(NSString *)executionID
               timeout:(NSTimeInterval)timeout
                  line:(void (^)(NSString *line, BOOL isStdErr))line
            completion:(void (^)(NSData *jsonResult))completion;
+ (void)cancelExecutionID:(NSString *)executionID;
+ (void)writeData:(NSData *)data
            toPath:(NSString *)path
           timeout:(NSTimeInterval)timeout
        completion:(void (^)(NSData *jsonResult))completion;
@end

NS_ASSUME_NONNULL_END

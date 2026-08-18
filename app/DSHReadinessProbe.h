//
//  DSHReadinessProbe.h
//  DSH
//
//  Polls an HTTP URL until it answers, then reports success once. Used to
//  find out when the guest's dsh web server is accepting connections.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^DSHReadinessHandler)(BOOL ready, NSTimeInterval elapsed);

@interface DSHReadinessProbe : NSObject

- (instancetype)initWithURL:(NSURL *)url
                   interval:(NSTimeInterval)interval
                    timeout:(NSTimeInterval)timeout NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

/// URLSession used for probing; replaceable for tests.
@property (nonatomic) NSURLSession *session;

/// Starts polling. `handler` fires exactly once on the main queue: `ready=YES`
/// as soon as the URL responds with 2xx/3xx, `ready=NO` after `timeout`
/// seconds or after -cancel.
- (void)startWithHandler:(DSHReadinessHandler)handler;
- (void)cancel;

@property (nonatomic, readonly, getter=isRunning) BOOL running;

/// One-shot check: YES if the URL currently answers 2xx/3xx within `timeout`.
+ (void)checkURL:(NSURL *)url timeout:(NSTimeInterval)timeout completion:(void (^)(BOOL alive))completion;

@end

NS_ASSUME_NONNULL_END

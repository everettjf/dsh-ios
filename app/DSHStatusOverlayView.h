//
//  DSHStatusOverlayView.h
//  DSH
//
//  Full-screen status card shown while the harness is starting or failed.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DSHStatusOverlayView : UIView

@property (nonatomic, copy, nullable) dispatch_block_t retryHandler;
@property (nonatomic, copy, nullable) dispatch_block_t terminalHandler;
@property (nonatomic, copy, nullable) dispatch_block_t logHandler;

- (void)showStarting:(NSString *)message;
/// Drives the progress bar: elapsed vs. expected seconds since `startedAt`.
/// Pass nil startedAt to hide the estimate (e.g. "Loading the interface…").
- (void)setProgressStartedAt:(nullable NSDate *)startedAt expected:(NSTimeInterval)expected;
- (void)showFailure:(NSString *)message;
- (void)hide;
- (void)setLogText:(NSString *)text;

@property (nonatomic, readonly, getter=isShowingFailure) BOOL showingFailure;

@end

NS_ASSUME_NONNULL_END

//
//  DSHLogViewController.h
//  DSH
//
//  Scrollable, live-updating view of the server log with copy/share.
//

#import <UIKit/UIKit.h>
#import "DSHLogBuffer.h"

NS_ASSUME_NONNULL_BEGIN

@interface DSHLogViewController : UIViewController
- (instancetype)initWithLog:(DSHLogBuffer *)log NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END

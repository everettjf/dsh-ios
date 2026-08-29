#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Persists a small, value-only startup timeline for TestFlight diagnosis.
/// No user content, paths, credentials or model responses are recorded.
@interface DSHStartupMetrics : NSObject
+ (instancetype)shared;
- (void)beginLaunch;
- (void)mark:(NSString *)stage;
@property (nonatomic, readonly, copy) NSArray<NSDictionary *> *recentLaunches;
@property (nonatomic, readonly, copy) NSString *summary;
@end

NS_ASSUME_NONNULL_END

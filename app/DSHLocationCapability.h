//
//  DSHLocationCapability.h
//  DSH
//
//  One location fix, on request.
//
//  Nothing continuous: the agent asks, CoreLocation is started, the first
//  usable fix is returned and the manager is stopped again. A background agent
//  cannot quietly follow the user around, and the fix carries its accuracy so
//  the model can say "within 65 m" instead of implying more than it knows.
//

#import <Foundation/Foundation.h>
@class DSHHostBridge;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const DSHCapabilityLocationRead;

@interface DSHLocationCapability : NSObject
+ (void)installOn:(DSHHostBridge *)bridge;
@end

NS_ASSUME_NONNULL_END

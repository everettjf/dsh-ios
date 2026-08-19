//
//  DSHDeviceCapability.h
//  DSH
//
//  The first bridge capability: read-only facts about the device. No user data,
//  no system permission — it exists to prove the whole path end to end.
//

#import <Foundation/Foundation.h>
@class DSHHostBridge;

NS_ASSUME_NONNULL_BEGIN

@interface DSHDeviceCapability : NSObject
/// Adds `GET /v1/device` to the bridge.
+ (void)installOn:(DSHHostBridge *)bridge;
/// The payload that route returns (also used by tests).
+ (NSDictionary *)snapshot;
@end

NS_ASSUME_NONNULL_END

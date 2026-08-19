//
//  DSHHealthCapability.h
//  DSH
//
//  Apple Health, read-only, over HealthKit.
//
//  Gated twice like the EventKit capabilities: the user's switch in DSH's
//  settings, and iOS's own permission sheet. HealthKit adds a wrinkle the
//  others do not have — iOS deliberately refuses to tell an app whether *read*
//  access was granted, so a denied type is indistinguishable from a type with
//  no samples. Every route therefore says so in a `note` when it comes back
//  empty, rather than letting the model conclude the user has never walked.
//

#import <Foundation/Foundation.h>
#import <HealthKit/HealthKit.h>

@class DSHHostBridge;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const DSHCapabilityHealthRead;

@interface DSHHealthCapability : NSObject

/// Registers the capability and adds the `/v1/health/*` routes.
+ (void)installOn:(DSHHostBridge *)bridge;

/// Read types the capability asks for, in one sheet on first use.
+ (NSSet<HKObjectType *> *)readTypes;

/// Sleep totals built from samples, bucketed by the day a stretch *ends* on so
/// a night that crosses midnight counts once, on the waking day. A daytime nap
/// lands in the same bucket, so a row is a day's sleep rather than one night.
/// Pure: takes the samples rather than fetching them, so it is unit-testable.
+ (NSDictionary *)sleepSummaryFromSamples:(NSArray<HKCategorySample *> *)samples;

/// "Running", "Walking", … for the workout list; unknown values keep their raw
/// number so the model can still refer to them.
+ (NSString *)activityNameFor:(HKWorkoutActivityType)type;

@end

NS_ASSUME_NONNULL_END

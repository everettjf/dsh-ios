//
//  DSHDeviceCapability.m
//  DSH
//

#import "DSHCapability.h"
#import "DSHDeviceCapability.h"
#import "DSHHostBridge.h"
#import <UIKit/UIKit.h>
#include <sys/sysctl.h>

@implementation DSHDeviceCapability

+ (void)installOn:(DSHHostBridge *)bridge {
    [bridge registerRoute:@"GET" path:@"/v1/device" capability:@"device.info" handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        return [DSHHostBridgeResponse ok:[self snapshot]];
    }];
    // Same capability, cheaper answer: power and heat change minute to minute,
    // and an agent deciding whether to start something expensive should not
    // have to pull the whole device snapshot to find out.
    [bridge registerRoute:@"GET" path:@"/v1/device/power" capability:@"device.info" handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        return [DSHHostBridgeResponse ok:[self powerSnapshot]];
    }];
}

+ (NSDictionary *)powerSnapshot {
    NSDictionary *full = [self snapshot];
    NSMutableDictionary *out = [@{
        @"thermalState": full[@"thermalState"],
        @"lowPowerMode": full[@"lowPowerMode"],
        // Says out loud what "serious"/"critical" means for the agent's plans,
        // which is the only reason it asked.
        @"shouldDeferExpensiveWork": @([full[@"thermalState"] isEqualToString:@"serious"]
                                       || [full[@"thermalState"] isEqualToString:@"critical"]
                                       || [full[@"lowPowerMode"] boolValue]),
    } mutableCopy];
    if (full[@"batteryLevel"]) out[@"batteryLevel"] = full[@"batteryLevel"];
    if (full[@"batteryState"]) out[@"batteryState"] = full[@"batteryState"];
    return out;
}

+ (NSString *)hardwareModel {
    char value[64] = {0};
    size_t size = sizeof(value);
    if (sysctlbyname("hw.machine", value, &size, NULL, 0) != 0)
        return @"unknown";
    return [NSString stringWithUTF8String:value] ?: @"unknown";
}

+ (NSString *)thermalStateName {
    switch (NSProcessInfo.processInfo.thermalState) {
        case NSProcessInfoThermalStateNominal: return @"nominal";
        case NSProcessInfoThermalStateFair: return @"fair";
        case NSProcessInfoThermalStateSerious: return @"serious";
        case NSProcessInfoThermalStateCritical: return @"critical";
    }
    return @"unknown";
}

+ (NSDictionary *)snapshot {
    // UIDevice is main-thread-only for some properties; the bridge calls us on
    // a background queue, so gather UIKit values on the main queue.
    __block NSString *systemName, *systemVersion, *idiom, *deviceName;
    __block float batteryLevel;
    __block NSString *batteryState;
    void (^collect)(void) = ^{
        UIDevice *device = UIDevice.currentDevice;
        BOOL wasMonitoring = device.batteryMonitoringEnabled;
        device.batteryMonitoringEnabled = YES;
        systemName = device.systemName;
        systemVersion = device.systemVersion;
        deviceName = device.model;    // "iPhone"/"iPad" — never the user's device name
        idiom = device.userInterfaceIdiom == UIUserInterfaceIdiomPad ? @"pad"
              : device.userInterfaceIdiom == UIUserInterfaceIdiomPhone ? @"phone" : @"other";
        batteryLevel = device.batteryLevel;
        switch (device.batteryState) {
            case UIDeviceBatteryStateCharging: batteryState = @"charging"; break;
            case UIDeviceBatteryStateFull: batteryState = @"full"; break;
            case UIDeviceBatteryStateUnplugged: batteryState = @"unplugged"; break;
            default: batteryState = @"unknown"; break;
        }
        device.batteryMonitoringEnabled = wasMonitoring;
    };
    DSHRunOnMainSync(collect);

    NSProcessInfo *process = NSProcessInfo.processInfo;
    NSMutableDictionary *out = [@{
        @"model": [self hardwareModel],
        @"deviceClass": deviceName ?: @"unknown",
        @"idiom": idiom ?: @"other",
        @"systemName": systemName ?: @"iOS",
        @"systemVersion": systemVersion ?: @"",
        @"locale": NSLocale.currentLocale.localeIdentifier ?: @"",
        @"timeZone": NSTimeZone.localTimeZone.name ?: @"",
        @"processorCount": @(process.processorCount),
        @"physicalMemoryMB": @(process.physicalMemory / (1024 * 1024)),
        @"thermalState": [self thermalStateName],
        @"lowPowerMode": @(process.isLowPowerModeEnabled),
        @"appVersion": [NSBundle.mainBundle objectForInfoDictionaryKey:@"CFBundleShortVersionString"] ?: @"",
    } mutableCopy];
    if (batteryLevel >= 0)
        out[@"batteryLevel"] = @((int) roundf(batteryLevel * 100));
    out[@"batteryState"] = batteryState ?: @"unknown";
    return out;
}

@end

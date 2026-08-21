//
//  DSHLocationCapability.m
//  DSH
//

#import "DSHLocationCapability.h"
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHHarness.h"
#import <CoreLocation/CoreLocation.h>

NSString *const DSHCapabilityLocationRead = @"location.read";

/// A first fix usually lands in a second or two indoors, longer from cold.
static const NSTimeInterval kFixTimeout = 12;

@interface DSHLocationFix : NSObject <CLLocationManagerDelegate>
/// Asks iOS for access and keeps itself alive until the user answers.
+ (void)prompt;
@end

@implementation DSHLocationFix {
    CLLocationManager *_manager;
    dispatch_semaphore_t _done;
    CLLocation *_location;
    NSError *_error;
}

- (instancetype)init {
    if (self = [super init]) {
        _done = dispatch_semaphore_create(0);
        // CLLocationManager wants a run loop, so it is created and driven on the
        // main thread — which is also where the settings switch calls in from.
        DSHRunOnMainSync(^{
            self->_manager = [CLLocationManager new];
            self->_manager.delegate = self;
            self->_manager.desiredAccuracy = kCLLocationAccuracyHundredMeters;
        });
    }
    return self;
}

- (CLAuthorizationStatus)status {
    __block CLAuthorizationStatus status;
    DSHRunOnMainSync(^{ status = self->_manager.authorizationStatus; });
    return status;
}

/// Blocks until a fix, an error or the timeout. Returns nil on failure.
- (nullable CLLocation *)waitForFix {
    dispatch_async(dispatch_get_main_queue(), ^{ [self->_manager requestLocation]; });
    dispatch_semaphore_wait(_done, dispatch_time(DISPATCH_TIME_NOW, (int64_t) (kFixTimeout * NSEC_PER_SEC)));
    dispatch_async(dispatch_get_main_queue(), ^{ [self->_manager stopUpdatingLocation]; });
    return _location;
}

- (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray<CLLocation *> *)locations {
    _location = locations.lastObject;
    dispatch_semaphore_signal(_done);
}

- (void)locationManager:(CLLocationManager *)manager didFailWithError:(NSError *)error {
    _error = error;
    dispatch_semaphore_signal(_done);
}

/// The dialog outlives the call that raised it, and a CLLocationManager whose
/// owner has been deallocated is a delegate call into freed memory. One static
/// reference holds the asking object until iOS reports an answer.
static DSHLocationFix *sPrompt;

+ (void)prompt {
    DSHRunOnMainSync(^{
        sPrompt = [DSHLocationFix new];
        [sPrompt->_manager requestWhenInUseAuthorization];
    });
}

- (void)locationManagerDidChangeAuthorization:(CLLocationManager *)manager {
    if (manager.authorizationStatus != kCLAuthorizationStatusNotDetermined && self == sPrompt)
        sPrompt = nil;
}

@end

@implementation DSHLocationCapability

+ (void)installOn:(DSHHostBridge *)bridge {
    DSHCapability *capability =
        [[DSHCapability alloc] initWithIdentifier:DSHCapabilityLocationRead
                                            title:@"Location"
                                          details:@"One fix at a time, when the agent asks. DSH never tracks you in the background."
                                             gate:DSHCapabilityGateSystemPermission
                                 enabledByDefault:YES
                                        available:CLLocationManager.locationServicesEnabled];
    capability.requestSystemPermission = ^{
        [DSHLocationFix prompt];
        [DSHHarness.shared.log append:@"[bridge] asked for location access"];
    };
    [DSHCapabilityRegistry.shared registerCapability:capability];

    [bridge registerRoute:@"GET" path:@"/v1/location" capability:DSHCapabilityLocationRead
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        DSHLocationFix *fix = [DSHLocationFix new];
        CLAuthorizationStatus status = [fix status];
        if (status == kCLAuthorizationStatusNotDetermined) {
            [DSHLocationFix prompt];
            return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                                  message:@"iOS has just asked the user for location access. Tell them to allow it, then try again."
                                              recoverable:YES];
        }
        if (status == kCLAuthorizationStatusDenied || status == kCLAuthorizationStatusRestricted)
            return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                                  message:@"Location access is denied for DSH in iOS Settings ▸ Privacy ▸ Location Services."
                                              recoverable:YES];

        CLLocation *location = [fix waitForFix];
        if (location == nil)
            return [DSHHostBridgeResponse errorWithStatus:504 code:@"timeout"
                                                  message:@"No location fix within 12 seconds — indoors or with Location Services still warming up. Worth one retry."
                                              recoverable:YES];

        NSMutableDictionary *body = [@{
            @"latitude": @(location.coordinate.latitude),
            @"longitude": @(location.coordinate.longitude),
            // The model must be able to qualify the answer rather than imply
            // more precision than there is.
            @"accuracyMeters": @((NSInteger) round(location.horizontalAccuracy)),
            @"timestamp": [NSISO8601DateFormatter stringFromDate:location.timestamp
                                                        timeZone:NSTimeZone.systemTimeZone
                                                   formatOptions:NSISO8601DateFormatWithInternetDateTime],
        } mutableCopy];
        if (location.verticalAccuracy >= 0)
            body[@"altitudeMeters"] = @((NSInteger) round(location.altitude));
        if (location.speed >= 0)
            body[@"speedMetersPerSecond"] = @(round(location.speed * 10) / 10);
        return [DSHHostBridgeResponse ok:body];
    }];
}

@end

//
//  DSHCapability.m
//  DSH
//

#import "DSHCapability.h"
#import <UIKit/UIKit.h>

NSNotificationName const DSHCapabilityRegistryDidChangeNotification = @"DSHCapabilityRegistryDidChangeNotification";
static NSString *const kEnabledPrefix = @"DSHCapabilityEnabled.";

NSString *DSHCapabilityStateName(DSHCapabilityState state) {
    switch (state) {
        case DSHCapabilityStateGranted: return @"granted";
        case DSHCapabilityStateDisabled: return @"disabled";
        case DSHCapabilityStatePrompt: return @"prompt";
        case DSHCapabilityStateUnavailable: return @"unavailable";
    }
    return @"unavailable";
}

@implementation DSHCapability

- (instancetype)initWithIdentifier:(NSString *)identifier
                             title:(NSString *)title
                           details:(NSString *)details
                              gate:(DSHCapabilityGate)gate
                  enabledByDefault:(BOOL)enabledByDefault
                         available:(BOOL)available {
    if (self = [super init]) {
        _identifier = [identifier copy];
        _title = [title copy];
        _details = [details copy];
        _gate = gate;
        _enabledByDefault = enabledByDefault;
        _available = available;
    }
    return self;
}

@end

@interface DSHCapabilityRegistry ()
@property (nonatomic) NSMutableArray<DSHCapability *> *ordered;
@property (nonatomic) NSMutableDictionary<NSString *, DSHCapability *> *byIdentifier;
@end

@implementation DSHCapabilityRegistry

+ (instancetype)shared {
    static DSHCapabilityRegistry *shared;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        shared = [DSHCapabilityRegistry new];
        [shared registerBuiltIns];
    });
    return shared;
}

- (instancetype)init {
    if (self = [super init]) {
        _ordered = [NSMutableArray array];
        _byIdentifier = [NSMutableDictionary dictionary];
    }
    return self;
}

- (void)registerBuiltIns {
    // Phase 0 ships the one capability that needs no permission and no user
    // data, so the whole path can be proven before anything sensitive lands.
    [self registerCapability:[[DSHCapability alloc] initWithIdentifier:@"device.info"
                                                                title:@"Device information"
                                                              details:@"Model, iOS version, locale, battery and thermal state."
                                                                 gate:DSHCapabilityGateEnabledOnly
                                                     enabledByDefault:YES
                                                            available:YES]];
}

- (void)registerCapability:(DSHCapability *)capability {
    @synchronized (self) {
        DSHCapability *existing = self.byIdentifier[capability.identifier];
        if (existing)
            [self.ordered removeObject:existing];
        self.byIdentifier[capability.identifier] = capability;
        [self.ordered addObject:capability];
    }
}

- (NSArray<DSHCapability *> *)capabilities {
    @synchronized (self) { return [self.ordered copy]; }
}

- (DSHCapability *)capabilityWithIdentifier:(NSString *)identifier {
    @synchronized (self) { return self.byIdentifier[identifier]; }
}

- (BOOL)isEnabled:(NSString *)identifier {
    DSHCapability *capability = [self capabilityWithIdentifier:identifier];
    if (capability == nil || !capability.available)
        return NO;
    NSString *key = [kEnabledPrefix stringByAppendingString:identifier];
    NSNumber *stored = [NSUserDefaults.standardUserDefaults objectForKey:key];
    return stored != nil ? stored.boolValue : capability.enabledByDefault;
}

- (void)setEnabled:(BOOL)enabled forIdentifier:(NSString *)identifier {
    [NSUserDefaults.standardUserDefaults setBool:enabled forKey:[kEnabledPrefix stringByAppendingString:identifier]];
    dispatch_async(dispatch_get_main_queue(), ^{
        [NSNotificationCenter.defaultCenter postNotificationName:DSHCapabilityRegistryDidChangeNotification object:self];
    });
}

- (DSHCapabilityState)stateForIdentifier:(NSString *)identifier {
    DSHCapability *capability = [self capabilityWithIdentifier:identifier];
    if (capability == nil || !capability.available)
        return DSHCapabilityStateUnavailable;
    if (![self isEnabled:identifier])
        return DSHCapabilityStateDisabled;
    // Gates beyond the switch are evaluated by the capability's own handler
    // when the call arrives (system dialogs, per-call confirmation).
    return capability.gate == DSHCapabilityGateEnabledOnly ? DSHCapabilityStateGranted : DSHCapabilityStatePrompt;
}

- (NSArray<NSDictionary *> *)stateSummary {
    NSMutableArray *out = [NSMutableArray array];
    for (DSHCapability *capability in self.capabilities) {
        [out addObject:@{
            @"id": capability.identifier,
            @"title": capability.title,
            @"details": capability.details,
            @"state": DSHCapabilityStateName([self stateForIdentifier:capability.identifier]),
            @"gate": capability.gate == DSHCapabilityGateEnabledOnly ? @"enabled-only"
                   : capability.gate == DSHCapabilityGateSystemPermission ? @"system-permission" : @"per-call",
        }];
    }
    return out;
}

- (void)resetForTesting {
    @synchronized (self) {
        for (DSHCapability *capability in self.ordered)
            [NSUserDefaults.standardUserDefaults removeObjectForKey:[kEnabledPrefix stringByAppendingString:capability.identifier]];
        [self.ordered removeAllObjects];
        [self.byIdentifier removeAllObjects];
    }
}

@end

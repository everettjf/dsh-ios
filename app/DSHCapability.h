//
//  DSHCapability.h
//  DSH
//
//  The registry of iOS capabilities the guest may reach through the host
//  bridge. Each capability is off unless the user turned it on (or it is
//  harmless enough to default to on), and the app — never the guest — decides.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// How the app gates one capability.
typedef NS_ENUM(NSInteger, DSHCapabilityGate) {
    /// Allowed whenever the capability is enabled (read-only, no user data).
    DSHCapabilityGateEnabledOnly = 0,
    /// Needs the system permission dialog of its framework as well.
    DSHCapabilityGateSystemPermission,
    /// Needs a native confirmation in the app for every call.
    DSHCapabilityGatePerCall,
};

/// What a capability answers when asked whether it can run right now.
typedef NS_ENUM(NSInteger, DSHCapabilityState) {
    DSHCapabilityStateGranted = 0,  // ready to use
    DSHCapabilityStateDisabled,     // switched off in DSH's settings
    DSHCapabilityStatePrompt,       // enabled, but a permission/confirmation is still needed
    DSHCapabilityStateUnavailable,  // not supported by this build or OS
};

NSString *DSHCapabilityStateName(DSHCapabilityState state);

@interface DSHCapability : NSObject
@property (nonatomic, readonly, copy) NSString *identifier;   // e.g. "device.info"
@property (nonatomic, readonly, copy) NSString *title;        // shown in settings
@property (nonatomic, readonly, copy) NSString *details;      // one line for the user
@property (nonatomic, readonly) DSHCapabilityGate gate;
@property (nonatomic, readonly) BOOL enabledByDefault;
@property (nonatomic, readonly) BOOL available;               // supported on this device/build

- (instancetype)initWithIdentifier:(NSString *)identifier
                             title:(NSString *)title
                           details:(NSString *)details
                              gate:(DSHCapabilityGate)gate
                   enabledByDefault:(BOOL)enabledByDefault
                         available:(BOOL)available NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
@end

extern NSNotificationName const DSHCapabilityRegistryDidChangeNotification;

@interface DSHCapabilityRegistry : NSObject

+ (instancetype)shared;

/// Every capability this build knows about, in display order.
@property (nonatomic, readonly, copy) NSArray<DSHCapability *> *capabilities;

- (nullable DSHCapability *)capabilityWithIdentifier:(NSString *)identifier;
- (BOOL)isEnabled:(NSString *)identifier;
- (void)setEnabled:(BOOL)enabled forIdentifier:(NSString *)identifier;
/// Current state of one capability (unknown identifiers are Unavailable).
- (DSHCapabilityState)stateForIdentifier:(NSString *)identifier;
/// `capabilities` as JSON-ready dictionaries for `GET /v1/capabilities`.
- (NSArray<NSDictionary *> *)stateSummary;

/// Registers a capability; used by tests and by future capability modules.
- (void)registerCapability:(DSHCapability *)capability;
/// Test hook: forget every registered capability and stored preference.
- (void)resetForTesting;

@end

NS_ASSUME_NONNULL_END

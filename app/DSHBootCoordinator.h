//
//  DSHBootCoordinator.h
//  DSH
//
//  Runs everything that must happen before the harness can start — importing
//  the bundled guest image when it changed, and booting the emulator kernel —
//  on a background thread.
//
//  This work takes tens of seconds on a phone, and iOS kills an app whose
//  launch methods block for ~20 s (0x8badf00d). So the UI comes up first and
//  the boot reports progress through DSHBootStateDidChangeNotification.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DSHBootPhase) {
    DSHBootPhaseIdle = 0,
    DSHBootPhaseImportingImage,   // first launch, or an app update with a new image
    DSHBootPhaseBootingKernel,    // mounting the fakefs and starting init
    DSHBootPhaseMigratingData,    // copying ~/.dsh and the workspace from the previous root
    DSHBootPhaseReady,            // the guest is up; the harness may start
    DSHBootPhaseFailed,
};

typedef NS_ENUM(NSInteger, DSHModelProvider) {
    DSHModelProviderApplePCC = 0,
    DSHModelProviderDeepSeekAPI,
};

NSString *DSHModelProviderName(DSHModelProvider provider);
/// YES on iOS/iPadOS 27 and later, where Apple PCC can be selected.
BOOL DSHApplePCCSupported(void);

extern NSNotificationName const DSHBootStateDidChangeNotification;

@interface DSHBootCoordinator : NSObject

+ (instancetype)shared;

@property (nonatomic, readonly) DSHBootPhase phase;
/// 0…1 while importing an image, -1 when the step has no measurable progress.
@property (nonatomic, readonly) double progress;
/// Human-readable status for the startup overlay.
@property (nonatomic, readonly, copy) NSString *statusMessage;
/// Kernel boot result (0 = success); valid once the phase is Ready or Failed.
@property (nonatomic, readonly) int bootError;
/// Apple PCC is the default on iOS 27+; iOS 26 always uses DeepSeek API.
/// The selected provider survives app launches on systems that support PCC.
@property (nonatomic) DSHModelProvider modelProvider;

/// Starts the sequence on a background queue. Safe to call once per launch.
- (void)start;

@end

NS_ASSUME_NONNULL_END

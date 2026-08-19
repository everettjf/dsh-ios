//
//  DSHShortcutsCapability.h
//  DSH
//
//  Running one of the user's Shortcuts.
//
//  This is the widest capability in the bridge by far: a shortcut can do
//  anything the user has ever built, and DSH cannot see inside it. It is
//  confirmed per call, by name, always.
//
//  It also has a cost the others do not: opening Shortcuts sends DSH to the
//  background, which suspends the emulator — so the agent's turn stops until
//  the user comes back. The route says so in its answer rather than pretending
//  the call completed normally.
//

#import <Foundation/Foundation.h>
@class DSHHostBridge;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const DSHCapabilityShortcutsRun;

@interface DSHShortcutsCapability : NSObject
+ (void)installOn:(DSHHostBridge *)bridge;
/// The x-callback-url for a shortcut, percent-encoded. Exposed for tests.
+ (nullable NSURL *)urlForShortcut:(NSString *)name input:(nullable NSString *)input;
@end

NS_ASSUME_NONNULL_END

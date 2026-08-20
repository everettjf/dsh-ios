//
//  DSHClipboardCapability.h
//  DSH
//
//  Writing to the system pasteboard.
//
//  There is deliberately no read route. iOS asks the user to confirm every
//  programmatic read of a pasteboard that came from another app, and no API
//  avoids it — `detectPatterns` can say whether text is there but not what it
//  is. A capability that interrupts the user every single time it is used is
//  not worth having, so it was removed after trying it on a device.
//
//  Writing raises no system prompt, so the only confirmation is DSH's own, per
//  call: it changes state outside the app, and the next thing the user pastes
//  anywhere would be whatever the agent put there.
//

#import <Foundation/Foundation.h>
@class DSHHostBridge;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const DSHCapabilityClipboardWrite;

@interface DSHClipboardCapability : NSObject
/// Adds `POST /v1/clipboard`.
+ (void)installOn:(DSHHostBridge *)bridge;
/// Short, human-readable preview of what is about to be written, for the
/// confirmation alert (never the whole payload).
+ (NSString *)previewOf:(NSString *)text;
@end

NS_ASSUME_NONNULL_END

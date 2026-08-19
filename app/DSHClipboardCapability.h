//
//  DSHClipboardCapability.h
//  DSH
//
//  The system pasteboard, read and write.
//
//  Reading is gated by the switch alone — iOS shows its own paste banner, so
//  the user always learns that it happened. Writing is confirmed per call: it
//  changes state outside the app, and the next thing the user pastes anywhere
//  would be whatever the agent put there.
//

#import <Foundation/Foundation.h>
@class DSHHostBridge;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const DSHCapabilityClipboardRead;
extern NSString *const DSHCapabilityClipboardWrite;

@interface DSHClipboardCapability : NSObject
/// Adds `GET /v1/clipboard` and `POST /v1/clipboard`.
+ (void)installOn:(DSHHostBridge *)bridge;
/// Short, human-readable preview of what is about to be written, for the
/// confirmation alert (never the whole payload).
+ (NSString *)previewOf:(NSString *)text;
@end

NS_ASSUME_NONNULL_END

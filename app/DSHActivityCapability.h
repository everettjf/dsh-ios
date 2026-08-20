//
//  DSHActivityCapability.h
//  DSH
//
//  The route the guest reports its own tool calls through.
//
//  The app can see every bridge call, but not what the agent does *inside* the
//  guest — the bash it runs, the files it edits, the searches it makes. Those
//  are most of what an agent actually does, and none of them were visible.
//  The bridge plugin subscribes to dsh's session events and posts them here.
//
//  This route is not a capability: it carries no user data out of the device,
//  it only lets the guest describe itself, and switching it off would leave
//  the record silently incomplete — which is worse than not having one.
//

#import <Foundation/Foundation.h>
@class DSHHostBridge;

NS_ASSUME_NONNULL_BEGIN

@interface DSHActivityCapability : NSObject
/// Adds `POST /v1/activity`.
+ (void)installOn:(DSHHostBridge *)bridge;
@end

NS_ASSUME_NONNULL_END

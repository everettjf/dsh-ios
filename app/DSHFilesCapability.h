//
//  DSHFilesCapability.h
//  DSH
//
//  Moving files between the guest's workspace and the rest of iOS.
//
//  The app never reaches into the guest filesystem: the guest sends or receives
//  the *contents* over the bridge and writes them itself with the tools it
//  already has. That keeps the emulator's fakefs out of this entirely.
//
//  Import is confirmed by the document picker itself — the user chooses the
//  file, so there is nothing extra to ask. Export asks first: it puts data the
//  agent chose somewhere the user did not.
//

#import <Foundation/Foundation.h>
@class DSHHostBridge;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const DSHCapabilityFilesImport;
extern NSString *const DSHCapabilityFilesExport;

@interface DSHFilesCapability : NSObject
+ (void)installOn:(DSHHostBridge *)bridge;
/// Bytes a single import or export may carry.
+ (NSUInteger)maximumBytes;
@end

NS_ASSUME_NONNULL_END

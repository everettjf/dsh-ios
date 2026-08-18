//
//  DSHRootUpgrader.h
//  DSH
//
//  Keeps the imported guest root in sync with the root.tar.gz shipped in the
//  app bundle. When an update carries a different image, the new one is
//  imported as a fresh root, becomes the default, and after boot the user's
//  data (/root/.dsh — sessions, credentials, settings — and /root/workspace)
//  is copied over from the previous root, which is then deleted.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DSHRootUpgrader : NSObject

+ (instancetype)shared;

/// SHA-256 of the bundled root.tar.gz (from root.tar.gz.sha256), or nil.
@property (nonatomic, readonly, nullable) NSString *bundledRootHash;
/// Hash recorded for the root that is currently the default.
@property (nonatomic, readonly, nullable) NSString *installedRootHash;
/// Name of the root whose user data still has to be migrated, if any.
@property (nonatomic, readonly, nullable) NSString *pendingMigrationRoot;

/// Call BEFORE the kernel mounts the root (i.e. before AppDelegate.boot).
/// Imports the bundled image as a new default root when it changed. Returns
/// YES when a new root was imported (a migration is then pending).
- (BOOL)prepareRootsBeforeBoot;

/// Call AFTER the kernel booted. Copies user data from the previous root
/// into the running one (via the guest), unmounts and deletes it, then calls
/// completion on the main queue. Calls completion immediately when nothing
/// is pending.
- (void)migrateIfNeededWithCompletion:(void (^)(BOOL migrated, NSError *_Nullable error))completion;

@end

NS_ASSUME_NONNULL_END

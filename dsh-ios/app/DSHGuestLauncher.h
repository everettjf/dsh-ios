//
//  DSHGuestLauncher.h
//  DSH
//
//  DSHGuestProcessLauncher backed by the emulator (ISHShellExecutor).
//

#import <Foundation/Foundation.h>
#import "DSHHarness.h"

NS_ASSUME_NONNULL_BEGIN

@interface DSHGuestLauncher : NSObject <DSHGuestProcessLauncher>
@end

NS_ASSUME_NONNULL_END

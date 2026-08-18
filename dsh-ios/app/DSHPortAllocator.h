//
//  DSHPortAllocator.h
//  DSH
//
//  Picks the loopback TCP port the guest's dsh web server should listen on.
//  The guest's sockets are pass-through host sockets, so a port that is free
//  on the host loopback interface is free for the guest as well.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DSHPortAllocator : NSObject

/// First port that can be bound on 127.0.0.1 in [preferred, preferred+span),
/// or 0 when none is available.
+ (uint16_t)freeLoopbackPortStartingAt:(uint16_t)preferred span:(uint16_t)span;

/// YES when 127.0.0.1:port can currently be bound (i.e. nobody listens there).
+ (BOOL)isLoopbackPortFree:(uint16_t)port;

@end

NS_ASSUME_NONNULL_END

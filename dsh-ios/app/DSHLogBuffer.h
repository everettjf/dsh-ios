//
//  DSHLogBuffer.h
//  DSH
//
//  Bounded, thread-safe ring of log lines from the guest server process.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const DSHLogBufferDidChangeNotification;

@interface DSHLogBuffer : NSObject

- (instancetype)initWithCapacity:(NSUInteger)capacity NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, readonly) NSUInteger capacity;
@property (nonatomic, readonly) NSUInteger count;

/// Appends one line (trailing newlines stripped; noise lines the guest node
/// prints on every start are dropped). Posts DSHLogBufferDidChangeNotification
/// on the main queue.
- (void)append:(NSString *)line;
- (void)clear;

/// Snapshot of the retained lines, oldest first.
@property (nonatomic, readonly, copy) NSArray<NSString *> *lines;
/// The last `n` lines joined by "\n".
- (NSString *)tail:(NSUInteger)n;

/// Lines that add nothing for the user (e.g. the V8 flag warning).
+ (BOOL)isNoiseLine:(NSString *)line;

@end

NS_ASSUME_NONNULL_END

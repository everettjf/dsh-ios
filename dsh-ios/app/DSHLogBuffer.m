//
//  DSHLogBuffer.m
//  DSH
//

#import "DSHLogBuffer.h"

NSNotificationName const DSHLogBufferDidChangeNotification = @"DSHLogBufferDidChangeNotification";

@interface DSHLogBuffer ()
@property (nonatomic) NSMutableArray<NSString *> *storage;
@property (nonatomic) NSUInteger head;   // index of the oldest line when full
@property (nonatomic) BOOL notifyPending;
@end

@implementation DSHLogBuffer

- (instancetype)initWithCapacity:(NSUInteger)capacity {
    if (self = [super init]) {
        _capacity = MAX(capacity, 1);
        _storage = [NSMutableArray arrayWithCapacity:_capacity];
    }
    return self;
}

+ (BOOL)isNoiseLine:(NSString *)line {
    if (line.length == 0)
        return YES;
    if ([line containsString:@"disabling flag --expose_wasm"])
        return YES;
    return NO;
}

- (void)append:(NSString *)rawLine {
    NSString *line = [rawLine stringByTrimmingCharactersInSet:NSCharacterSet.newlineCharacterSet];
    if ([DSHLogBuffer isNoiseLine:line])
        return;
    @synchronized (self) {
        if (self.storage.count < self.capacity) {
            [self.storage addObject:line];
        } else {
            self.storage[self.head] = line;
            self.head = (self.head + 1) % self.capacity;
        }
        if (self.notifyPending)
            return;
        self.notifyPending = YES;
    }
    // Coalesce bursts of lines into one UI update per run-loop turn.
    dispatch_async(dispatch_get_main_queue(), ^{
        @synchronized (self) { self.notifyPending = NO; }
        [NSNotificationCenter.defaultCenter postNotificationName:DSHLogBufferDidChangeNotification object:self];
    });
}

- (void)clear {
    @synchronized (self) {
        [self.storage removeAllObjects];
        self.head = 0;
    }
    dispatch_async(dispatch_get_main_queue(), ^{
        [NSNotificationCenter.defaultCenter postNotificationName:DSHLogBufferDidChangeNotification object:self];
    });
}

- (NSUInteger)count {
    @synchronized (self) { return self.storage.count; }
}

- (NSArray<NSString *> *)lines {
    @synchronized (self) {
        if (self.storage.count < self.capacity || self.head == 0)
            return [self.storage copy];
        NSMutableArray *ordered = [NSMutableArray arrayWithCapacity:self.capacity];
        [ordered addObjectsFromArray:[self.storage subarrayWithRange:NSMakeRange(self.head, self.capacity - self.head)]];
        [ordered addObjectsFromArray:[self.storage subarrayWithRange:NSMakeRange(0, self.head)]];
        return ordered;
    }
}

- (NSString *)tail:(NSUInteger)n {
    NSArray<NSString *> *all = self.lines;
    if (all.count > n)
        all = [all subarrayWithRange:NSMakeRange(all.count - n, n)];
    return [all componentsJoinedByString:@"\n"];
}

@end

#import "DSHStartupMetrics.h"

static NSString *const kStartupHistoryKey = @"DSHStartupHistory.1";

@implementation DSHStartupMetrics {
    NSDate *_startedAt;
    NSMutableDictionary *_current;
}

+ (instancetype)shared {
    static DSHStartupMetrics *shared;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ shared = [DSHStartupMetrics new]; });
    return shared;
}

- (void)beginLaunch {
    @synchronized (self) {
        _startedAt = NSDate.date;
        _current = [@{ @"started_at": @(_startedAt.timeIntervalSince1970), @"stages": [NSMutableDictionary dictionary] } mutableCopy];
        [self persistCurrent];
    }
}

- (void)mark:(NSString *)stage {
    if (stage.length == 0) return;
    @synchronized (self) {
        if (_startedAt == nil) [self beginLaunch];
        NSMutableDictionary *stages = _current[@"stages"];
        stages[stage] = @(-_startedAt.timeIntervalSinceNow);
        [self persistCurrent];
    }
}

- (void)persistCurrent {
    if (_current == nil) return;
    NSUserDefaults *defaults = NSUserDefaults.standardUserDefaults;
    NSMutableArray *history = [[defaults arrayForKey:kStartupHistoryKey] mutableCopy] ?: [NSMutableArray array];
    if (history.count && [history.firstObject[@"started_at"] isEqual:_current[@"started_at"]])
        history[0] = [_current copy];
    else
        [history insertObject:[_current copy] atIndex:0];
    if (history.count > 10) [history removeObjectsInRange:NSMakeRange(10, history.count - 10)];
    [defaults setObject:history forKey:kStartupHistoryKey];
}

- (NSArray<NSDictionary *> *)recentLaunches {
    NSArray *value = [NSUserDefaults.standardUserDefaults arrayForKey:kStartupHistoryKey];
    return [value isKindOfClass:NSArray.class] ? value : @[];
}

- (NSString *)summary {
    NSMutableString *text = [NSMutableString stringWithString:@"Startup stages (seconds from launch):"];
    NSUInteger index = 0;
    for (NSDictionary *launch in self.recentLaunches) {
        if (index++ >= 5) break;
        NSDictionary *stages = launch[@"stages"];
        [text appendFormat:@"\n%lu. image=%@ kernel=%@ bridge=%@ harness=%@ web=%@",
            (unsigned long)index, stages[@"image_ready"] ?: @"–", stages[@"kernel_ready"] ?: @"–",
            stages[@"bridge_ready"] ?: @"–", stages[@"harness_ready"] ?: @"–", stages[@"web_ready"] ?: @"–"];
    }
    return text;
}

@end

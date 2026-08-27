//
//  DSHActivityLog.m
//  DSH
//

#import "DSHActivityLog.h"

NSNotificationName const DSHActivityLogDidChangeNotification = @"DSHActivityLogDidChange";

/// Enough to cover a long session without turning into a database. Older
/// entries are dropped, which is the right trade for a record whose job is
/// "what has this thing been doing lately".
static const NSUInteger kCapacity = 2000;
/// Arguments are summarised, never stored whole: a bash command is worth
/// seeing, a 40 KB file edit is not.
static const NSUInteger kMaxDetailCharacters = 300;
/// Writes are coalesced; a burst of tool calls should not mean a burst of
/// file writes on the main thread's heels.
static const NSTimeInterval kSaveDelay = 2.0;

NSString *DSHActivityOutcomeName(DSHActivityOutcome outcome) {
    switch (outcome) {
        case DSHActivityOutcomeOK: return @"ok";
        case DSHActivityOutcomeRefused: return @"refused";
        case DSHActivityOutcomeDeclined: return @"declined";
        case DSHActivityOutcomeTimedOut: return @"timed out";
        case DSHActivityOutcomeCancelled: return @"cancelled";
        case DSHActivityOutcomeError: return @"error";
        case DSHActivityOutcomeStarted: return @"started";
    }
}

static NSString *SourceName(DSHActivitySource source) {
    switch (source) {
        case DSHActivitySourceCapability: return @"capability";
        case DSHActivitySourceGuestTool: return @"tool";
        case DSHActivitySourceConfirmation: return @"asked";
        case DSHActivitySourceNativeTurn: return @"turn";
        case DSHActivitySourceModel: return @"model";
        case DSHActivitySourceMCP: return @"mcp";
        case DSHActivitySourceNativeGuest: return @"guest";
    }
}

static DSHActivitySource SourceFromName(NSString *name) {
    if ([name isEqualToString:@"tool"]) return DSHActivitySourceGuestTool;
    if ([name isEqualToString:@"asked"]) return DSHActivitySourceConfirmation;
    if ([name isEqualToString:@"turn"]) return DSHActivitySourceNativeTurn;
    if ([name isEqualToString:@"model"]) return DSHActivitySourceModel;
    if ([name isEqualToString:@"mcp"]) return DSHActivitySourceMCP;
    if ([name isEqualToString:@"guest"]) return DSHActivitySourceNativeGuest;
    return DSHActivitySourceCapability;
}

static DSHActivityOutcome OutcomeFromName(NSString *name) {
    if ([name isEqualToString:@"refused"]) return DSHActivityOutcomeRefused;
    if ([name isEqualToString:@"declined"]) return DSHActivityOutcomeDeclined;
    if ([name isEqualToString:@"timed out"]) return DSHActivityOutcomeTimedOut;
    if ([name isEqualToString:@"cancelled"]) return DSHActivityOutcomeCancelled;
    if ([name isEqualToString:@"error"]) return DSHActivityOutcomeError;
    if ([name isEqualToString:@"started"]) return DSHActivityOutcomeStarted;
    return DSHActivityOutcomeOK;
}

@interface DSHActivityEntry ()
@property (nonatomic, readwrite) NSDate *date;
@property (nonatomic, readwrite) DSHActivitySource source;
@property (nonatomic, readwrite) DSHActivityOutcome outcome;
@property (nonatomic, readwrite, copy) NSString *name;
@property (nonatomic, readwrite, copy, nullable) NSString *detail;
@property (nonatomic, readwrite, copy, nullable) NSString *result;
@property (nonatomic, readwrite) NSTimeInterval duration;
/// Not persisted: it only matters while a call is in flight.
@property (nonatomic, copy, nullable) NSString *correlationID;
@end

@implementation DSHActivityEntry

- (NSDictionary *)dictionaryRepresentation {
    NSMutableDictionary *out = [@{
        @"t": @(self.date.timeIntervalSince1970),
        @"source": SourceName(self.source),
        @"name": self.name,
        @"outcome": DSHActivityOutcomeName(self.outcome),
        @"duration": @(round(self.duration * 1000) / 1000),
    } mutableCopy];
    if (self.detail) out[@"detail"] = self.detail;
    if (self.result) out[@"result"] = self.result;
    return out;
}

+ (nullable instancetype)entryFromDictionary:(NSDictionary *)dictionary {
    if (![dictionary[@"name"] isKindOfClass:NSString.class])
        return nil;
    DSHActivityEntry *entry = [DSHActivityEntry new];
    entry.date = [NSDate dateWithTimeIntervalSince1970:[dictionary[@"t"] doubleValue]];
    entry.source = SourceFromName(dictionary[@"source"]);
    entry.outcome = OutcomeFromName(dictionary[@"outcome"]);
    entry.name = dictionary[@"name"];
    entry.detail = [dictionary[@"detail"] isKindOfClass:NSString.class] ? dictionary[@"detail"] : nil;
    entry.result = [dictionary[@"result"] isKindOfClass:NSString.class] ? dictionary[@"result"] : nil;
    entry.duration = [dictionary[@"duration"] doubleValue];
    return entry;
}

@end

@interface DSHActivityLog ()
/// Oldest first internally; `entries` reverses for display.
@property (nonatomic) NSMutableArray<DSHActivityEntry *> *storage;
@property (nonatomic) dispatch_queue_t queue;
@property (nonatomic) BOOL saveScheduled;
@property (nonatomic) BOOL notifyScheduled;
@end

@implementation DSHActivityLog

+ (instancetype)shared {
    static DSHActivityLog *shared;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ shared = [DSHActivityLog new]; });
    return shared;
}

- (instancetype)init {
    if (self = [super init]) {
        _storage = [NSMutableArray array];
        _queue = dispatch_queue_create("app.dsh.activitylog", DISPATCH_QUEUE_SERIAL);
        [self load];
    }
    return self;
}

- (NSUInteger)capacity { return kCapacity; }

#pragma mark Recording

- (void)recordSource:(DSHActivitySource)source
                name:(NSString *)name
              detail:(NSString *)detail
              result:(NSString *)result
             outcome:(DSHActivityOutcome)outcome
            duration:(NSTimeInterval)duration {
    [self recordSource:source name:name detail:detail result:result
               outcome:outcome duration:duration correlationID:nil];
}

- (void)recordSource:(DSHActivitySource)source
                name:(NSString *)name
              detail:(NSString *)detail
              result:(NSString *)result
             outcome:(DSHActivityOutcome)outcome
            duration:(NSTimeInterval)duration
       correlationID:(NSString *)correlationID {
    if (name.length == 0)
        return;
    DSHActivityEntry *entry = [DSHActivityEntry new];
    entry.date = NSDate.date;
    entry.source = source;
    entry.name = name;
    entry.detail = [self summarise:detail];
    entry.result = [self summarise:result];
    entry.outcome = outcome;
    entry.duration = duration;
    entry.correlationID = correlationID;

    dispatch_async(self.queue, ^{
        // A finished call replaces the row its start put there, keeping the
        // original timestamp — when it began is the useful moment.
        NSUInteger existing = correlationID ? [self indexOfCorrelation:correlationID] : NSNotFound;
        if (existing != NSNotFound) {
            DSHActivityEntry *started = self.storage[existing];
            entry.date = started.date;
            if (entry.detail == nil)
                entry.detail = started.detail;
            [self.storage replaceObjectAtIndex:existing withObject:entry];
            [self scheduleSave];
            [self scheduleNotify];
            return;
        }
        [self.storage addObject:entry];
        if (self.storage.count > kCapacity)
            [self.storage removeObjectsInRange:NSMakeRange(0, self.storage.count - kCapacity)];
        [self scheduleSave];
        [self scheduleNotify];
    });
}

/// One line, bounded. Newlines are the enemy of a list row, and a tool that
/// hands over a whole file should not be able to fill the log with it.
- (nullable NSString *)summarise:(nullable NSString *)text {
    if (![text isKindOfClass:NSString.class] || text.length == 0)
        return nil;
    NSString *flat = [[text componentsSeparatedByCharactersInSet:NSCharacterSet.newlineCharacterSet]
                      componentsJoinedByString:@" "];
    flat = [self redactSecrets:flat];
    flat = [flat stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceCharacterSet];
    while ([flat containsString:@"  "])
        flat = [flat stringByReplacingOccurrencesOfString:@"  " withString:@" "];
    if (flat.length > kMaxDetailCharacters)
        flat = [[flat substringToIndex:kMaxDetailCharacters] stringByAppendingString:@"…"];
    return flat.length ? flat : nil;
}

/// Apply this both while recording and while exporting so records written by
/// older app versions cannot leak credentials through a diagnostic report.
- (NSString *)redactSecrets:(NSString *)text {
    NSArray<NSString *> *patterns = @[
        @"(?i)(Bearer\\s+)[^\\s,;\\\"]+",
        @"(?i)((?:DEEPSEEK_API_KEY|DSH_HOST_BRIDGE_TOKEN|API[_-]?KEY|BEARER[_-]?TOKEN)\\s*[=:]\\s*)[^\\s,;]+",
        @"(?i)(\\\"(?:api[_-]?key|bearerToken|authorization)\\\"\\s*:\\s*\\\")[^\\\"]+"
    ];
    NSString *output = text;
    for (NSString *pattern in patterns) {
        NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:pattern options:0 error:nil];
        output = [regex stringByReplacingMatchesInString:output options:0 range:NSMakeRange(0, output.length)
                                             withTemplate:@"$1[REDACTED]"];
    }
    return output;
}

/// Only in-flight rows are candidates, and only recent ones: a correlation id
/// from the guest is unique per call, but a crashed turn can leave a start
/// behind forever and it should not capture a later call's result.
- (NSUInteger)indexOfCorrelation:(NSString *)correlationID {
    NSDate *cutoff = [NSDate dateWithTimeIntervalSinceNow:-600];
    for (NSInteger i = (NSInteger) self.storage.count - 1; i >= 0; i--) {
        DSHActivityEntry *entry = self.storage[i];
        if ([entry.date compare:cutoff] == NSOrderedAscending)
            break;
        if (entry.outcome == DSHActivityOutcomeStarted && [entry.correlationID isEqualToString:correlationID])
            return (NSUInteger) i;
    }
    return NSNotFound;
}

#pragma mark Reading

- (NSArray<DSHActivityEntry *> *)entries {
    __block NSArray *out;
    dispatch_sync(self.queue, ^{
        out = [[self.storage reverseObjectEnumerator] allObjects];
    });
    return out;
}

- (nullable NSDate *)lastUseOf:(NSString *)name {
    __block NSDate *date = nil;
    dispatch_sync(self.queue, ^{
        for (DSHActivityEntry *entry in [self.storage reverseObjectEnumerator]) {
            // A refusal is not a use: the point of "last used" is what actually
            // reached the framework.
            if ([entry.name isEqualToString:name] && entry.outcome == DSHActivityOutcomeOK) {
                date = entry.date;
                break;
            }
        }
    });
    return date;
}

- (NSUInteger)countOf:(NSString *)name within:(NSTimeInterval)seconds {
    __block NSUInteger count = 0;
    NSDate *cutoff = [NSDate dateWithTimeIntervalSinceNow:-seconds];
    dispatch_sync(self.queue, ^{
        for (DSHActivityEntry *entry in [self.storage reverseObjectEnumerator]) {
            if ([entry.date compare:cutoff] == NSOrderedAscending)
                break;
            if ([entry.name isEqualToString:name])
                count += 1;
        }
    });
    return count;
}

- (NSString *)plainText {
    NSDateFormatter *formatter = [NSDateFormatter new];
    formatter.dateFormat = @"yyyy-MM-dd HH:mm:ss";
    NSMutableString *out = [NSMutableString string];
    for (DSHActivityEntry *entry in self.entries) {
        [out appendFormat:@"%@  %-10s %-24s %-9s",
         [formatter stringFromDate:entry.date],
         SourceName(entry.source).UTF8String, entry.name.UTF8String,
         DSHActivityOutcomeName(entry.outcome).UTF8String];
        if (entry.duration > 0) [out appendFormat:@" %.2fs", entry.duration];
        if (entry.detail) [out appendFormat:@"  %@", entry.detail];
        if (entry.result) [out appendFormat:@"  → %@", entry.result];
        [out appendString:@"\n"];
    }
    return [self redactSecrets:out];
}

#pragma mark Persistence

- (NSURL *)fileURL {
    NSURL *directory = [NSFileManager.defaultManager URLsForDirectory:NSApplicationSupportDirectory
                                                            inDomains:NSUserDomainMask].firstObject;
    [NSFileManager.defaultManager createDirectoryAtURL:directory withIntermediateDirectories:YES
                                            attributes:nil error:nil];
    return [directory URLByAppendingPathComponent:@"dsh-activity.json"];
}

- (void)load {
    NSData *data = [NSData dataWithContentsOfURL:[self fileURL]];
    if (data == nil)
        return;
    NSArray *rows = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
    if (![rows isKindOfClass:NSArray.class])
        return;
    for (NSDictionary *row in rows) {
        if (![row isKindOfClass:NSDictionary.class])
            continue;
        DSHActivityEntry *entry = [DSHActivityEntry entryFromDictionary:row];
        if (entry)
            [self.storage addObject:entry];
    }
}

- (void)scheduleSave {
    if (self.saveScheduled)
        return;
    self.saveScheduled = YES;
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t) (kSaveDelay * NSEC_PER_SEC)), self.queue, ^{
        self.saveScheduled = NO;
        [self saveNow];
    });
}

- (void)saveNow {
    NSMutableArray *rows = [NSMutableArray arrayWithCapacity:self.storage.count];
    for (DSHActivityEntry *entry in self.storage)
        [rows addObject:entry.dictionaryRepresentation];
    NSData *data = [NSJSONSerialization dataWithJSONObject:rows options:0 error:nil];
    // Excluded from backups: it is a local audit trail, not user content, and
    // it should not follow the user onto another device.
    NSURL *url = [self fileURL];
    [data writeToURL:url options:NSDataWritingAtomic error:nil];
    [url setResourceValue:@YES forKey:NSURLIsExcludedFromBackupKey error:nil];
}

- (void)scheduleNotify {
    if (self.notifyScheduled)
        return;
    self.notifyScheduled = YES;
    dispatch_async(dispatch_get_main_queue(), ^{
        self.notifyScheduled = NO;
        [NSNotificationCenter.defaultCenter postNotificationName:DSHActivityLogDidChangeNotification object:self];
    });
}

- (void)clear {
    dispatch_async(self.queue, ^{
        [self.storage removeAllObjects];
        [self saveNow];
        [self scheduleNotify];
    });
}

- (void)resetForTesting {
    dispatch_sync(self.queue, ^{
        [self.storage removeAllObjects];
        [NSFileManager.defaultManager removeItemAtURL:[self fileURL] error:nil];
    });
}

@end

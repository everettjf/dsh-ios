//
//  DSHActivityLog.h
//  DSH
//
//  What the agent actually did.
//
//  The capability switches are only worth as much as the user's ability to
//  check them. Every bridge call and every confirmation was already logged —
//  into the same buffer as the guest's stdout, where nobody would ever find
//  it. This is the record that can be read: one timeline, persisted across
//  launches, covering both sides.
//
//    * the app side — capability calls, their outcome, and what the user
//      answered when asked;
//    * the guest side — every tool the agent ran, including the ones that
//      never touch iOS (bash, file edits, search), reported by the bridge
//      plugin through POST /v1/activity.
//
//  What is recorded is deliberately asymmetric. Names, times, durations and
//  outcomes always; arguments only as a one-line summary; the *contents* a
//  read returned never — a log of the user's contacts would be a worse leak
//  than the capability it is supposed to make auditable.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DSHActivitySource) {
    DSHActivitySourceCapability = 0,  // a bridge route, from the app's side
    DSHActivitySourceGuestTool,       // a dsh tool inside the guest
    DSHActivitySourceConfirmation,    // the user was asked, and answered
    DSHActivitySourceNativeTurn,      // Swift-native turn lifecycle
    DSHActivitySourceModel,           // model request metrics, never prompts
    DSHActivitySourceMCP,             // MCP connection and tool lifecycle
    DSHActivitySourceNativeGuest,     // optional Linux guest work from Swift
};

typedef NS_ENUM(NSInteger, DSHActivityOutcome) {
    DSHActivityOutcomeOK = 0,
    DSHActivityOutcomeRefused,        // a gate said no (switch off, no permission)
    DSHActivityOutcomeDeclined,       // the user said no
    DSHActivityOutcomeTimedOut,
    DSHActivityOutcomeCancelled,
    DSHActivityOutcomeError,
    DSHActivityOutcomeStarted,        // in flight; updated when it finishes
};

NSString *DSHActivityOutcomeName(DSHActivityOutcome outcome);

@interface DSHActivityEntry : NSObject
@property (nonatomic, readonly) NSDate *date;
@property (nonatomic, readonly) DSHActivitySource source;
@property (nonatomic, readonly) DSHActivityOutcome outcome;
/// `calendar.read`, `bash`, `reminders.write` — what was used.
@property (nonatomic, readonly, copy) NSString *name;
/// One line, already truncated: the command, the path, the effect confirmed.
@property (nonatomic, readonly, copy, nullable) NSString *detail;
/// Shape of what came back (`10 events`, `exit 0`), never the contents.
@property (nonatomic, readonly, copy, nullable) NSString *result;
@property (nonatomic, readonly) NSTimeInterval duration;

- (NSDictionary *)dictionaryRepresentation;
@end

extern NSNotificationName const DSHActivityLogDidChangeNotification;

@interface DSHActivityLog : NSObject

+ (instancetype)shared;

/// Newest first.
@property (nonatomic, readonly, copy) NSArray<DSHActivityEntry *> *entries;
/// Capped; oldest entries are dropped rather than growing without bound.
@property (nonatomic, readonly) NSUInteger capacity;

- (void)recordSource:(DSHActivitySource)source
                name:(NSString *)name
              detail:(nullable NSString *)detail
              result:(nullable NSString *)result
             outcome:(DSHActivityOutcome)outcome
            duration:(NSTimeInterval)duration;

/// Same, but keyed: a later record with the same `correlationID` replaces the
/// earlier one in place. This is what lets a tool appear the moment it starts
/// — useful while a long command runs — without leaving a second row behind
/// when it finishes.
- (void)recordSource:(DSHActivitySource)source
                name:(NSString *)name
              detail:(nullable NSString *)detail
              result:(nullable NSString *)result
             outcome:(DSHActivityOutcome)outcome
            duration:(NSTimeInterval)duration
       correlationID:(nullable NSString *)correlationID;

/// When a capability was last used at all, for the Capabilities screen.
- (nullable NSDate *)lastUseOf:(NSString *)name;
/// How many times `name` was used in the last `seconds` — the number that lets
/// a confirmation say "this is the fifth time in ten minutes".
- (NSUInteger)countOf:(NSString *)name within:(NSTimeInterval)seconds;

/// Plain text, for sharing out of the viewer.
- (NSString *)plainText;
- (void)clear;

/// Test hook: forget everything, including what is on disk.
- (void)resetForTesting;

@end

NS_ASSUME_NONNULL_END

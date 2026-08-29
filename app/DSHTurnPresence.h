//
//  DSHTurnPresence.h
//  DSH
//
//  iOS suspends an app that is not on screen, and the guest is threads inside
//  this process, so an agent turn does not continue while the user is somewhere
//  else. Today that is silent: the user switches away mid-turn, comes back, and
//  finds a conversation that stopped without saying why.
//
//  This does two things about it, neither of which is the real fix (turns that
//  resume where they left off, which is a change to the harness rather than to
//  the app):
//
//    - Asks iOS for the extra seconds it grants on the way out, so a step that
//      is already in flight — a capability call, an HTTP response being written
//      — finishes instead of being cut mid-write.
//    - Notices that a turn was in progress when the app left, and says so on
//      the way back, at the moment the user is looking at the stall and
//      wondering.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Posted on the main thread when the app returns to the foreground having left
/// it mid-turn. The object is the presence instance; there is no user info.
extern NSNotificationName const DSHTurnWasInterruptedNotification;
extern NSString *const DSHTurnRecoveryStatusKey;

@interface DSHTurnPresence : NSObject

@property (class, nonatomic, readonly) DSHTurnPresence *shared;

/// Starts observing the activity record and the app's lifecycle. Safe to call
/// more than once.
- (void)start;

/// Whether the agent has done something recently enough to count as working.
/// Any activity counts, guest tool calls included — a shell command running in
/// the guest is as much a turn in progress as a capability call is.
@property (nonatomic, readonly, getter=isWorking) BOOL working;

/// Set while the app is in the background having left mid-turn, and cleared
/// once the notice has been shown. Exposed for tests.
@property (nonatomic, readonly) BOOL leftMidTurn;
/// Last persisted interruption time, including an interruption carried across
/// a process termination. Nil after the recovery notice has been consumed.
@property (nonatomic, readonly, nullable) NSDate *interruptedAt;

/// How recent activity has to be to count as working.
@property (class, nonatomic, readonly) NSTimeInterval workingWindow;

/// Tests only: forget the last activity and any pending notice. The instance
/// outlives one test the way it outlives one turn, and in an app that is the
/// point — twenty seconds of memory is what makes the window work.
- (void)resetForTesting;

@end

NS_ASSUME_NONNULL_END

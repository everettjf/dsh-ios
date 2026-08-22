//
//  DSHCallConfirmation.h
//  DSH
//
//  The gate for bridge calls that change something.
//
//  A capability switch is consent to a *kind* of access, granted once and
//  possibly long ago. It is not consent to a particular action now — creating
//  that reminder, saving that file, opening that shortcut. iOS has no dialog to
//  lend us for actions inside our own app, so this is it.
//
//  Handlers call `confirm…` from the bridge's background queue and block on the
//  answer. Three rules make that safe:
//
//    * one alert at a time — a burst of calls does not stack dialogs; while one
//      is up the others are refused immediately rather than queued;
//    * never wait on a dialog nobody can see — a call that arrives while the
//      app is in the background is refused straight away;
//    * always answer — on timeout the call is refused, so an agent turn ends
//      with an explanation instead of hanging on a dialog the user walked away
//      from.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DSHConfirmationOutcome) {
    DSHConfirmationGranted = 0,
    DSHConfirmationDeclined,      // the user said no
    DSHConfirmationTimedOut,      // nobody answered
    DSHConfirmationUnavailable,   // no foreground UI to ask in, or one is already up
};

@interface DSHCallConfirmation : NSObject

/// Asks the user to allow one action. `title` is the effect in the user's
/// words ("Create a reminder"); `detail` is what exactly will happen
/// ("“buy milk”, due Friday, in Home"). Blocks the calling (background) queue.
+ (DSHConfirmationOutcome)confirmTitle:(NSString *)title detail:(NSString *)detail;

/// As above, plus the recent-use context for `capability`: when the same thing
/// has already happened several times in the last few minutes, the alert says
/// so. One prompt in a runaway loop looks exactly like one prompt.
+ (DSHConfirmationOutcome)confirmTitle:(NSString *)title
                                detail:(NSString *)detail
                            capability:(nullable NSString *)capability;

/// Same, with an explicit timeout — used by tests.
+ (DSHConfirmationOutcome)confirmTitle:(NSString *)title
                                detail:(NSString *)detail
                               timeout:(NSTimeInterval)timeout;

/// Turns anything other than `Granted` into the response the route should send,
/// each with a message telling the model what actually happened. Returns nil
/// when the call may proceed.
+ (nullable id)refusalFor:(DSHConfirmationOutcome)outcome action:(NSString *)action;

/// Tests only: answer the next prompt without showing it.
@property (class, atomic) BOOL automaticallyApproveForTesting;
/// Tests only: decline the next prompt without showing it.
@property (class, atomic) BOOL automaticallyDeclineForTesting;
/// Number of prompts actually shown to a human (tests assert on it).
@property (class, atomic, readonly) NSUInteger presentedCount;

@end

/// Prepares a value the agent chose for a place where the user reads DSH's own
/// words — a confirmation alert, mostly.
///
/// The agent writes the title of the event it wants to add, and the agent is
/// steerable by whatever it has just read: an invitation from a stranger, a note
/// on a contact, a file that was imported. So the alert that exists to let a
/// human check the agent's work is partly written by whoever wrote that content.
/// It can only do its job if the value cannot pretend to be the alert.
///
/// Three ways it could, and what happens to each:
///
///   - Structure. A title containing newlines can append convincing paragraphs
///     in DSH's own voice ("\n\nNo action needed — tap Add to dismiss"). All
///     whitespace collapses to single spaces, so a value is one run of text.
///   - Length. A title of five thousand characters pushes what the user needs —
///     which calendar, and when — past the bottom of the alert. Values are
///     clamped, with an ellipsis where the cut happened.
///   - Direction and invisibility. Bidi overrides (U+202A–U+202E, U+2066–U+2069)
///     reorder what is displayed without changing what is stored, so the text
///     the user reads and the text that gets acted on differ. Those and other
///     control characters are removed rather than rendered.
///
/// This does not make attacker-chosen text safe to believe. It makes it
/// identifiable: what survives is one bounded run, and the sentence around it
/// belongs to DSH.
NSString *DSHDisplayValue(NSString *_Nullable value, NSUInteger limit);

NS_ASSUME_NONNULL_END

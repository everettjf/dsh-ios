//
//  DSHCapabilitiesViewController.h
//  DSH
//
//  The switchboard for everything the agent can reach on the device.
//
//  Capabilities ship off; this is the only place they can be turned on. The
//  bridge reads the registry per call, so a switch takes effect on the agent's
//  next tool call — no restart, and revoking mid-turn works too.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DSHCapabilitiesViewController : UITableViewController
@end

NS_ASSUME_NONNULL_END

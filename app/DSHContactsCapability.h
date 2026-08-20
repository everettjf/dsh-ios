//
//  DSHContactsCapability.h
//  DSH
//
//  Contact lookup, read-only and search-first.
//
//  There is no "give me the address book" route: the agent has to say who it
//  is looking for, and gets at most a handful of matches. Dumping every
//  contact into a model's context is exactly the thing this bridge should not
//  make easy.
//

#import <Foundation/Foundation.h>
#import <Contacts/Contacts.h>
@class DSHHostBridge;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const DSHCapabilityContactsRead;

@interface DSHContactsCapability : NSObject
+ (void)installOn:(DSHHostBridge *)bridge;
/// Everything a match is fetched with — including the formatter's own required
/// keys, without which formatting a matched contact raises.
+ (NSArray<id<CNKeyDescriptor>> *)keysToFetch;
@end

NS_ASSUME_NONNULL_END

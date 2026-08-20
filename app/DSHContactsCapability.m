//
//  DSHContactsCapability.m
//  DSH
//

#import "DSHContactsCapability.h"
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHHarness.h"
#import <Contacts/Contacts.h>

NSString *const DSHCapabilityContactsRead = @"contacts.read";

static const NSInteger kDefaultLimit = 10;
static const NSInteger kMaxLimit = 25;

@implementation DSHContactsCapability

+ (CNContactStore *)store {
    static CNContactStore *store;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ store = [CNContactStore new]; });
    return store;
}

+ (void)requestAccess {
    [[self store] requestAccessForEntityType:CNEntityTypeContacts completionHandler:^(BOOL granted, NSError *error) {
        [DSHHarness.shared.log append:[NSString stringWithFormat:@"[bridge] contacts access %@",
                                       granted ? @"granted" : @"denied"]];
    }];
}

+ (nullable DSHHostBridgeResponse *)refusal {
    CNAuthorizationStatus status = [CNContactStore authorizationStatusForEntityType:CNEntityTypeContacts];
    BOOL authorized = status == CNAuthorizationStatusAuthorized;
    if (@available(iOS 18.0, *))
        authorized = authorized || status == CNAuthorizationStatusLimited;
    if (authorized)
        return nil;
    if (status == CNAuthorizationStatusNotDetermined) {
        [self requestAccess];
        return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                              message:@"iOS has just asked the user for Contacts access. Tell them to allow it, then try again."
                                          recoverable:YES];
    }
    return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                          message:@"Contacts access is denied for DSH in iOS Settings ▸ Privacy ▸ Contacts."
                                      recoverable:YES];
}

+ (NSArray<id<CNKeyDescriptor>> *)keysToFetch {
    return @[CNContactGivenNameKey, CNContactFamilyNameKey,
             CNContactOrganizationNameKey, CNContactNicknameKey,
             CNContactPhoneNumbersKey, CNContactEmailAddressesKey,
             CNContactPostalAddressesKey, CNContactBirthdayKey,
             // CNContactFormatter needs its own set, and asking it for a name
             // it was not given keys for raises rather than returning nil. This
             // only bites when a search actually matches somebody, which is why
             // it survived every test that ran against an empty address book.
             [CNContactFormatter descriptorForRequiredKeysForStyle:CNContactFormatterStyleFullName]];
}

+ (NSArray<NSDictionary *> *)matching:(NSString *)query limit:(NSInteger)limit truncated:(BOOL *)truncated {
    NSArray<id<CNKeyDescriptor>> *keys = [self keysToFetch];
    NSPredicate *predicate = [CNContact predicateForContactsMatchingName:query];
    NSError *error = nil;
    NSArray<CNContact *> *found = [[self store] unifiedContactsMatchingPredicate:predicate
                                                                    keysToFetch:keys error:&error];
    NSMutableArray *out = [NSMutableArray array];
    for (CNContact *contact in found) {
        if (out.count >= (NSUInteger) limit)
            break;
        NSMutableDictionary *item = [NSMutableDictionary dictionary];
        NSString *name = [CNContactFormatter stringFromContact:contact style:CNContactFormatterStyleFullName];
        item[@"name"] = name.length ? name : (contact.organizationName ?: @"(no name)");
        if (contact.organizationName.length) item[@"organization"] = contact.organizationName;
        if (contact.nickname.length) item[@"nickname"] = contact.nickname;

        NSMutableArray *phones = [NSMutableArray array];
        for (CNLabeledValue<CNPhoneNumber *> *phone in contact.phoneNumbers)
            [phones addObject:@{
                @"label": [CNLabeledValue localizedStringForLabel:phone.label ?: @""] ?: @"",
                @"number": phone.value.stringValue ?: @"",
            }];
        if (phones.count) item[@"phones"] = phones;

        NSMutableArray *emails = [NSMutableArray array];
        for (CNLabeledValue<NSString *> *email in contact.emailAddresses)
            [emails addObject:@{
                @"label": [CNLabeledValue localizedStringForLabel:email.label ?: @""] ?: @"",
                @"address": email.value ?: @"",
            }];
        if (emails.count) item[@"emails"] = emails;

        NSMutableArray *addresses = [NSMutableArray array];
        for (CNLabeledValue<CNPostalAddress *> *address in contact.postalAddresses)
            [addresses addObject:@{
                @"label": [CNLabeledValue localizedStringForLabel:address.label ?: @""] ?: @"",
                @"address": [CNPostalAddressFormatter stringFromPostalAddress:address.value
                                                                       style:CNPostalAddressFormatterStyleMailingAddress] ?: @"",
            }];
        if (addresses.count) item[@"addresses"] = addresses;

        if (contact.birthday) {
            NSDateComponents *birthday = contact.birthday;
            item[@"birthday"] = birthday.year != NSDateComponentUndefined
                ? [NSString stringWithFormat:@"%04ld-%02ld-%02ld", (long) birthday.year, (long) birthday.month, (long) birthday.day]
                : [NSString stringWithFormat:@"--%02ld-%02ld", (long) birthday.month, (long) birthday.day];
        }
        [out addObject:item];
    }
    if (truncated)
        *truncated = found.count > out.count;
    return out;
}

+ (void)installOn:(DSHHostBridge *)bridge {
    DSHCapability *capability =
        [[DSHCapability alloc] initWithIdentifier:DSHCapabilityContactsRead
                                            title:@"Contacts (read)"
                                          details:@"Look up a person by name. The agent has to name who it wants; it cannot list everyone."
                                             gate:DSHCapabilityGateSystemPermission
                                 enabledByDefault:NO
                                        available:YES];
    capability.requestSystemPermission = ^{ [self requestAccess]; };
    [DSHCapabilityRegistry.shared registerCapability:capability];

    [bridge registerRoute:@"GET" path:@"/v1/contacts" capability:DSHCapabilityContactsRead
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        NSString *query = request.query[@"q"];
        if (query.length == 0)
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:@"Pass `q` — the name to search for. There is no route that returns every contact."
                                              recoverable:NO];
        DSHHostBridgeResponse *refusal = [self refusal];
        if (refusal)
            return refusal;

        NSInteger limit = [request integerFor:@"limit" fallback:kDefaultLimit min:1 max:kMaxLimit];
        BOOL truncated = NO;
        NSArray *contacts = [self matching:query limit:limit truncated:&truncated];
        return [DSHHostBridgeResponse ok:@{ @"query": query, @"contacts": contacts, @"truncated": @(truncated) }];
    }];
}

@end

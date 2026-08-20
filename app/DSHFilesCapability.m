//
//  DSHFilesCapability.m
//  DSH
//

#import "DSHFilesCapability.h"
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHCallConfirmation.h"
#import "DSHHarness.h"
#import <UIKit/UIKit.h>
#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h>

NSString *const DSHCapabilityFilesImport = @"files.import";
NSString *const DSHCapabilityFilesExport = @"files.export";

/// Everything crosses the bridge base64-encoded inside a JSON body, so this is
/// a real ceiling, not a formality.
static const NSUInteger kMaxBytes = 8 * 1024 * 1024;
/// The picker is a human interaction; give it room but not forever.
static const NSTimeInterval kPickerTimeout = 120;

#pragma mark - Picker plumbing

/// Presents a document picker and turns its delegate callbacks back into a
/// blocking call for the bridge handler.
@interface DSHDocumentPicker : NSObject <UIDocumentPickerDelegate>
@property (nonatomic) NSURL *pickedURL;
@property (nonatomic) BOOL cancelled;
@property (nonatomic) dispatch_semaphore_t done;
@end

@implementation DSHDocumentPicker

- (instancetype)init {
    if (self = [super init])
        _done = dispatch_semaphore_create(0);
    return self;
}

- (void)documentPicker:(UIDocumentPickerViewController *)controller didPickDocumentsAtURLs:(NSArray<NSURL *> *)urls {
    self.pickedURL = urls.firstObject;
    dispatch_semaphore_signal(self.done);
}

- (void)documentPickerWasCancelled:(UIDocumentPickerViewController *)controller {
    self.cancelled = YES;
    dispatch_semaphore_signal(self.done);
}

@end

@implementation DSHFilesCapability

+ (NSUInteger)maximumBytes { return kMaxBytes; }

+ (nullable UIViewController *)topViewController {
    UIWindow *window = nil;
    for (UIScene *scene in UIApplication.sharedApplication.connectedScenes) {
        if (![scene isKindOfClass:UIWindowScene.class] || scene.activationState != UISceneActivationStateForegroundActive)
            continue;
        for (UIWindow *candidate in ((UIWindowScene *) scene).windows)
            if (candidate.isKeyWindow) { window = candidate; break; }
        if (window) break;
    }
    UIViewController *controller = window.rootViewController;
    while (controller.presentedViewController)
        controller = controller.presentedViewController;
    return controller;
}

+ (DSHHostBridgeResponse *)noForegroundUI {
    return [DSHHostBridgeResponse errorWithStatus:409 code:@"unavailable"
                                          message:@"DSH is not in the foreground, so it cannot show the file picker. Ask the user to open DSH and try again."
                                      recoverable:YES];
}

#pragma mark - Routes

+ (void)installOn:(DSHHostBridge *)bridge {
    DSHCapabilityRegistry *registry = DSHCapabilityRegistry.shared;
    [registry registerCapability:[[DSHCapability alloc] initWithIdentifier:DSHCapabilityFilesImport
                                                                    title:@"Files (import)"
                                                                  details:@"Opens the file picker so you can hand a file to the agent. You choose the file."
                                                                     gate:DSHCapabilityGateEnabledOnly
                                                         enabledByDefault:NO
                                                                available:YES]];
    [registry registerCapability:[[DSHCapability alloc] initWithIdentifier:DSHCapabilityFilesExport
                                                                    title:@"Files (export)"
                                                                  details:@"Lets the agent save a file out of DSH; you choose where it goes."
                                                                     gate:DSHCapabilityGatePerCall
                                                         enabledByDefault:NO
                                                                available:YES]];

    // Import: the picker *is* the confirmation, so there is no extra prompt.
    [bridge registerRoute:@"POST" path:@"/v1/files/import" capability:DSHCapabilityFilesImport
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        DSHDocumentPicker *picker = [DSHDocumentPicker new];
        __block BOOL presented = NO;
        dispatch_sync(dispatch_get_main_queue(), ^{
            UIViewController *top = [self topViewController];
            if (top == nil)
                return;
            UIDocumentPickerViewController *controller =
                [[UIDocumentPickerViewController alloc] initForOpeningContentTypes:@[UTTypeItem] asCopy:YES];
            controller.delegate = picker;
            controller.allowsMultipleSelection = NO;
            [top presentViewController:controller animated:YES completion:nil];
            presented = YES;
        });
        if (!presented)
            return [self noForegroundUI];

        dispatch_semaphore_wait(picker.done, dispatch_time(DISPATCH_TIME_NOW, (int64_t) (kPickerTimeout * NSEC_PER_SEC)));
        if (picker.cancelled || picker.pickedURL == nil)
            return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                                  message:@"The user closed the file picker without choosing anything."
                                              recoverable:NO];

        NSURL *url = picker.pickedURL;
        NSNumber *size = nil;
        [url getResourceValue:&size forKey:NSURLFileSizeKey error:nil];
        if (size.unsignedLongLongValue > kMaxBytes)
            return [DSHHostBridgeResponse errorWithStatus:413 code:@"invalid_request"
                                                  message:[NSString stringWithFormat:@"“%@” is %.1f MB; the bridge carries at most %lu MB.",
                                                           url.lastPathComponent, size.doubleValue / 1024 / 1024, (unsigned long) (kMaxBytes / 1024 / 1024)]
                                              recoverable:NO];

        NSError *error = nil;
        NSData *data = [NSData dataWithContentsOfURL:url options:0 error:&error];
        if (data == nil)
            return [DSHHostBridgeResponse errorWithStatus:500 code:@"internal"
                                                  message:[NSString stringWithFormat:@"Could not read the chosen file: %@", error.localizedDescription]
                                              recoverable:NO];
        return [DSHHostBridgeResponse ok:@{
            @"name": url.lastPathComponent ?: @"file",
            @"bytes": @(data.length),
            @"base64": [data base64EncodedStringWithOptions:0],
        }];
    }];

    // Export: the agent chose the contents and the name, so it asks first and
    // only then shows the picker.
    [bridge registerRoute:@"POST" path:@"/v1/files/export" capability:DSHCapabilityFilesExport
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        NSString *name = request.json[@"name"];
        NSString *base64 = request.json[@"base64"];
        if (![name isKindOfClass:NSString.class] || name.length == 0 || ![base64 isKindOfClass:NSString.class])
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:@"Send a JSON body with `name` and base64-encoded `base64` contents."
                                              recoverable:NO];
        NSData *data = [[NSData alloc] initWithBase64EncodedString:base64 options:NSDataBase64DecodingIgnoreUnknownCharacters];
        if (data == nil)
            return [DSHHostBridgeResponse errorWithStatus:400 code:@"invalid_request"
                                                  message:@"`base64` is not valid base64."
                                              recoverable:NO];
        if (data.length > kMaxBytes)
            return [DSHHostBridgeResponse errorWithStatus:413 code:@"invalid_request"
                                                  message:[NSString stringWithFormat:@"That is %.1f MB; the bridge carries at most %lu MB.",
                                                           data.length / 1024.0 / 1024.0, (unsigned long) (kMaxBytes / 1024 / 1024)]
                                              recoverable:NO];
        // A name from the guest must not be able to escape the temp directory.
        NSString *safeName = [[name lastPathComponent] stringByReplacingOccurrencesOfString:@"/" withString:@"_"];
        if (safeName.length == 0 || [safeName hasPrefix:@"."])
            safeName = [@"export-" stringByAppendingString:safeName];

        DSHConfirmationOutcome outcome =
            [DSHCallConfirmation confirmTitle:@"Save a file out of DSH?"
                                       detail:[NSString stringWithFormat:@"DSH wants to save “%@” (%.1f KB). You will choose where it goes.",
                                               safeName, data.length / 1024.0]
                                   capability:DSHCapabilityFilesExport];
        DSHHostBridgeResponse *refusal = [DSHCallConfirmation refusalFor:outcome action:[NSString stringWithFormat:@"saving “%@”", safeName]];
        if (refusal)
            return refusal;

        NSURL *temporary = [[NSURL fileURLWithPath:NSTemporaryDirectory()] URLByAppendingPathComponent:safeName];
        NSError *error = nil;
        if (![data writeToURL:temporary options:NSDataWritingAtomic error:&error])
            return [DSHHostBridgeResponse errorWithStatus:500 code:@"internal"
                                                  message:[NSString stringWithFormat:@"Could not stage the file: %@", error.localizedDescription]
                                              recoverable:NO];

        DSHDocumentPicker *picker = [DSHDocumentPicker new];
        __block BOOL presented = NO;
        dispatch_sync(dispatch_get_main_queue(), ^{
            UIViewController *top = [self topViewController];
            if (top == nil)
                return;
            UIDocumentPickerViewController *controller =
                [[UIDocumentPickerViewController alloc] initForExportingURLs:@[temporary] asCopy:YES];
            controller.delegate = picker;
            [top presentViewController:controller animated:YES completion:nil];
            presented = YES;
        });
        if (!presented)
            return [self noForegroundUI];

        dispatch_semaphore_wait(picker.done, dispatch_time(DISPATCH_TIME_NOW, (int64_t) (kPickerTimeout * NSEC_PER_SEC)));
        [NSFileManager.defaultManager removeItemAtURL:temporary error:nil];
        if (picker.cancelled)
            return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                                  message:@"The user closed the save dialog without saving."
                                              recoverable:NO];
        return [DSHHostBridgeResponse ok:@{ @"saved": @YES, @"name": safeName, @"bytes": @(data.length) }];
    }];
}

@end

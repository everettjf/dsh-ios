//
//  DSHPhotosCapability.m
//  DSH
//

#import "DSHPhotosCapability.h"
#import "DSHHostBridge.h"
#import "DSHCapability.h"
#import "DSHHarness.h"
#import <UIKit/UIKit.h>
#import <PhotosUI/PhotosUI.h>
#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h>

NSString *const DSHCapabilityPhotosImport = @"photos.import";

/// The same ceiling the file routes use: the contents cross the bridge as
/// base64 in one response, and the guest has to hold it in memory to decode.
static const NSUInteger kMaxBytes = 8 * 1024 * 1024;

/// A person browsing their library takes as long as they take.
static const NSTimeInterval kPickerTimeout = 180;

#pragma mark - Picker

@interface DSHPhotoPicker : NSObject <PHPickerViewControllerDelegate>
@property (nonatomic) dispatch_semaphore_t done;
@property (nonatomic, nullable) NSData *data;
@property (nonatomic, nullable) NSString *name;
@property (nonatomic, nullable) NSString *type;
@property (nonatomic, nullable) NSString *failure;
@property (nonatomic) BOOL cancelled;
@end

@implementation DSHPhotoPicker

- (instancetype)init {
    if (self = [super init])
        _done = dispatch_semaphore_create(0);
    return self;
}

- (void)picker:(PHPickerViewController *)picker didFinishPicking:(NSArray<PHPickerResult *> *)results {
    [picker dismissViewControllerAnimated:YES completion:nil];
    PHPickerResult *result = results.firstObject;
    if (result == nil) {
        self.cancelled = YES;
        dispatch_semaphore_signal(self.done);
        return;
    }

    // Ask for the file representation rather than a UIImage: it keeps the
    // original bytes, so an agent that was handed a photo gets the photo the
    // user chose rather than a re-encoding of it.
    NSItemProvider *provider = result.itemProvider;
    NSString *identifier = [provider.registeredTypeIdentifiers containsObject:UTTypeJPEG.identifier]
        ? UTTypeJPEG.identifier
        : provider.registeredTypeIdentifiers.firstObject ?: UTTypeImage.identifier;

    __weak typeof(self) weakSelf = self;
    [provider loadFileRepresentationForTypeIdentifier:identifier
                                    completionHandler:^(NSURL *url, NSError *error) {
        typeof(self) self_ = weakSelf;
        if (self_ == nil) return;
        if (url == nil) {
            self_.failure = error.localizedDescription ?: @"the picked item could not be read";
        } else {
            NSError *readError = nil;
            NSData *data = [NSData dataWithContentsOfURL:url options:0 error:&readError];
            if (data == nil)
                self_.failure = readError.localizedDescription ?: @"the picked item could not be read";
            else {
                self_.data = data;
                self_.name = url.lastPathComponent ?: @"photo";
                self_.type = identifier;
            }
        }
        dispatch_semaphore_signal(self_.done);
    }];
}

@end

#pragma mark - Capability

@implementation DSHPhotosCapability

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

+ (void)installOn:(DSHHostBridge *)bridge {
    [DSHCapabilityRegistry.shared registerCapability:
        [[DSHCapability alloc] initWithIdentifier:DSHCapabilityPhotosImport
                                            title:@"Photos (import)"
                                          details:@"Lets the agent ask for a photo. You pick it; DSH never sees the library."
                                             gate:DSHCapabilityGateEnabledOnly
                                 enabledByDefault:YES
                                        available:YES]];

    // The picker is the confirmation, as with file import: nothing crosses the
    // bridge that the user did not choose in a system UI DSH cannot read.
    [bridge registerRoute:@"POST" path:@"/v1/photos/import" capability:DSHCapabilityPhotosImport
                  handler:^DSHHostBridgeResponse *(DSHHostBridgeRequest *request) {
        DSHPhotoPicker *picker = [DSHPhotoPicker new];
        __block BOOL presented = NO;
        DSHRunOnMainSync(^{
            UIViewController *top = [self topViewController];
            if (top == nil)
                return;
            PHPickerConfiguration *configuration = [[PHPickerConfiguration alloc] init];
            configuration.selectionLimit = 1;
            configuration.filter = PHPickerFilter.imagesFilter;
            PHPickerViewController *controller =
                [[PHPickerViewController alloc] initWithConfiguration:configuration];
            controller.delegate = picker;
            [top presentViewController:controller animated:YES completion:nil];
            presented = YES;
        });
        if (!presented)
            return [DSHHostBridgeResponse errorWithStatus:409 code:@"unavailable"
                                                  message:@"DSH is not in the foreground, so it cannot show the photo picker. Ask the user to open DSH and try again."
                                              recoverable:YES];

        dispatch_semaphore_wait(picker.done, dispatch_time(DISPATCH_TIME_NOW, (int64_t) (kPickerTimeout * NSEC_PER_SEC)));

        if (picker.cancelled)
            return [DSHHostBridgeResponse errorWithStatus:403 code:@"permission_denied"
                                                  message:@"The user closed the photo picker without choosing anything."
                                              recoverable:NO];
        if (picker.failure)
            return [DSHHostBridgeResponse errorWithStatus:500 code:@"internal"
                                                  message:[NSString stringWithFormat:@"The chosen photo could not be read: %@", picker.failure]
                                              recoverable:NO];
        if (picker.data == nil)
            return [DSHHostBridgeResponse errorWithStatus:504 code:@"timeout"
                                                  message:@"Nobody chose a photo within three minutes."
                                              recoverable:YES];
        if (picker.data.length > kMaxBytes)
            return [DSHHostBridgeResponse errorWithStatus:413 code:@"invalid_request"
                                                  message:[NSString stringWithFormat:
                                                           @"That photo is %.1f MB and the bridge carries at most %lu MB. Ask the user for a smaller one.",
                                                           picker.data.length / 1024.0 / 1024.0, (unsigned long) (kMaxBytes / 1024 / 1024)]
                                              recoverable:NO];

        [DSHHarness.shared.log append:[NSString stringWithFormat:@"[bridge] photo imported (%lu bytes)",
                                       (unsigned long) picker.data.length]];
        return [DSHHostBridgeResponse ok:@{
            @"name": picker.name ?: @"photo",
            @"type": picker.type ?: @"public.image",
            @"bytes": @(picker.data.length),
            @"base64": [picker.data base64EncodedStringWithOptions:0],
        }];
    }];
}

@end

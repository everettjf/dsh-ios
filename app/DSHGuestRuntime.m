#import "DSHGuestRuntime.h"
#import "DSHBootCoordinator.h"
#import "ISHShellExecutor.h"

static NSString *const DSHGuestRuntimeErrorDomain = @"com.xnuapp.dsh.guest";

@implementation DSHGuestRuntime

+ (void)ensureReady:(void (^)(NSError *))completion {
    dispatch_async(dispatch_get_main_queue(), ^{
        DSHBootCoordinator *boot = DSHBootCoordinator.shared;
        if (boot.phase == DSHBootPhaseReady) {
            completion(nil);
            return;
        }
        if (boot.phase == DSHBootPhaseFailed) {
            completion([NSError errorWithDomain:DSHGuestRuntimeErrorDomain
                                           code:boot.bootError
                                       userInfo:@{NSLocalizedDescriptionKey: boot.statusMessage}]);
            return;
        }
        __block id token = nil;
        token = [NSNotificationCenter.defaultCenter
            addObserverForName:DSHBootStateDidChangeNotification
                        object:boot
                         queue:NSOperationQueue.mainQueue
                    usingBlock:^(NSNotification *note) {
            if (boot.phase != DSHBootPhaseReady && boot.phase != DSHBootPhaseFailed)
                return;
            [NSNotificationCenter.defaultCenter removeObserver:token];
            if (boot.phase == DSHBootPhaseReady) {
                completion(nil);
            } else {
                completion([NSError errorWithDomain:DSHGuestRuntimeErrorDomain
                                               code:boot.bootError
                                           userInfo:@{NSLocalizedDescriptionKey: boot.statusMessage}]);
            }
        }];
        [boot start];
    });
}

+ (void)executeCommand:(NSString *)command
                timeout:(NSTimeInterval)timeout
             completion:(void (^)(NSData *))completion {
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
        ISHShellExecutionResult *result = [ISHShellExecutor executeCommandSync:command
                                                                       timeout:timeout
                                                                  lineCallback:nil];
        NSDictionary *payload = @{
            @"exit_code": @(result.exitCode),
            @"stdout": result.output ?: @"",
            @"stderr": result.errorOutput ?: @"",
            @"duration": @(result.duration),
            @"executor_error": @(result.error),
        };
        NSData *data = [NSJSONSerialization dataWithJSONObject:payload options:0 error:nil];
        completion(data ?: [@"{\"exit_code\":-1,\"stderr\":\"Could not encode command result.\"}" dataUsingEncoding:NSUTF8StringEncoding]);
    });
}

+ (void)writeData:(NSData *)data
            toPath:(NSString *)path
           timeout:(NSTimeInterval)timeout
        completion:(void (^)(NSData *))completion {
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
        // path is generated from a UUID by Swift and never contains shell syntax.
        NSString *command = [NSString stringWithFormat:@"mkdir -p /root/workspace/attachments && cat > '%@'", path];
        ISHShellExecutionResult *result = [ISHShellExecutor executeCommandSync:command
                                                                     inputData:data
                                                                       timeout:timeout
                                                                  lineCallback:nil];
        NSDictionary *payload = @{
            @"exit_code": @(result.exitCode),
            @"stdout": result.output ?: @"",
            @"stderr": result.errorOutput ?: @"",
            @"duration": @(result.duration),
            @"executor_error": @(result.error),
        };
        NSData *json = [NSJSONSerialization dataWithJSONObject:payload options:0 error:nil];
        completion(json ?: [@"{\"exit_code\":-1,\"stderr\":\"Could not encode write result.\"}" dataUsingEncoding:NSUTF8StringEncoding]);
    });
}

@end

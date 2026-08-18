//
//  DSHGuestLauncher.m
//  DSH
//

#import "DSHGuestLauncher.h"
#import "ISHShellExecutor.h"

@implementation DSHGuestLauncher

- (int)launchExecutable:(NSString *)executable
              arguments:(NSArray<NSString *> *)arguments
            environment:(NSDictionary<NSString *, NSString *> *)environment
                   line:(void (^)(NSString *, BOOL))line
                   exit:(void (^)(int))exit {
    // ISHShellExecutor forks a child of init and execs inside the guest; its
    // callbacks arrive on the main queue.
    return [ISHShellExecutor executeExecutable:executable
                                     arguments:arguments
                                   environment:environment
                                  lineCallback:^(NSString *l, BOOL isStdErr) {
        if (line) line(l, isStdErr);
    } completion:^(ISHShellExecutionResult *result) {
        if (exit) exit(result.error == ISHShellExecutorErrorNone ? result.exitCode : (int) result.error);
    }];
}

- (BOOL)killProcess:(int)pid signal:(int)signal {
    return [ISHShellExecutor killProcess:pid withSignal:signal];
}

@end

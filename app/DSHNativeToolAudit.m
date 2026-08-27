#import "DSHNativeToolAudit.h"
#import "DSHActivityLog.h"

@implementation DSHNativeToolAudit

+ (DSHActivitySource)sourceForName:(NSString *)source {
    if ([source isEqualToString:@"turn"]) return DSHActivitySourceNativeTurn;
    if ([source isEqualToString:@"model"]) return DSHActivitySourceModel;
    if ([source isEqualToString:@"mcp"]) return DSHActivitySourceMCP;
    if ([source isEqualToString:@"guest"]) return DSHActivitySourceNativeGuest;
    return DSHActivitySourceCapability;
}

+ (void)recordStartedWithSource:(NSString *)source name:(NSString *)name detail:(NSString *)detail correlationID:(NSString *)correlationID {
    [DSHActivityLog.shared recordSource:[self sourceForName:source] name:name detail:detail result:nil
                                outcome:DSHActivityOutcomeStarted duration:0 correlationID:correlationID];
}

+ (void)recordFinishedWithSource:(NSString *)source name:(NSString *)name detail:(NSString *)detail
                           result:(NSString *)result outcome:(NSString *)outcome duration:(NSTimeInterval)duration
                    correlationID:(NSString *)correlationID {
    DSHActivityOutcome value = [outcome isEqualToString:@"ok"] ? DSHActivityOutcomeOK
        : [outcome isEqualToString:@"refused"] ? DSHActivityOutcomeRefused
        : [outcome isEqualToString:@"declined"] ? DSHActivityOutcomeDeclined
        : [outcome isEqualToString:@"timed_out"] ? DSHActivityOutcomeTimedOut
        : [outcome isEqualToString:@"cancelled"] ? DSHActivityOutcomeCancelled
        : DSHActivityOutcomeError;
    [DSHActivityLog.shared recordSource:[self sourceForName:source] name:name detail:detail result:result
                                outcome:value duration:duration correlationID:correlationID];
}

+ (void)recordStarted:(NSString *)name detail:(NSString *)detail correlationID:(NSString *)correlationID {
    [self recordStartedWithSource:@"capability" name:name detail:detail correlationID:correlationID];
}

+ (void)recordFinished:(NSString *)name
                 detail:(NSString *)detail
                 result:(NSString *)result
                outcome:(NSString *)outcome
               duration:(NSTimeInterval)duration
          correlationID:(NSString *)correlationID {
    [self recordFinishedWithSource:@"capability" name:name detail:detail result:result outcome:outcome
                          duration:duration correlationID:correlationID];
}

+ (NSString *)diagnosticReport {
    NSBundle *bundle = NSBundle.mainBundle;
    NSString *version = [bundle objectForInfoDictionaryKey:@"CFBundleShortVersionString"] ?: @"unknown";
    NSString *build = [bundle objectForInfoDictionaryKey:@"CFBundleVersion"] ?: @"unknown";
    NSString *system = NSProcessInfo.processInfo.operatingSystemVersionString;
    return [NSString stringWithFormat:
        @"DSH Native Agent Diagnostics\nApp: %@ (%@)\nSystem: %@\nPrivacy: prompts, file contents, API keys, endpoints, and tool results are not included.\n\n%@",
        version, build, system, DSHActivityLog.shared.plainText];
}

@end

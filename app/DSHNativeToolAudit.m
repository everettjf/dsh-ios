#import "DSHNativeToolAudit.h"
#import "DSHActivityLog.h"

@implementation DSHNativeToolAudit

+ (void)recordStarted:(NSString *)name detail:(NSString *)detail correlationID:(NSString *)correlationID {
    [DSHActivityLog.shared recordSource:DSHActivitySourceCapability
                                   name:name
                                 detail:detail
                                 result:nil
                                outcome:DSHActivityOutcomeStarted
                               duration:0
                          correlationID:correlationID];
}

+ (void)recordFinished:(NSString *)name
                 detail:(NSString *)detail
                 result:(NSString *)result
                outcome:(NSString *)outcome
               duration:(NSTimeInterval)duration
          correlationID:(NSString *)correlationID {
    DSHActivityOutcome value = [outcome isEqualToString:@"ok"] ? DSHActivityOutcomeOK
        : [outcome isEqualToString:@"refused"] ? DSHActivityOutcomeRefused
        : [outcome isEqualToString:@"declined"] ? DSHActivityOutcomeDeclined
        : [outcome isEqualToString:@"timed_out"] ? DSHActivityOutcomeTimedOut
        : DSHActivityOutcomeError;
    [DSHActivityLog.shared recordSource:DSHActivitySourceCapability
                                   name:name
                                 detail:detail
                                 result:result
                                outcome:value
                               duration:duration
                          correlationID:correlationID];
}

@end

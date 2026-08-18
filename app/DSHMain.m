//
//  DSHMain.m
//  DSH
//

#import <UIKit/UIKit.h>
#import "DSHAppDelegate.h"
#import "ExceptionExfiltrator.h"

int main(int argc, char * argv[]) {
    NSSetUncaughtExceptionHandler(iSHExceptionHandler);
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([DSHAppDelegate class]));
    }
}

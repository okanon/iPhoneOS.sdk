//
//  WKInterfaceController.h
//  WatchKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WatchKit/WKDefines.h>

WKI_EXTERN NSString * const WatchKitErrorDomain;

typedef NS_ENUM(NSInteger, WatchKitErrorCode)  {
    WatchKitUnknownError = 1,                                           // unknown error
    WatchKitApplicationDelegateWatchKitRequestReplyNotCalledError = 2,  // in iOS app's -[UIApplicationDelegate application:handleWatchKitExtensionRequest:reply:], reply was never called

};

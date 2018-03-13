//
//  UILocalNotification.h
//  UIKit
//
//  Copyright (c) 2007-2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

@class CLRegion;

// In iOS 8.0 and later, your application must register for user notifications using -[UIApplication registerUserNotificationSettings:] before being able to schedule and present UILocalNotifications
NS_CLASS_AVAILABLE_IOS(4_0) @interface UILocalNotification : NSObject<NSCopying, NSCoding>       // added in iOS 4.0

// timer-based scheduling
@property(nonatomic,copy) NSDate *fireDate;
// the time zone to interpret fireDate in. pass nil if fireDate is an absolute GMT time (e.g. for an egg timer).
// pass a time zone to interpret fireDate as a wall time to be adjusted automatically upon time zone changes (e.g. for an alarm clock).
@property(nonatomic,copy) NSTimeZone *timeZone;

@property(nonatomic) NSCalendarUnit repeatInterval;      // 0 means don't repeat
@property(nonatomic,copy) NSCalendar *repeatCalendar;

// location-based scheduling

// set a CLRegion object to trigger the notification when the user enters or leaves a geographic region, depending upon the properties set on the CLRegion object itself. registering multiple UILocalNotifications with different regions containing the same identifier will result in undefined behavior. the number of region-triggered UILocalNotifications that may be registered at any one time is internally limited. in order to use region-triggered notifications, applications must have "when-in-use" authorization through CoreLocation. see the CoreLocation documentation for more information.
@property(nonatomic,copy) CLRegion *region NS_AVAILABLE_IOS(8_0);

// when YES, the notification will only fire one time. when NO, the notification will fire every time the region is entered or exited (depending upon the CLRegion object's configuration). default is YES.
@property(nonatomic,assign) BOOL regionTriggersOnce NS_AVAILABLE_IOS(8_0);

// alerts
@property(nonatomic,copy) NSString *alertBody;      // defaults to nil. pass a string or localized string key to show an alert
@property(nonatomic) BOOL hasAction;                // defaults to YES. pass NO to hide launching button/slider
@property(nonatomic,copy) NSString *alertAction;    // used in UIAlert button or 'slide to unlock...' slider in place of unlock
@property(nonatomic,copy) NSString *alertLaunchImage;   // used as the launch image (UILaunchImageFile) when launch button is tapped
@property(nonatomic,copy) NSString *alertTitle NS_AVAILABLE_IOS(8_2);  // defaults to nil. pass a string or localized string key

// sound
@property(nonatomic,copy) NSString *soundName;      // name of resource in app's bundle to play or UILocalNotificationDefaultSoundName

// badge
@property(nonatomic) NSInteger applicationIconBadgeNumber;  // 0 means no change. defaults to 0

// user info
@property(nonatomic,copy) NSDictionary *userInfo;   // throws if contains non-property list types

// category of the local notification, as passed to +[UIUserNotificationSettings settingsForUserNotificationTypes:userNotificationActionSettings:]
@property (nonatomic, copy) NSString *category NS_AVAILABLE_IOS(8_0);

@end


UIKIT_EXTERN NSString *const UILocalNotificationDefaultSoundName NS_AVAILABLE_IOS(4_0);

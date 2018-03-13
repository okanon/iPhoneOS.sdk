//
//  UIUserNotificationSettings.h
//  UIKit
//
//  Copyright (c) 2007-2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

typedef NS_OPTIONS(NSUInteger, UIUserNotificationType) {
    UIUserNotificationTypeNone    = 0,      // the application may not present any UI upon a notification being received
    UIUserNotificationTypeBadge   = 1 << 0, // the application may badge its icon upon a notification being received
    UIUserNotificationTypeSound   = 1 << 1, // the application may play a sound upon a notification being received
    UIUserNotificationTypeAlert   = 1 << 2, // the application may display an alert upon a notification being received
} NS_ENUM_AVAILABLE_IOS(8_0);

typedef NS_ENUM(NSUInteger, UIUserNotificationActivationMode) {
    UIUserNotificationActivationModeForeground, // activates the application in the foreground
    UIUserNotificationActivationModeBackground  // activates the application in the background, unless it's already in the foreground
} NS_ENUM_AVAILABLE_IOS(8_0);

typedef NS_ENUM(NSUInteger, UIUserNotificationActionContext) {
    UIUserNotificationActionContextDefault,  // the default context of a notification action
    UIUserNotificationActionContextMinimal   // the context of a notification action when space is limited
} NS_ENUM_AVAILABLE_IOS(8_0);

NS_CLASS_AVAILABLE_IOS(8_0)
@interface UIUserNotificationSettings : NSObject

// categories may be nil or an empty set if custom user notification actions will not be used
+ (instancetype)settingsForTypes:(UIUserNotificationType)types
                      categories:(NSSet *)categories; // instances of UIUserNotificationCategory

@property (nonatomic, readonly) UIUserNotificationType types;

// The set of UIUserNotificationCategory objects that describe the actions to show when a user notification is presented
@property (nonatomic, copy, readonly) NSSet *categories;

@end

NS_CLASS_AVAILABLE_IOS(8_0)
@interface UIUserNotificationCategory : NSObject <NSCopying, NSMutableCopying, NSSecureCoding>

// The category identifier passed in a UILocalNotification or a remote notification payload
@property (nonatomic, copy, readonly) NSString *identifier;

// UIUserNotificationActions in the order to be displayed for the specified context
- (NSArray *)actionsForContext:(UIUserNotificationActionContext)context;

@end

NS_CLASS_AVAILABLE_IOS(8_0)
@interface UIMutableUserNotificationCategory : UIUserNotificationCategory

// The category identifier passed in a UILocalNotification or a remote notification payload
@property (nonatomic, copy) NSString *identifier;

// Sets the UIUserNotificationActions in the order to be displayed for the specified context
- (void)setActions:(NSArray *)actions forContext:(UIUserNotificationActionContext)context;

@end

NS_CLASS_AVAILABLE_IOS(8_0)
@interface UIUserNotificationAction : NSObject <NSCopying, NSMutableCopying, NSSecureCoding>

// The unique identifier for this action.
@property (nonatomic, copy, readonly) NSString *identifier;

// The localized title to display for this action.
@property (nonatomic, copy, readonly) NSString *title;

// How the application should be activated in response to the action.
@property (nonatomic, assign, readonly) UIUserNotificationActivationMode activationMode;

// Whether this action is secure and should require unlocking before being performed. If the activation mode is UIUserNotificationActivationModeForeground, then the action is considered secure and this property is ignored.
@property (nonatomic, assign, readonly, getter=isAuthenticationRequired) BOOL authenticationRequired;

// Whether this action should be indicated as destructive when displayed.
@property (nonatomic, assign, readonly, getter=isDestructive) BOOL destructive;

@end

NS_CLASS_AVAILABLE_IOS(8_0)
@interface UIMutableUserNotificationAction : UIUserNotificationAction

// The unique identifier for this action.
@property (nonatomic, copy) NSString *identifier;

// The localized title to display for this action.
@property (nonatomic, copy) NSString *title;

// How the application should be activated in response to the action.
@property (nonatomic, assign) UIUserNotificationActivationMode activationMode;

// Whether this action is secure and should require unlocking before being performed. If the activation mode is UIUserNotificationActivationModeForeground, then the action is considered secure and this property is ignored.
@property (nonatomic, assign, getter=isAuthenticationRequired) BOOL authenticationRequired;

// Whether this action should be indicated as destructive when displayed.
@property (nonatomic, assign, getter=isDestructive) BOOL destructive;

@end

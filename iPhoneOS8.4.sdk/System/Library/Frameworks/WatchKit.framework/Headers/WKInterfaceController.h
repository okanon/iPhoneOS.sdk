//
//  WKInterfaceController.h
//  WatchKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <WatchKit/WKDefines.h>

@class WKInterfaceTable;
@class UIImage;
@class UILocalNotification;

typedef NS_ENUM(NSInteger, WKUserNotificationInterfaceType)  {
    WKUserNotificationInterfaceTypeDefault,
    WKUserNotificationInterfaceTypeCustom,
} NS_ENUM_AVAILABLE_IOS(8_2);

typedef NS_ENUM(NSInteger, WKMenuItemIcon)  {
    WKMenuItemIconAccept,       // checkmark
    WKMenuItemIconAdd,          // '+'
    WKMenuItemIconBlock,        // circle w/ slash
    WKMenuItemIconDecline,      // 'x'
    WKMenuItemIconInfo,         // 'i'
    WKMenuItemIconMaybe,        // '?'
    WKMenuItemIconMore,         // '...'
    WKMenuItemIconMute,         // speaker w/ slash
    WKMenuItemIconPause,        // pause button
    WKMenuItemIconPlay,         // play button
    WKMenuItemIconRepeat,       // looping arrows
    WKMenuItemIconResume,       // circular arrow
    WKMenuItemIconShare,        // share icon
    WKMenuItemIconShuffle,      // swapped arrows
    WKMenuItemIconSpeaker,      // speaker icon
    WKMenuItemIconTrash,        // trash icon
} NS_ENUM_AVAILABLE_IOS(8_2);

typedef NS_ENUM(NSInteger, WKTextInputMode)  {
    WKTextInputModePlain,		// text (no emoji) from dictation + suggestions
    WKTextInputModeAllowEmoji, 		// text plus non-animated emoji from dictation + suggestions
    WKTextInputModeAllowAnimatedEmoji,	// all text, animated emoji (GIF data)
};

WK_CLASS_AVAILABLE_IOS(8_2)
@interface WKInterfaceController : NSObject

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (void)awakeWithContext:(id)context;   // context from controller that did push or modal presentation. default does nothing

@property(nonatomic,readonly) CGRect contentFrame;

- (void)willActivate;      // Called when watch interface is visible to user (screen on and app/glance/notification running)
- (void)didDeactivate;     // Called when watch interface is no longer visible (screen off or app/glance/notification not running)

- (void)table:(WKInterfaceTable *)table didSelectRowAtIndex:(NSInteger)rowIndex;  // row selection if controller has WKInterfaceTable property
- (void)handleActionWithIdentifier:(NSString *)identifier forRemoteNotification:(NSDictionary *)remoteNotification; // when the app is launched from a notification. If launched from app icon in notification UI, identifier will be empty
- (void)handleActionWithIdentifier:(NSString *)identifier forLocalNotification:(UILocalNotification *)localNotification; // when the app is launched from a notification. If launched from app icon in notification UI, identifier will be empty
- (void)handleUserActivity:(NSDictionary *)userInfo; // called on root controller(s) with user info

- (void)setTitle:(NSString *)title;        // title of controller. displayed when controller active

- (void)pushControllerWithName:(NSString *)name context:(id)context;  // context passed to child controller via initWithContext:
- (void)popController;
- (void)popToRootController;

+ (void)reloadRootControllersWithNames:(NSArray *)names contexts:(NSArray *)contexts;
- (void)becomeCurrentPage;

- (void)presentControllerWithName:(NSString *)name context:(id)context; // modal presentation
- (void)presentControllerWithNames:(NSArray *)names contexts:(NSArray *)contexts; // modal presentation of paged controllers. contexts matched to controllers
- (void)dismissController;

- (void)presentTextInputControllerWithSuggestions:(NSArray *)suggestions allowedInputMode:(WKTextInputMode)inputMode completion:(void(^)(NSArray *results))completion; // results is nil if cancelled
- (void)dismissTextInputController;

- (id)contextForSegueWithIdentifier:(NSString *)segueIdentifier;
- (NSArray *)contextsForSegueWithIdentifier:(NSString *)segueIdentifier;
- (id)contextForSegueWithIdentifier:(NSString *)segueIdentifier inTable:(WKInterfaceTable *)table rowIndex:(NSInteger)rowIndex;
- (NSArray *)contextsForSegueWithIdentifier:(NSString *)segueIdentifier inTable:(WKInterfaceTable *)table rowIndex:(NSInteger)rowIndex;

- (void)addMenuItemWithImage:(UIImage *)image title:(NSString *)title action:(SEL)action;           // all parameters must be non-nil
- (void)addMenuItemWithImageNamed:(NSString *)imageName title:(NSString *)title action:(SEL)action;
- (void)addMenuItemWithItemIcon:(WKMenuItemIcon)itemIcon title:(NSString *)title action:(SEL)action;
- (void)clearAllMenuItems;

- (void)updateUserActivity:(NSString *)type userInfo:(NSDictionary *)userInfo webpageURL:(NSURL *)webpageURL;  // provide type and info to Handoff. userInfo and webpageUrl are passed to the application receiving the Handoff
- (void)invalidateUserActivity;

+ (BOOL)openParentApplication:(NSDictionary *)userInfo reply:(void(^)(NSDictionary *replyInfo, NSError *error)) reply;    // launches containing iOS application on the phone. userInfo must be non-nil

@end

WK_CLASS_AVAILABLE_IOS(8_2)
@interface WKUserNotificationInterfaceController : WKInterfaceController

- (instancetype)init;
- (void)didReceiveRemoteNotification:(NSDictionary *)remoteNotification withCompletion:(void(^)(WKUserNotificationInterfaceType interface)) completionHandler;
- (void)didReceiveLocalNotification:(UILocalNotification *)localNotification withCompletion:(void(^)(WKUserNotificationInterfaceType interface)) completionHandler;

@end

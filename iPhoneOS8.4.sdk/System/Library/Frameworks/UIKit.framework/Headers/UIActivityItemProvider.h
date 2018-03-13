//
//  UIActivityItemProvider.h
//  UIKit
//
//  Copyright 2012-2014 Apple Inc. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

@class UIActivityViewController, UIImage;

@protocol UIActivityItemSource <NSObject>

@required

- (id)activityViewControllerPlaceholderItem:(UIActivityViewController *)activityViewController;	// called to determine data type. only the class of the return type is consulted. it should match what -itemForActivityType: returns later
- (id)activityViewController:(UIActivityViewController *)activityViewController itemForActivityType:(NSString *)activityType;	// called to fetch data after an activity is selected. you can return nil.

@optional

- (NSString *)activityViewController:(UIActivityViewController *)activityViewController subjectForActivityType:(NSString *)activityType; // if activity supports a Subject field. iOS 7.0
- (NSString *)activityViewController:(UIActivityViewController *)activityViewController dataTypeIdentifierForActivityType:(NSString *)activityType; // UTI for item if it is an NSData. iOS 7.0. will be called with nil activity and then selected activity
- (UIImage *)activityViewController:(UIActivityViewController *)activityViewController thumbnailImageForActivityType:(NSString *)activityType suggestedSize:(CGSize)size; // if activity supports preview image. iOS 7.0

@end

NS_CLASS_AVAILABLE_IOS(6_0) @interface UIActivityItemProvider : NSOperation <UIActivityItemSource>

- (instancetype)initWithPlaceholderItem:(id)placeholderItem;               // placeHolder is the return value for -activityViewControllerPlaceholderItem:

@property(nonatomic,retain,readonly) id        placeholderItem;
@property(nonatomic,readonly)        NSString *activityType;     // activity type available when -item is called. nil at other times. use this in your -item method to customize the data to return

- (id)item;   // called on secondary thread when user selects an activity. you must subclass and return a non-nil value. The item can use the UIActivityItemSource protocol to return extra information

@end

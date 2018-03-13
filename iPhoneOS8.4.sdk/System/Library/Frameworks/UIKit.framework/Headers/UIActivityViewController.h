//
//  UIActivityViewController.h
//  UIKit
//
//  Copyright 2012-2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIViewController.h>
#import <UIKit/UIKitDefines.h>

typedef void (^UIActivityViewControllerCompletionHandler)(NSString *activityType, BOOL completed);
typedef void (^UIActivityViewControllerCompletionWithItemsHandler)(NSString *activityType, BOOL completed, NSArray *returnedItems, NSError *activityError);

NS_CLASS_AVAILABLE_IOS(6_0) @interface UIActivityViewController : UIViewController

- (instancetype)initWithActivityItems:(NSArray *)activityItems applicationActivities:(NSArray *)applicationActivities;

@property(nonatomic,copy) UIActivityViewControllerCompletionHandler completionHandler NS_DEPRECATED_IOS(6_0, 8_0, "Use completionWithItemsHandler instead.");  // set to nil after call
@property(nonatomic,copy) UIActivityViewControllerCompletionWithItemsHandler completionWithItemsHandler NS_AVAILABLE_IOS(8_0); // set to nil after call
@property(nonatomic,copy) NSArray *excludedActivityTypes; // default is nil. activity types listed will not be displayed

@end

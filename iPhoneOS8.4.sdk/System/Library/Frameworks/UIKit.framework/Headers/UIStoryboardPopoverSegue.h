//
//  UIStoryboardPopoverSegue.h
//  UIKit
//
//  Copyright 2011-2012 Apple Inc. All rights reserved.
//

#import <UIKit/UIStoryboardSegue.h>

@class UIPopoverController;

NS_CLASS_AVAILABLE_IOS(5_0) @interface UIStoryboardPopoverSegue : UIStoryboardSegue {
}

@property (nonatomic, retain, readonly) UIPopoverController *popoverController;

@end

//
//  WKInterfaceSwitch.h
//  WatchKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WatchKit/WKDefines.h>
#import <WatchKit/WKInterfaceObject.h>

WK_CLASS_AVAILABLE_IOS(8_2)
@interface WKInterfaceSwitch : WKInterfaceObject

- (void)setTitle:(NSString *)title;
- (void)setAttributedTitle:(NSAttributedString *)attributedTitle;

- (void)setEnabled:(BOOL)enabled;
- (void)setOn:(BOOL)on;
- (void)setColor:(UIColor *)color;

@end

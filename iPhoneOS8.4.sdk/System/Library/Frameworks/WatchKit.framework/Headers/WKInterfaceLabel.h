//
//  WKInterfaceLabel.h
//  WatchKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WatchKit/WKDefines.h>
#import <WatchKit/WKInterfaceObject.h>

@class UIColor;

WK_CLASS_AVAILABLE_IOS(8_2)
@interface WKInterfaceLabel : WKInterfaceObject

- (void)setText:(NSString *)text;
- (void)setTextColor:(UIColor *)color;

- (void)setAttributedText:(NSAttributedString *)attributedText;

@end

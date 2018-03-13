//
//  WKInterfaceTimer.h
//  WatchKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <WatchKit/WatchKit.h>
#import <WatchKit/WKDefines.h>
#import <WatchKit/WKInterfaceObject.h>

@class UIColor;

WK_CLASS_AVAILABLE_IOS(8_2)
@interface WKInterfaceTimer : WKInterfaceObject

- (void)setTextColor:(UIColor *)color;

- (void)setDate:(NSDate *)date; // count up/down from current date to this date
- (void)start;
- (void)stop;

@end

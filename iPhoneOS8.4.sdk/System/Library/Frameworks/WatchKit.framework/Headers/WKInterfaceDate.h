//
//  WKInterfaceDate.h
//  WatchKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <WatchKit/WatchKit.h>
#import <WatchKit/WKDefines.h>
#import <WatchKit/WKInterfaceObject.h>

@class UIColor;

WK_CLASS_AVAILABLE_IOS(8_2)
@interface WKInterfaceDate : WKInterfaceObject

- (void)setTextColor:(UIColor *)color;

- (void)setTimeZone:(NSTimeZone *)timeZone;
- (void)setCalendar:(NSCalendar *)calendar;

@end

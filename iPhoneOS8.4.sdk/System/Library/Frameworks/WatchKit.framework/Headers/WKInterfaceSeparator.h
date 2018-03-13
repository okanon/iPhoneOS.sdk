//
//  WKInterfaceSeparator.h
//  WatchKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <WatchKit/WKDefines.h>
#import <WatchKit/WKInterfaceObject.h>

@class UIColor;

WK_CLASS_AVAILABLE_IOS(8_2)
@interface WKInterfaceSeparator : WKInterfaceObject

- (void)setColor:(UIColor *)color;

@end

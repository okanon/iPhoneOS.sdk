//
//  WKInterfaceObject.h
//  WatchKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIAccessibility.h>
#import <WatchKit/WKDefines.h>

WK_CLASS_AVAILABLE_IOS(8_2)
@interface WKInterfaceObject : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (void)setHidden:(BOOL)hidden;
- (void)setAlpha:(CGFloat)alpha;

- (void)setWidth:(CGFloat)width;   // setting to 0 means use natural size. ignored for table
- (void)setHeight:(CGFloat)height;

@property(nonatomic,readonly,copy) NSString *interfaceProperty;   // same as controller's property name

@end

@interface WKInterfaceObject (WKAccessibility)

- (void)setAccessibilityLabel:(NSString *)accessibilityLabel;
- (void)setAccessibilityHint:(NSString *)accessibilityHint;
- (void)setAccessibilityValue:(NSString *)accessibilityValue;
- (void)setIsAccessibilityElement:(BOOL)isAccessibilityElement;
- (void)setAccessibilityTraits:(UIAccessibilityTraits)accessibilityTraits;
- (void)setAccessibilityImageRegions:(NSArray *)accessibilityImageRegions;          // array of WKAccessibilityImageRegion. copied

@end

WK_CLASS_AVAILABLE_IOS(8_2)
@interface WKAccessibilityImageRegion : NSObject

@property(nonatomic)      CGRect    frame;
@property(nonatomic,copy) NSString *label;

@end

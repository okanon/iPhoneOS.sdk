//
//  WKInterfaceMap.h
//  WatchKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
#import <WatchKit/WKDefines.h>
#import <WatchKit/WKInterfaceObject.h>

typedef NS_ENUM(NSInteger, WKInterfaceMapPinColor) {
    WKInterfaceMapPinColorRed,
    WKInterfaceMapPinColorGreen,
    WKInterfaceMapPinColorPurple,
} NS_ENUM_AVAILABLE_IOS(8_2);

WK_CLASS_AVAILABLE_IOS(8_2)
@interface WKInterfaceMap : WKInterfaceObject

- (void)setVisibleMapRect:(MKMapRect)mapRect;
- (void)setRegion:(MKCoordinateRegion)coordinateRegion;

- (void)addAnnotation:(CLLocationCoordinate2D)location withImage:(UIImage *)image centerOffset:(CGPoint)offset;
- (void)addAnnotation:(CLLocationCoordinate2D)location withImageNamed:(NSString *)name centerOffset:(CGPoint)offset;
- (void)addAnnotation:(CLLocationCoordinate2D)location withPinColor:(WKInterfaceMapPinColor)pinColor;
- (void)removeAllAnnotations;

@end

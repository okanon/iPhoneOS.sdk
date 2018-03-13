//
//  MKUserTrackingBarButtonItem.h
//  MapKit
//
//  Copyright (c) 2010-2014, Apple Inc. All rights reserved.
//

#import <UIKit/UIBarButtonItem.h>
#import <MapKit/MKFoundation.h>

@class MKMapView;

MK_CLASS_AVAILABLE(NA, 5_0)
@interface MKUserTrackingBarButtonItem : UIBarButtonItem

- (instancetype)initWithMapView:(MKMapView *)mapView NS_DESIGNATED_INITIALIZER;
@property (nonatomic, strong) MKMapView *mapView;

@end

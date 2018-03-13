//
//  HKCorrelation.h
//  HealthKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <HealthKit/HKSample.h>

@class HKObjectType;
@class HKCorrelationType;

/*!
 @class         HKCorrelation
 @abstract      An HKCorrelation is a collection of correlated objects.
 @discussion    When multiple readings are taken together, it may be beneficial to correlate them so that they can be
                displayed together and share common metadata about how they were created.
 
                For example, systolic and diastolic blood pressure readings are typically presented together so these
                readings should be saved with a correlation of type blood pressure.
 */
HK_CLASS_AVAILABLE_IOS(8_0)
@interface HKCorrelation : HKSample <NSSecureCoding>

@property (readonly) HKCorrelationType *correlationType;

/*!
 @property  objects
 @abstract  A set of HKSamples containing all of the objects that were saved with the receiver.
 */
@property (readonly, copy) NSSet *objects;

/*!
 @method        correlationWithType:startDate:endDate:objects:metadata:
 @abstract      Creates a new HKCorrelation with the given type, start date, end date, and objects.
 @discussion    objects must be a set of HKQuantitySamples and HKCategorySamples
 */
+ (instancetype)correlationWithType:(HKCorrelationType *)correlationType
                          startDate:(NSDate *)startDate
                            endDate:(NSDate *)endDate
                            objects:(NSSet *)objects;

/*!
 @method        correlationWithType:startDate:endDate:objects:metadata:
 @abstract      Creates a new HKCorrelation with the given type, start date, end date, objects, and metadata.
 @discussion    objects must be a set of HKQuantitySamples and HKCategorySamples
 */
+ (instancetype)correlationWithType:(HKCorrelationType *)correlationType
                          startDate:(NSDate *)startDate
                            endDate:(NSDate *)endDate
                            objects:(NSSet *)objects
                           metadata:(NSDictionary *)metadata;

/*!
 @method    objectsForType:
 @abstract  Returns the set of correlated objects with the specified type.
 */
- (NSSet *)objectsForType:(HKObjectType *)objectType;

@end

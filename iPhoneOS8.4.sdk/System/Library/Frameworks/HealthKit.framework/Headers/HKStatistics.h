//
//  HKStatistics.h
//  HealthKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <HealthKit/HKDefines.h>

@class HKQuantity;
@class HKQuantityType;
@class HKSource;

/*!
 @enum          HKStatisticsOptions
 @abstract      Options for specifying which statistics to calculate
 @discussion    When querying for HKStatistics objects, an options bitmask will specify which statistics will be calculated.
 
                Statistics are classified as discrete or cumulative.  If a discrete statistics option is specified for a
                cumulative HKQuantityType, an exception will be thrown.  If a cumulative statistics options is specified
                for a discrete HKQuantityType, an exception will also be thrown.
 
 @constant      HKStatisticsOptionNone
 @constant      HKStatisticsOptionSeparateBySource
 @constant      HKStatisticsOptionDiscreteAverage   Calculate averageQuantity when creating statistics.
 @constant      HKStatisticsOptionDiscreteMin       Calculate minQuantity when creating statistics.
 @constant      HKStatisticsOptionDiscreteMax       Calculate maxQuantity when creating statistics.
 @constant      HKStatisticsOptionCumulativeSum     Calculate sumQuantity when creating statistics.
 */
typedef NS_OPTIONS(NSUInteger, HKStatisticsOptions) {
    HKStatisticsOptionNone              		= 0,
    HKStatisticsOptionSeparateBySource          = 1 << 0,
    HKStatisticsOptionDiscreteAverage           = 1 << 1,
    HKStatisticsOptionDiscreteMin               = 1 << 2,
    HKStatisticsOptionDiscreteMax               = 1 << 3,
    HKStatisticsOptionCumulativeSum             = 1 << 4,
} NS_ENUM_AVAILABLE_IOS(8_0);

/*!
 @class         HKStatistics
 @abstract      Represents statistics for quantity samples over a period of time.
 */
HK_CLASS_AVAILABLE_IOS(8_0)
@interface HKStatistics : NSObject <NSSecureCoding, NSCopying>

@property (readonly, strong) HKQuantityType *quantityType;
@property (readonly, strong) NSDate *startDate;
@property (readonly, strong) NSDate *endDate;
@property (readonly, strong) NSArray *sources;

- (instancetype)init NS_UNAVAILABLE;

/* Discrete Quantities */

/*!
 @method        averageQuantityForSource:
 @abstract      Returns the average quantity for the given source in the time period represented by the receiver.
 @discussion    If HKStatisticsOptionSeparateBySource is not specified, then this will always be nil.
 */
- (HKQuantity *)averageQuantityForSource:(HKSource *)source;

/*!
 @method        averageQuantityForSource:
 @abstract      Returns the average quantity in the time period represented by the receiver.
 */
- (HKQuantity *)averageQuantity;

/*!
 @method        minimumQuantityForSource:
 @abstract      Returns the minimum quantity for the given source in the time period represented by the receiver.
 @discussion    If HKStatisticsOptionSeparateBySource is not specified, then this will always be nil.
 */
- (HKQuantity *)minimumQuantityForSource:(HKSource *)source;

/*!
 @method        averageQuantityForSource:
 @abstract      Returns the minimum quantity in the time period represented by the receiver.
 */
- (HKQuantity *)minimumQuantity;

/*!
 @method        maximumQuantityForSource:
 @abstract      Returns the maximum quantity for the given source in the time period represented by the receiver.
 @discussion    If HKStatisticsOptionSeparateBySource is not specified, then this will always be nil.
 */
- (HKQuantity *)maximumQuantityForSource:(HKSource *)source;

/*!
 @method        averageQuantityForSource:
 @abstract      Returns the maximum quantity in the time period represented by the receiver.
 */
- (HKQuantity *)maximumQuantity;

/* Cumulative Quantities */

/*!
 @method        sumQuantityForSource:
 @abstract      Returns the sum quantity for the given source in the time period represented by the receiver.
 @discussion    If HKStatisticsOptionSeparateBySource is not specified, then this will always be nil.
 */
- (HKQuantity *)sumQuantityForSource:(HKSource *)source;

/*!
 @method        averageQuantityForSource:
 @abstract      Returns the sum of quantities in the time period represented by the receiver.
 */
- (HKQuantity *)sumQuantity;

@end

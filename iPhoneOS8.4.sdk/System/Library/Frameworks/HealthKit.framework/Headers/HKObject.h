//
//  HKObject.h
//  HealthKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <HealthKit/HKDefines.h>
#import <Foundation/Foundation.h>

@class HKSource;

HK_CLASS_AVAILABLE_IOS(8_0)
@interface HKObject : NSObject <NSSecureCoding>

/*!
 @property      UUID
 @abstract      A unique identifier of the receiver in the HealthKit database.
 */
@property (readonly, strong) NSUUID *UUID;

/*!
 @property      source
 @abstract      Represents the entity that created the receiver.
 @discussion    The source may be the application or device that created the receiver.
 */
@property (readonly, strong) HKSource *source;

/*!
 @property      metadata
 @abstract      Extra information describing properties of the receiver.
 @discussion    Keys must be NSString and values must be either NSString, NSNumber, or NSDate.
                See HKMetadata.h for potential metadata keys and values.
 */
@property (readonly, copy) NSDictionary *metadata;

- (instancetype)init NS_UNAVAILABLE;

@end

// Predicate Key Paths
HK_EXTERN NSString * const HKPredicateKeyPathUUID NS_AVAILABLE_IOS(8_0);
HK_EXTERN NSString * const HKPredicateKeyPathSource NS_AVAILABLE_IOS(8_0);
HK_EXTERN NSString * const HKPredicateKeyPathMetadata NS_AVAILABLE_IOS(8_0);
HK_EXTERN NSString * const HKPredicateKeyPathCorrelation NS_AVAILABLE_IOS(8_0);
HK_EXTERN NSString * const HKPredicateKeyPathWorkout NS_AVAILABLE_IOS(8_0);

//
//  HKAnchoredObjectQuery.h
//  HealthKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <HealthKit/HKQuery.h>

#define HKAnchoredObjectQueryNoAnchor (0)

/*!
 @class     HKAnchoredObjectQuery
 */
HK_CLASS_AVAILABLE_IOS(8_0)
@interface HKAnchoredObjectQuery : HKQuery

- (instancetype)initWithType:(HKSampleType *)type
                   predicate:(NSPredicate *)predicate
                      anchor:(NSUInteger)anchor
                       limit:(NSUInteger)limit
           completionHandler:(void(^)(HKAnchoredObjectQuery *query, NSArray *results, NSUInteger newAnchor, NSError *error))handler;
@end

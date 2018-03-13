// HMCharacteristicWriteAction.h
// HomeKit
//
// Copyright (c) 2014 Apple Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <HomeKit/HMAction.h>

@class HMCharacteristic;

/*!
 * @brief This class is used to represent an entry in an action set that writes a specific
 *        value to a characteristic.
 */
NS_CLASS_AVAILABLE_IOS(8_0)
@interface HMCharacteristicWriteAction : HMAction

- (instancetype)init NS_UNAVAILABLE;

/*!
 * @brief Initializer method that ties the action to a particular characteristic.
 *
 * @param characteristic The characteristic bound to the action.
 *
 * @param targetValue The target value for the characteristic.
 *
 * @return Instance object if input parameters are valid; nil otherwise
 */
- (instancetype)initWithCharacteristic:(HMCharacteristic *)characteristic targetValue:(id)targetValue NS_DESIGNATED_INITIALIZER;

/*!
 * @brief The characteristic associated with the action.
 */
@property(readonly, strong, nonatomic) HMCharacteristic* characteristic;

/*!
 * @brief The target value for the action.
 */
@property(readonly, copy, nonatomic) id targetValue;

/*!
 * @brief This method is used to change target value for the characteristic.
 *
 * @param value New target value for the characteristic.
 *
 * @param completion Block that is invoked once the request is processed. 
 *                   The NSError provides more information on the status of the request, error
 *                   will be nil on success.
 */
- (void)updateTargetValue:(id)targetValue completionHandler:(void (^)(NSError *error))completion;

@end


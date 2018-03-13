// HMService.h
// HomeKit
//
// Copyright (c) 2013-2014 Apple Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <HomeKit/HMDefines.h>

@class HMAccessory;
@class HMCharacteristic;

/*!
 * @brief Represents a service provided by an accessory.
 *
 * @discussion This class represents a service provided by an accessory in the home.
 *             A service is composed of one or more characteristics that can be 
 *             modified.
 */
NS_CLASS_AVAILABLE_IOS(8_0)
@interface HMService : NSObject

/*!
 * @brief Accessory that provides this service.
 */
@property(readonly, weak, nonatomic) HMAccessory *accessory;

/*!
 * @brief The type of the service, e.g. HMServiceTypeLightbulb.
 */
@property(readonly, copy, nonatomic) NSString *serviceType;

/*!
 * @brief Name for the service.
 *
 * @discussion Returns the service's name that is associated with HomeKit. The initial value is the value of
 *             the name characteristic of the service, if it has one.
 */
@property(readonly, copy, nonatomic) NSString *name;

/*!
 * @brief For HMServiceTypeOutlet and HMServiceTypeSwitch, this is the type of the associated service.
 *
 * @discussion This could be any of the HomeKit Accessory Profile defined services (except HMServiceTypeOutlet
 *             or HMServiceTypeSwitch) that supports HMCharacteristicTypePowerState characteristic.
 */
@property(readonly, copy, nonatomic) NSString *associatedServiceType;

/*!
 * @brief Array of HMCharacteristic objects that represents all the characteristics
 *        provided by the service.
 */
@property(readonly, copy, nonatomic) NSArray *characteristics;

/*!
 * @brief This method is used to change the name of the service.
 *
 * @param name New name for the service.
 *
 * @discussion The new name is stored in HomeKit and not on the accessory.
 *
 * @param completion Block that is invoked once the request is processed. 
 *                   The NSError provides more information on the status of the request, error
 *                   will be nil on success.
 */
- (void)updateName:(NSString *)name completionHandler:(void (^)(NSError *error))completion;

/*!
 * @brief This method is used to set up the service type of the device connected to a switch or an outlet.
 *
 * @param serviceType Service type of the device connected to a switch/outlet service.
 *
 * @discussion This method is only valid for services of type HMServiceTypeOutlet and HMServiceTypeSwitch.
 *             serviceType can be any of the HomeKit Accessory Profile defined services (except HMServiceTypeOutlet
 *             or HMServiceTypeSwitch) that supports HMCharacteristicTypePowerState characteristic.
 *
 * @param completion Block that is invoked once the request is processed.
 *                   The NSError provides more information on the status of the request, error
 *                   will be nil on success.
 */
- (void)updateAssociatedServiceType:(NSString *)serviceType completionHandler:(void (^)(NSError *error))completion;

@end

/*!
 * @group Accessory Service Types
 *
 * @brief These constants define the service types supported by the HomeKit Accessory Profile for HomeKit based accessories.
 */

/*!
 * @brief Service type for lightbulb.
 */
HM_EXTERN NSString * const HMServiceTypeLightbulb NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Service type for switch.
 */
HM_EXTERN NSString * const HMServiceTypeSwitch NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Service type for thermostat.
 */
HM_EXTERN NSString * const HMServiceTypeThermostat NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Service type for garage door opener.
 */
HM_EXTERN NSString * const HMServiceTypeGarageDoorOpener NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Service type for accessory information.
 */
HM_EXTERN NSString * const HMServiceTypeAccessoryInformation NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Service type for fan.
 */
HM_EXTERN NSString * const HMServiceTypeFan NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Service type for outlet.
 */
HM_EXTERN NSString * const HMServiceTypeOutlet NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Service type for lock mechanism.
 */
HM_EXTERN NSString * const HMServiceTypeLockMechanism NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Service type for lock management.
 */
HM_EXTERN NSString * const HMServiceTypeLockManagement NS_AVAILABLE_IOS(8_0);


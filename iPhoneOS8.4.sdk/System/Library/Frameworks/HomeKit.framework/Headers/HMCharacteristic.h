// HMCharacteristic.h
// HomeKit
//
// Copyright (c) 2013-2014 Apple Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <HomeKit/HMDefines.h>

@class HMAccessory;
@class HMService;
@class HMCharacteristicMetadata;

/*!
 * @brief Represent a characteristic on a service of an accessory.
 */
NS_CLASS_AVAILABLE_IOS(8_0)
@interface HMCharacteristic : NSObject

/*!
 * @brief The type of the characteristic, e.g. HMCharacteristicTypePowerState.
 */
@property(readonly, copy, nonatomic) NSString *characteristicType;

/*!
 * @brief Service that contains this characteristic.
 */
@property(weak, readonly, nonatomic) HMService *service;

/*!
 * @brief Array that describes the properties of the characteristic.
 *
 * @discussion This value corresponds to the properties associated with this characteristic.
 *             The contents of the array are one or more HMCharacteristicProperty constants.
 */
@property(readonly, copy, nonatomic) NSArray *properties;

/*!
 * @brief Meta data associated with the characteristic.
 */
@property(readonly, strong, nonatomic) HMCharacteristicMetadata *metadata;

/*!
 * @brief The value of the characteristic.
 *
 * @discussion The value is a cached value that may have been updated as a result of prior
 *             interaction with the accessory.
 */
@property(readonly, copy, nonatomic) id value;

/*!
 * @brief Specifies whether the characteristic has been enabled to send notifications.
 *
 * @discussion This property is reset to NO if the reachability of the accessory is NO.
 */
@property(readonly, getter=isNotificationEnabled, nonatomic) BOOL notificationEnabled;

/*!
 * @brief Modifies the value of the characteristic.
 *
 * @param value The value to be written.
 *
 * @param completion Block that is invoked once the request is processed. 
 *                   The NSError provides more information on the status of the request, error
 *                   will be nil on success.
 *
 * @discussion The value being written is validated against the metadata, format and permissions.
 *             The value written may be bounded by metadata for characteristics with int and 
 *             float format. If validation fails, the error provided to the completion handler
 *             indicates the type of failure.
 */
- (void)writeValue:(id)value completionHandler:(void (^)(NSError *error))completion;

/*!
 * @brief Reads the value of the characteristic. The updated value can be read from the 'value' property of the characteristic.
 *
 * @param completion Block that is invoked once the request is processed. 
 *                   The NSError provides more information on the status of the request, error
 *                   will be nil on success.
 */
- (void)readValueWithCompletionHandler:(void (^)(NSError *error))completion;

/*!
 * @brief Enables/disables notifications or indications for the value of a specified characteristic.
 *
 * @param enabled A Boolean value indicating whether you wish to receive notifications or 
 *                indications whenever the characteristic’s value changes.
 *
 * @param completion Block that is invoked once the request is processed. 
 *                   The NSError provides more information on the status of the request, error
 *                   will be nil on success.
 */
- (void)enableNotification:(BOOL)enable completionHandler:(void (^)(NSError *error))completion;

/*!
 * @brief Sets/clears authorization data used when writing to the characteristic.
 *
 * @param data New authorization data to use. Specify nil to remove authorization data.
 *
 * @param completion Block that is invoked once the request is processed. 
 *                   The NSError provides more information on the status of the request, error
 *                   will be nil on success.
 */
- (void)updateAuthorizationData:(NSData *)data completionHandler:(void (^)(NSError *error))completion;

@end

/*!
 * @brief This constant specifies that the characteristic supports notifications
 *        using the event connection established by the controller. The
 *        event connection provides unidirectional communication from the
 *        accessory to the controller.
 */
HM_EXTERN NSString * const HMCharacteristicPropertySupportsEventNotification NS_AVAILABLE_IOS(8_0);

/*!
 * @brief This constant specifies that the characteristic is readable.
 */
HM_EXTERN NSString * const HMCharacteristicPropertyReadable NS_AVAILABLE_IOS(8_0);

/*!
 * @brief This constant specifies that the characteristic is writable.
 */
HM_EXTERN NSString * const HMCharacteristicPropertyWritable NS_AVAILABLE_IOS(8_0);


/*!
 * @group Accessory Service Characteristic Types
 *
 * @brief These constants define the characteristic types supported by the HomeKit Accessory Profile for HomeKit based accessories.
 */

/*!
 * @brief Characteristic type for power state. The value of the characteristic is a boolean.
 */
HM_EXTERN NSString * const HMCharacteristicTypePowerState NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for hue. The value of the characteristic is a float value in arc degrees.
 */
HM_EXTERN NSString * const HMCharacteristicTypeHue NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for saturation. The value of the characteristic is a float value in percent.
 */
HM_EXTERN NSString * const HMCharacteristicTypeSaturation NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for brightness. The value of the characteristic is an int value in percent.
 */
HM_EXTERN NSString * const HMCharacteristicTypeBrightness NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for temperature units. The value of the characteristic is one of the values
 *        defined for HMCharacteristicValueTemperatureUnit.
 */
HM_EXTERN NSString * const HMCharacteristicTypeTemperatureUnits NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for current temperature. The value of the characteristic is a float value in Celsius.
 */
HM_EXTERN NSString * const HMCharacteristicTypeCurrentTemperature NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for target temperature. The value of the characteristic is a float value in Celsius.
 */
HM_EXTERN NSString * const HMCharacteristicTypeTargetTemperature NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for heating/cooling mode. The value of the characteristic is one of the values
 *        defined for HMCharacteristicValueHeatingCooling and indicates the current heating/cooling mode.
 */
HM_EXTERN NSString * const HMCharacteristicTypeCurrentHeatingCooling NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for target heating/cooling mode. The value of the characteristic is one of the values
 *        defined for HMCharacteristicValueHeatingCooling and indicates the target heating/cooling mode.
 */
HM_EXTERN NSString * const HMCharacteristicTypeTargetHeatingCooling NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for cooling threshold temperature. The value of the characteristic is a float value in Celsius.
 */
HM_EXTERN NSString * const HMCharacteristicTypeCoolingThreshold NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for heating threshold temperature. The value of the characteristic is a float value in Celsius.
 */
HM_EXTERN NSString * const HMCharacteristicTypeHeatingThreshold NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for current relative humidity. The value of the characteristic is a float value in percent.
 */
HM_EXTERN NSString * const HMCharacteristicTypeCurrentRelativeHumidity NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for target relative humidity. The value of the characteristic is a float value in percent.
 */
HM_EXTERN NSString * const HMCharacteristicTypeTargetRelativeHumidity NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for current door state. The value of the characteristic is one of the values
 *        defined for HMCharacteristicValueDoorState and indicates the current door state.
 */
HM_EXTERN NSString * const HMCharacteristicTypeCurrentDoorState NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for target door state. The value of the characteristic is one of the values
 *        defined for HMCharacteristicValueDoorState and indicates the target door state.
 */
HM_EXTERN NSString * const HMCharacteristicTypeTargetDoorState NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for obstruction detected. The value of the characteristic is a boolean value.
 */
HM_EXTERN NSString * const HMCharacteristicTypeObstructionDetected NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for name. The value of the characteristic is a string.
 */
HM_EXTERN NSString * const HMCharacteristicTypeName NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for manufacturer. The value of the characteristic is a string.
 */
HM_EXTERN NSString * const HMCharacteristicTypeManufacturer NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for model. The value of the characteristic is a string.
 */
HM_EXTERN NSString * const HMCharacteristicTypeModel NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for serial number. The value of the characteristic is a string.
 */
HM_EXTERN NSString * const HMCharacteristicTypeSerialNumber NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for identify. The characteristic is write-only that takes a boolean.
 */
HM_EXTERN NSString * const HMCharacteristicTypeIdentify NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for rotation direction. The value of the characteristic is one of the values
 *        defined for HMCharacteristicValueRotationDirection and indicates the fan rotation direction.
 */
HM_EXTERN NSString * const HMCharacteristicTypeRotationDirection NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for rotation speed. The value of the characteristic is a float representing
          the percentage of maximum speed.
 */
HM_EXTERN NSString * const HMCharacteristicTypeRotationSpeed NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for outlet in use. The value of the characteristic is a boolean, which is true
 *        if the outlet is in use.
 */
HM_EXTERN NSString * const HMCharacteristicTypeOutletInUse NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for version. The value of the characteristic is a string.
 */
HM_EXTERN NSString * const HMCharacteristicTypeVersion NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for logs. The value of the characteristic is TLV8 data wrapped in an NSData.
 */
HM_EXTERN NSString * const HMCharacteristicTypeLogs NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for audio feedback. The value of the characteristic is a boolean.
 */
HM_EXTERN NSString * const HMCharacteristicTypeAudioFeedback NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for admin only access. The value of the characteristic is a boolean.
 */
HM_EXTERN NSString * const HMCharacteristicTypeAdminOnlyAccess NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for motion detected. The value of the characteristic is a boolean.
 */
HM_EXTERN NSString * const HMCharacteristicTypeMotionDetected NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for current lock mechanism state. The value of the characteristic is one of the values
 *        defined for HMCharacteristicValueLockMechanismState.

 */
HM_EXTERN NSString * const HMCharacteristicTypeCurrentLockMechanismState NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for target lock mechanism state. The value of the characteristic is either
 *        HMCharacteristicValueLockMechanismStateUnsecured, or HMCharacteristicValueLockMechanismStateSecured,
 *        as defined by HMCharacteristicValueLockMechanismState.
 */
HM_EXTERN NSString * const HMCharacteristicTypeTargetLockMechanismState NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for the last known action for a lock mechanism. The value of the characteristic is one of the values
 *        defined for HMCharacteristicValueLockMechanismLastKnownAction.
 */
HM_EXTERN NSString * const HMCharacteristicTypeLockMechanismLastKnownAction NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for the control point for lock management. The characteristic is write-only that takes TLV8 data wrapped in an NSData.
 */
HM_EXTERN NSString * const HMCharacteristicTypeLockManagementControlPoint NS_AVAILABLE_IOS(8_0);

/*!
 * @brief Characteristic type for the auto secure timeout for lock management. The value of the characteristic is an unsigned 32-bit integer representing the number of seconds.
 */
HM_EXTERN NSString * const HMCharacteristicTypeLockManagementAutoSecureTimeout NS_AVAILABLE_IOS(8_0);

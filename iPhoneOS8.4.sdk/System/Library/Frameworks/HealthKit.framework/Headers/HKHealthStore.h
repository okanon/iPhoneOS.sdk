//
//  HKHealthStore.h
//  HealthKit
//
//  Copyright (c) 2013-2014 Apple Inc. All rights reserved.
//

#import <HealthKit/HKDefines.h>

@class HKBiologicalSexObject;
@class HKBloodTypeObject;
@class HKUnit;
@class HKObject;
@class HKObjectType;
@class HKQuantityType;
@class HKQuery;
@class HKWorkout;

/*!
 @class         HKHealthStore
 @abstract      The HKHealthStore class provides an interface for accessing and storing the user's health data.
 */
HK_CLASS_AVAILABLE_IOS(8_0)
NS_EXTENSION_UNAVAILABLE_IOS("HealthKit is not supported in extensions")
@interface HKHealthStore : NSObject

/*!
 @method        isHealthDataAvailable
 @abstract      Returns YES if HealthKit is supported on the device.
 @discussion    HealthKit is not supported on all iOS devices.  Using HKHealthStore APIs on devices which are not
                supported will result in errors with the HKErrorHealthDataUnavailable code.  Call isHealthDataAvailable
                before attempting to use other parts of the framework.
 */
+ (BOOL)isHealthDataAvailable;

/*!
 @method        authorizationStatusForType:
 @abstract      Returns the application's authorization status for the given object type.
 */
- (HKAuthorizationStatus)authorizationStatusForType:(HKObjectType *)type;

/*!
 @method        requestAuthorizationToShareTypes:readTypes:completion:
 @abstract      Prompts the user to authorize the application for reading and saving objects of the given types.
 @discussion    Before attempting to execute queries or save objects, the application should first request authorization
                from the user to read and share every type of object for which the application may require access.
 
                The request is performed asynchronously and its completion will be executed on an arbitrary background
                queue after the user has responded.  If the user has already chosen whether to grant the application
                access to all of the types provided, then the completion will be called without prompting the user.
                The success parameter of the completion indicates whether prompting the user, if necessary, completed
                successfully and was not cancelled by the user.  It does NOT indicate whether the application was
                granted authorization.
 
                To customize the messages displayed on the authorization sheet, set the following keys in your app's
                Info.plist file. Set the NSHealthShareUsageDescription key to customize the message for reading data. Set
                the NSHealthUpdateUsageDescription key to customize the message for writing data.
 */
- (void)requestAuthorizationToShareTypes:(NSSet *)typesToShare
                               readTypes:(NSSet *)typesToRead
                              completion:(void (^)(BOOL success, NSError *error))completion;

/*!
 @method        saveObject:withCompletion:
 @abstract      Saves a single HKObject.
 @discussion    See saveObjects:withCompletion:.
 */
- (void)saveObject:(HKObject *)object withCompletion:(void(^)(BOOL success, NSError *error))completion;

/*!
 @method        saveObjects:withCompletion:
 @abstract      Saves an array of HKObjects.
 @discussion    After an object is saved, on subsequent retrievals the source property of the object will be set to the
                HKSource representing the application that saved it.  If the object has an HKObjectType property, then
                in order to save an object successfully the application must first request authorization to share
                objects with that type.  Saving an object with the same unique identifier as another object that has
                already been saved will fail.  When the application attempts to save multiple objects, if any single
                object cannot be saved then none of the objects will be saved.  This operation is performed
                asynchronously and the completion will be executed on an arbitrary background queue.
 */
- (void)saveObjects:(NSArray *)objects withCompletion:(void(^)(BOOL success, NSError *error))completion;

/*!
 @method        deleteObject:withCompletion:
 @abstract      Removes an object from the HealthKit database.
 @discussion    An application may only delete objects that it previously saved.  This operation is performed
                asynchronously and the completion will be executed on an arbitrary background queue.
 */
- (void)deleteObject:(HKObject *)object withCompletion:(void(^)(BOOL success, NSError *error))completion;

/*!
 @method        executeQuery:
 @abstract      Begins executing the given query.
 @discussion    After executing a query the completion, update, and/or results handlers of that query will be invoked
                asynchronously on an arbitrary background queue as results become available.  Errors that prevent a
                query from executing will be delivered to one of the query's handlers.  Which handler the error will be
                delivered to is defined by the HKQuery subclass.  The behavior of calling this method with a query that
                is already executing is undefined.  If a query would retrieve objects with an HKObjectType property,
                then the application must request authorization to access objects of that type before executing the query.
 */
- (void)executeQuery:(HKQuery *)query;

/*!
 @method        stopQuery:
 @abstract      Stops a query that is executing from continuing to run.
 @discussion    Calling this method will prevent the handlers of the query from being invoked in the future.  If the
                query is already stopped, this method does nothing.
 */
- (void)stopQuery:(HKQuery *)query;

/*!
 @method        dateOfBirthWithError:
 @abstract      Returns the user's date of birth.
 @discussion    Before calling this method, the application should request authorization to access objects with the
                HKCharacteristicType identified by HKCharacteristicTypeIdentifierDateOfBirth.
 */
- (NSDate *)dateOfBirthWithError:(NSError **)error;

/*!
 @method        biologicalSexWithError:
 @abstract      Returns an object encapsulating the user's biological sex.
 @discussion    Before calling this method, the application should request authorization to access objects with the
                HKCharacteristicType identified by HKCharacteristicTypeIdentifierBiologicalSex.
 */
- (HKBiologicalSexObject *)biologicalSexWithError:(NSError **)error;

/*!
 @method        bloodTypeWithError:
 @abstract      Returns an object encapsulating the user's blood type.
 @discussion    Before calling this method, the application should request authorization to access objects with the
                HKCharacteristicType identified by HKCharacteristicTypeIdentifierBloodType.
 */
- (HKBloodTypeObject *)bloodTypeWithError:(NSError **)error;

@end

@interface HKHealthStore (HKWorkout)

/*!
 @method        addSamples:toWorkout:completion:
 @abstract      Associates samples with a given workout
 @discussion    This will associate the given samples with the given workout. These samples will then be returned by a
                query that contains this workout as a predicate. If a sample is added that is not saved yet, then it will be
                saved for you. The workout provided has to be an HKWorkout that has already been saved to HealthKit.
 */
- (void)addSamples:(NSArray *)samples toWorkout:(HKWorkout *)workout completion:(void(^)(BOOL success, NSError *error))completion;

@end


@interface HKHealthStore (HKBackgroundDelivery)

/*!
 @method        enableBackgroundDeliveryForType:frequency:withCompletion:
 @abstract      This method enables activation of your app when data of the type is recorded at the cadence specified.
 @discussion    When an app has subscribed to a certain data type it will get activated at the cadence that is specified
                with the frequency parameter. The app is still responsible for creating an HKObserverQuery to know which
                data types have been updated and the corresponding fetch queries. Note that certain data types (such as
                HKQuantityTypeIdentifierStepCount) have a minimum frequency of HKUpdateFrequencyHourly. This is enforced
                transparently to the caller.
 */
- (void)enableBackgroundDeliveryForType:(HKObjectType *)type frequency:(HKUpdateFrequency)frequency withCompletion:(void(^)(BOOL success, NSError *error))completion;

- (void)disableBackgroundDeliveryForType:(HKObjectType *)type withCompletion:(void(^)(BOOL success, NSError *error))completion;

- (void)disableAllBackgroundDeliveryWithCompletion:(void(^)(BOOL success, NSError *error))completion;

@end

/*!
 @constant      HKUserPreferencesDidChangeNotification
 @abstract      Posted every time the user updates their preferred units.
 @discussion    Each HKHealthStore will post their HKUserPreferencesDidChangeNotification. To guarantee only one received notification it is
                necessary to specify an HKHealthStore to the object field in NSNotificationCenter's addObserver methods.
 */
HK_EXTERN NSString * const HKUserPreferencesDidChangeNotification NS_AVAILABLE_IOS(8_2);

@interface HKHealthStore (HKUserPreferences)

/*!
 @method        preferredUnitsForQuantityTypes:completion:
 @abstract      Calls the completion with the preferred HKUnits for a given set of HKQuantityTypes.
 @discussion    A preferred unit is either the unit that the user has chosen in Health for displaying samples of the given quantity type or the 
                default unit for that type in the current locale of the device. To access the user's preferences it is necessary to request 
                read or share authorization for the set of HKQuantityTypes provided. If neither read nor share authorization has been granted to 
                the app, then the default unit for the locale is provided.
 
                An error will be returned when preferred units are inaccessible because protected health data is unavailable or authorization status 
                is not determined for one or more of the provided types.
 
                The returned dictionary will map HKQuantityType to HKUnit.
 */
- (void)preferredUnitsForQuantityTypes:(NSSet *)quantityTypes completion:(void(^)(NSDictionary *preferredUnits, NSError *error))completion NS_AVAILABLE_IOS(8_2);

@end

/*!
 @class     HKBiologicalSexObject
 @abstract  A wrapper object for HKBiologicalSex enumeration.
 */
HK_CLASS_AVAILABLE_IOS(8_0)
@interface HKBiologicalSexObject : NSObject

@property (readonly) HKBiologicalSex biologicalSex;

@end

/*!
 @class     HKBloodTypeObject
 @abstract  A wrapper object for HKBloodType enumeration.
 */
HK_CLASS_AVAILABLE_IOS(8_0)
@interface HKBloodTypeObject : NSObject

@property (readonly) HKBloodType bloodType;

@end

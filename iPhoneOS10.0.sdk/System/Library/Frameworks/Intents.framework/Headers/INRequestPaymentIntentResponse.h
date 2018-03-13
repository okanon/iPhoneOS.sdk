//
//  INRequestPaymentIntentResponse.h
//  Intents
//
//  Copyright © 2016 Apple Inc. All rights reserved.
//

#import <Intents/INIntentResponse.h>

@class INPaymentRecord;

typedef NS_ENUM(NSInteger, INRequestPaymentIntentResponseCode) {
    INRequestPaymentIntentResponseCodeUnspecified = 0,
    INRequestPaymentIntentResponseCodeReady,
    INRequestPaymentIntentResponseCodeInProgress,
    INRequestPaymentIntentResponseCodeSuccess,
    INRequestPaymentIntentResponseCodeFailure,
    INRequestPaymentIntentResponseCodeFailureRequiringAppLaunch,
    INRequestPaymentIntentResponseCodeFailureCredentialsUnverified,
    INRequestPaymentIntentResponseCodeFailurePaymentsAmountBelowMinimum,
    INRequestPaymentIntentResponseCodeFailurePaymentsAmountAboveMaximum,
    INRequestPaymentIntentResponseCodeFailurePaymentsCurrencyUnsupported,
    INRequestPaymentIntentResponseCodeFailureNoBankAccount,
} API_AVAILABLE(ios(10.0)) API_UNAVAILABLE(macosx);

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(10.0))
API_UNAVAILABLE(macosx)
@interface INRequestPaymentIntentResponse : INIntentResponse

- (id)init NS_UNAVAILABLE;

// The app extension has the option of capturing its private state as an NSUserActivity and returning it as the 'currentActivity'.
// If the the app is launched, an NSUserActivity will be passed in with the private state.  The NSUserActivity may also be used to query the app's UI extension (if provided) for a view controller representing the current intent handling state.
// In the case of app launch, the NSUserActivity will have its activityType set to the name of the intent. This intent object will also be available in the NSUserActivity.interaction property.
- (instancetype)initWithCode:(INRequestPaymentIntentResponseCode)code userActivity:(nullable NSUserActivity *)userActivity NS_DESIGNATED_INITIALIZER;

@property (readonly, NS_NONATOMIC_IOSONLY) INRequestPaymentIntentResponseCode code;

@property (readwrite, copy, nullable, NS_NONATOMIC_IOSONLY) INPaymentRecord *paymentRecord;

@end

NS_ASSUME_NONNULL_END

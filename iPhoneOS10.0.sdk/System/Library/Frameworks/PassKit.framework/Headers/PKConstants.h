//
//  PKConstants.h
//  PassKit
//
//  Copyright © 2015 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef PKCONSTANTS_H
#define PKCONSTANTS_H


typedef NSString * PKEncryptionScheme NS_STRING_ENUM;
extern PKEncryptionScheme const PKEncryptionSchemeECC_V2 NS_AVAILABLE_IOS(9_0);
extern PKEncryptionScheme const PKEncryptionSchemeRSA_V2 NS_AVAILABLE_IOS(10_0);

typedef NSString * PKPaymentNetwork NS_EXTENSIBLE_STRING_ENUM;
extern PKPaymentNetwork const PKPaymentNetworkAmex NS_AVAILABLE_IOS(8_0) __WATCHOS_AVAILABLE(3.0);
extern PKPaymentNetwork const PKPaymentNetworkChinaUnionPay NS_AVAILABLE_IOS(9_2) __WATCHOS_AVAILABLE(3.0);
extern PKPaymentNetwork const PKPaymentNetworkDiscover NS_AVAILABLE_IOS(9_0) __WATCHOS_AVAILABLE(3.0);
extern PKPaymentNetwork const PKPaymentNetworkInterac NS_AVAILABLE_IOS(9_2) __WATCHOS_AVAILABLE(3.0);
extern PKPaymentNetwork const PKPaymentNetworkMasterCard NS_AVAILABLE_IOS(8_0) __WATCHOS_AVAILABLE(3.0);
extern PKPaymentNetwork const PKPaymentNetworkPrivateLabel NS_AVAILABLE_IOS(9_0) __WATCHOS_AVAILABLE(3.0);
extern PKPaymentNetwork const PKPaymentNetworkVisa NS_AVAILABLE_IOS(8_0) __WATCHOS_AVAILABLE(3.0);

typedef NS_ENUM(NSInteger, PKPaymentAuthorizationStatus) {
    PKPaymentAuthorizationStatusSuccess, // Merchant auth'd (or expects to auth) the transaction successfully.
    PKPaymentAuthorizationStatusFailure, // Merchant failed to auth the transaction.

    PKPaymentAuthorizationStatusInvalidBillingPostalAddress,  // Supplied billing address is insufficient or otherwise invalid
    PKPaymentAuthorizationStatusInvalidShippingPostalAddress, // Supplied postal address is insufficient or otherwise invalid
    PKPaymentAuthorizationStatusInvalidShippingContact,       // Supplied contact information is insufficient or otherwise invalid

    PKPaymentAuthorizationStatusPINRequired NS_ENUM_AVAILABLE_IOS(9_2),  // Transaction requires PIN entry.
    PKPaymentAuthorizationStatusPINIncorrect NS_ENUM_AVAILABLE_IOS(9_2), // PIN was not entered correctly, retry.
    PKPaymentAuthorizationStatusPINLockout NS_ENUM_AVAILABLE_IOS(9_2)    // PIN retry limit exceeded.

} NS_ENUM_AVAILABLE_IOS(8_0) __WATCHOS_AVAILABLE(3.0);

#endif // PKCONSTANTS_H

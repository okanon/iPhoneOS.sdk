//
//  PKPaymentRequest.h
//
//  Copyright (c) 2014, Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AddressBook/ABRecord.h>

extern NSString * const PKPaymentNetworkAmex NS_AVAILABLE(NA, 8_0);
extern NSString * const PKPaymentNetworkMasterCard NS_AVAILABLE(NA, 8_0);
extern NSString * const PKPaymentNetworkVisa NS_AVAILABLE(NA, 8_0);

typedef NS_OPTIONS(NSUInteger, PKMerchantCapability) {
    PKMerchantCapability3DS = 1UL << 0,  // Merchant supports 3DS
    PKMerchantCapabilityEMV = 1UL << 1   // Merchant supports EMV
} NS_ENUM_AVAILABLE(NA, 8_0);

typedef NS_OPTIONS(NSUInteger, PKAddressField) {
    PKAddressFieldNone                              = 0UL,      // No address fields required.
    PKAddressFieldPostalAddress                     = 1UL << 0, // Full street address including name, street, city, state/province, postal code, country.
    PKAddressFieldPhone                             = 1UL << 1,
    PKAddressFieldEmail                             = 1UL << 2,
    PKAddressFieldName NS_ENUM_AVAILABLE_IOS(8_3)   = 1UL << 3,
    PKAddressFieldAll                               = (PKAddressFieldPostalAddress|PKAddressFieldPhone|PKAddressFieldEmail|PKAddressFieldName)
} NS_ENUM_AVAILABLE(NA, 8_0);

typedef NS_ENUM(NSUInteger, PKShippingType) {
    PKShippingTypeShipping,
    PKShippingTypeDelivery,
    PKShippingTypeStorePickup,
    PKShippingTypeServicePickup
} NS_ENUM_AVAILABLE(NA, 8_3);

// PKPaymentSummaryItem Defines a line-item for a payment such as tax, shipping, or discount.
NS_CLASS_AVAILABLE(NA, 8_0)
@interface PKPaymentSummaryItem : NSObject

+ (instancetype)summaryItemWithLabel:(NSString *)label amount:(NSDecimalNumber *)amount;

// A short localized description of the item, e.g. "Tax" or "Gift Card".
@property (nonatomic, copy) NSString *label;

// Same currency as the enclosing PKPaymentRequest.  Negative values are permitted, for example when
// redeeming a coupon.
@property (nonatomic, copy) NSDecimalNumber *amount;

@end

// Defines a shipping method for delivering physical goods.
NS_CLASS_AVAILABLE(NA, 8_0)
@interface PKShippingMethod : PKPaymentSummaryItem

// Application-defined unique identifier for this shipping method.  The application will receive this
// in paymentAuthorizationViewController:didAuthorizePayment:completion:.
@property (nonatomic, copy) NSString *identifier;

// Additional localized information about the shipping method, e.g. "Ships in 24 hours" or
// "Arrives Friday April 4."
@property (nonatomic, copy) NSString *detail;

@end

// PKPaymentRequest defines an application's request to produce a payment instrument for the
// purchase of goods and services. It encapsulates information about the selling party's payment
// processing capabilities, an amount to pay, and the currency code.
NS_CLASS_AVAILABLE(NA, 8_0)
@interface PKPaymentRequest : NSObject

// Identifies the merchant, as previously agreed with Apple.  Must match one of the merchant
// identifiers in the application's entitlement.
@property (nonatomic, copy) NSString *merchantIdentifier;

// The merchant's ISO country code.
@property (nonatomic, copy) NSString *countryCode;

// The payment networks supported by the merchant, for example @[ PKPaymentNetworkVisa,
// PKPaymentNetworkMasterCard ].  This property constrains payment cards that may fund the payment.
@property (nonatomic, copy) NSArray *supportedNetworks;

// The payment processing capabilities of the merchant.
@property (nonatomic, assign) PKMerchantCapability merchantCapabilities;

// Array of PKPaymentSummaryItem objects which should be presented to the user.
@property (nonatomic, copy) NSArray *paymentSummaryItems;

// Currency code for this payment.
@property (nonatomic, copy) NSString *currencyCode;

// Indicates which billing address fields the merchant requires in order to process a transaction.
// The default is PKAddressFieldNone.
@property (nonatomic, assign) PKAddressField requiredBillingAddressFields;

// If the merchant already has a billing address on file, set it here.
@property (nonatomic, assign) ABRecordRef billingAddress;

// Indicates which shipping address fields the merchant requires in order to process a transaction.
// The default is PKAddressFieldNone.
@property (nonatomic, assign) PKAddressField requiredShippingAddressFields;

// If the merchant already has a shipping address on file, set it here.
@property (nonatomic, assign) ABRecordRef shippingAddress;

// Shipping methods supported by the merchant.
@property (nonatomic, copy) NSArray *shippingMethods;

// Indicates the display mode for the shipping (e.g, "Pick Up", "Ship To", "Deliver To"). Localized.
// The default is PKShippingTypeShipping
@property (nonatomic, assign) PKShippingType shippingType NS_AVAILABLE_IOS(8_3);

// Optional merchant-supplied information about the payment request.  Examples of this are an order
// or cart identifier.  It will be signed and included in the resulting PKPaymentToken.
@property (nonatomic, copy) NSData *applicationData;

@end

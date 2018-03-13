//
//  SKProductsRequest.h
//  StoreKit
//
//  Copyright 2009 Apple, Inc. All rights reserved.
//

#import <StoreKit/SKRequest.h>

@class SKProductsRequest, SKProductsResponse;


@protocol SKProductsRequestDelegate <SKRequestDelegate>

@required
// Sent immediately before -requestDidFinish:
- (void)productsRequest:(SKProductsRequest *)request didReceiveResponse:(SKProductsResponse *)response NS_AVAILABLE_IOS(3_0);

@end


// request information about products for your application
SK_EXTERN_CLASS_AVAILABLE(3_0) @interface SKProductsRequest : SKRequest {
@private
    id _productsRequestInternal;
}

// Set of string product identifiers
- (instancetype)initWithProductIdentifiers:(NSSet *)productIdentifiers NS_AVAILABLE_IOS(3_0);

@property(nonatomic, assign) id <SKProductsRequestDelegate> delegate NS_AVAILABLE_IOS(3_0);

@end


SK_EXTERN_CLASS_AVAILABLE(3_0) @interface SKProductsResponse : NSObject {
@private
    id _internal;
}

// Array of SKProduct instances.
@property(nonatomic, readonly) NSArray *products NS_AVAILABLE_IOS(3_0);

// Array of invalid product identifiers.
@property(nonatomic, readonly) NSArray *invalidProductIdentifiers NS_AVAILABLE_IOS(3_0);

@end

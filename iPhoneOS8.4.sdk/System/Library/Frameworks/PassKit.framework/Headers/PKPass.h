//
//  PKPass.h
//  PassKit
//
//  Copyright (c) 2011 Apple, Inc. All rights reserved.
//

#ifndef __PKPASS_H
#define __PKPASS_H

#import <PassKit/PKObject.h>

typedef NS_ENUM(NSUInteger, PKPassType) {
    PKPassTypeBarcode,
    PKPassTypePayment,
    PKPassTypeAny = ~0
} NS_ENUM_AVAILABLE_IOS(8_0);

@class PKPaymentPass;
@class UIImage;

@interface PKPass : PKObject

- (instancetype)initWithData:(NSData *)data error:(NSError **)error;

@property (nonatomic,assign,readonly)   PKPassType     passType NS_AVAILABLE_IOS(8_0);
@property (nonatomic,assign,readonly)   PKPaymentPass *paymentPass NS_AVAILABLE_IOS(8_0);

@property (nonatomic,copy,readonly) NSString     *serialNumber;
@property (nonatomic,copy,readonly) NSString     *passTypeIdentifier;
@property (nonatomic,copy,readonly) NSURL        *webServiceURL;
@property (nonatomic,copy,readonly) NSString     *authenticationToken;

@property (nonatomic,copy,readonly) UIImage      *icon;
@property (nonatomic,copy,readonly) NSString     *localizedName; // e.g. "Boarding Pass"
@property (nonatomic,copy,readonly) NSString     *localizedDescription; // e.g. "SFO -> LHR"
@property (nonatomic,copy,readonly) NSString     *organizationName; // e.g. "Great Airways"
@property (nonatomic,copy,readonly) NSDate       *relevantDate; // may be useful for sorting
@property (nonatomic,copy,readonly) NSDictionary *userInfo NS_AVAILABLE_IOS(7_0);

@property (nonatomic,copy,readonly) NSURL        *passURL; // open to view pass in Passbook.app

- (id)localizedValueForFieldKey:(NSString *)key; // IBOutlet-like; allows access to field data from pass file format

@end

#endif

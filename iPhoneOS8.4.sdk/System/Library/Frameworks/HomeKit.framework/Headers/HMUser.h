//
//  HMUser.h
//  HomeKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 * @brief This class describes a user in the home.
 */
NS_CLASS_AVAILABLE_IOS(8_0)
@interface HMUser : NSObject

- (instancetype)init NS_UNAVAILABLE;

/*!
 * @brief Name of the user.
 */
@property(readonly, copy, nonatomic) NSString *name;

@end

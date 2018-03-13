/*
 *	@file CBAttribute.h
 *	@framework CoreBluetooth
 *
 *	@copyright 2014 Apple, Inc. All rights reserved.
 */

#import <CoreBluetooth/CBDefines.h>

#import <Foundation/Foundation.h>

@class CBUUID;

NS_CLASS_AVAILABLE(N_A, 8_0)
CB_EXTERN_CLASS @interface CBAttribute : NSObject

/*!
 * @property UUID
 *
 * @discussion
 *      The Bluetooth UUID of the attribute.
 *
 */
@property(readonly, nonatomic) CBUUID *UUID;

@end

/*
 * NEVPNProtocol.h
 *
 * Copyright (c) 2013-2014 Apple Inc.
 * All rights reserved.
 */

/*!
 * @interface NEVPNProtocol
 * @discussion The NEVPNProtocol class declares the programmatic interface of an object that manages the protocol-specific portion of a VPN configuration.
 *
 * NEVPNProtocol is an abstract base class from which other protocol-specific classes are derived.
 *
 * Instances of this class are thread safe.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface NEVPNProtocol : NSObject <NSCopying,NSSecureCoding>

/*!
 * @property serverAddress
 * @discussion The VPN server. Depending on the protocol, may be an IP address, host name, or URL.
 */
@property (copy) NSString *serverAddress NS_AVAILABLE(10_10, 8_0);

/*!
 * @property username
 * @discussion The username component of the VPN authentication credential.
 */
@property (copy) NSString *username NS_AVAILABLE(10_10, 8_0);

/*!
 * @property passwordReference
 * @discussion The password component of the VPN authentication credential. The value is a persistent reference to a keychain item with the kSecClassGenericPassword class.
 */
@property (copy) NSData *passwordReference NS_AVAILABLE(10_10, 8_0);

/*!
 * @property identityReference
 * @discussion The certificate and private key component of the VPN authentication credential. The value is a persistent reference to a keychain item with the kSecClassIdentity class.
 */
@property (copy) NSData *identityReference NS_AVAILABLE(10_10, NA);

/*!
 * @property identityData
 * @discussion The PKCS12 data for the VPN authentication identity. The value is a NSData in PKCS12 format.
 */
@property (copy) NSData *identityData NS_AVAILABLE(NA, 8_0);

/*!
 * @property identitiDataPassword
 * @discussion The password to be used to decrypt the PKCS12 identity data.
 */
@property (copy) NSString *identityDataPassword NS_AVAILABLE(NA, 8_0);

/*!
 * @property disconnectOnSleep
 * @discussion If YES, the VPN connection will be disconnected when the device goes to sleep. The default is NO.
 */
@property BOOL disconnectOnSleep NS_AVAILABLE(10_10, 8_0);

@end

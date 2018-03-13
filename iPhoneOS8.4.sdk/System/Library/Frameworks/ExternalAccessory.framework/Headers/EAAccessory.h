//
//  EAAccessory.h
//  ExternalAccessory
//
//  NOTE: Data to the external accessory is automatically wrapped into an iAP
//        packet after bring sent to the output stream. The iAP wrapper is
//        automatically stripped from incoming packets before being sent to
//        the EAAccessory input stream.
//
//        Further information related to these wrapper can be found in the
//        iAP specifications.
//
//  Copyright (c) 2008-2012 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class EAAccessoryInternal;
@protocol EAAccessoryDelegate;

enum {
    EAConnectionIDNone = 0,
};

EA_EXTERN_CLASS_AVAILABLE(3_0) @interface EAAccessory : NSObject {
@private
    EAAccessoryInternal *_internal;
}

@property(nonatomic, readonly, getter=isConnected) BOOL connected __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);
@property(nonatomic, readonly) NSUInteger connectionID __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);
@property(nonatomic, readonly) NSString *manufacturer __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);
@property(nonatomic, readonly) NSString *name __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);
@property(nonatomic, readonly) NSString *modelNumber __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);
@property(nonatomic, readonly) NSString *serialNumber __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);
@property(nonatomic, readonly) NSString *firmwareRevision __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);
@property(nonatomic, readonly) NSString *hardwareRevision __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

// array of strings representing the protocols supported by the accessory
@property(nonatomic, readonly) NSArray *protocolStrings __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

@property(nonatomic, assign) id<EAAccessoryDelegate> delegate __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);

@end

@protocol EAAccessoryDelegate <NSObject>
@optional
- (void)accessoryDidDisconnect:(EAAccessory *)accessory __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);
@end

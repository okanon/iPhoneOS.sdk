//
//  MPVolumeView.h
//  MediaPlayer
//
//  Copyright 2008-2010 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayerDefines.h>

MP_EXTERN_CLASS_AVAILABLE(2_0) @interface MPVolumeView : UIView <NSCoding>

@property (nonatomic) BOOL showsVolumeSlider NS_AVAILABLE_IOS(4_2); // Default is YES.
@property (nonatomic) BOOL showsRouteButton NS_AVAILABLE_IOS(4_2);  // Default is YES.

// Returns YES if wireless routes (AirPlay, Bluetooth, etc) are available for user selection.
// Note that the view must be in present in a window hierarchy in order to discover some types of wireless routes.
@property (nonatomic, readonly, getter=areWirelessRoutesAvailable) BOOL wirelessRoutesAvailable NS_AVAILABLE_IOS(7_0);

// Returns YES if a wireless route is active.
@property (nonatomic, readonly, getter=isWirelessRouteActive) BOOL wirelessRouteActive NS_AVAILABLE_IOS(7_0);

// Volume slider customization

- (void)setMinimumVolumeSliderImage:(UIImage *)image forState:(UIControlState)state NS_AVAILABLE_IOS(6_0);
- (void)setMaximumVolumeSliderImage:(UIImage *)image forState:(UIControlState)state NS_AVAILABLE_IOS(6_0);
- (void)setVolumeThumbImage:(UIImage *)image forState:(UIControlState)state NS_AVAILABLE_IOS(6_0);

- (UIImage *)minimumVolumeSliderImageForState:(UIControlState)state NS_AVAILABLE_IOS(6_0);
- (UIImage *)maximumVolumeSliderImageForState:(UIControlState)state NS_AVAILABLE_IOS(6_0);
- (UIImage *)volumeThumbImageForState:(UIControlState)state NS_AVAILABLE_IOS(6_0);

// Sets the image for the EU volume limit. When appropriate, this image will be displayed on top of the
// maximumVolumeSliderImage. It must be visually distinct from the maximumVolumeSliderImage, and use
// a color similar to the default, to convey a sense of warning to the user. The same image is used for
// all control states. For debugging purposes, switch on the "EU Volume Limit" setting in the Developer
// menu of the Settings application to always enable the volume limit.
@property (nonatomic, strong) UIImage *volumeWarningSliderImage NS_AVAILABLE_IOS(7_0);

- (CGRect)volumeSliderRectForBounds:(CGRect)bounds NS_AVAILABLE_IOS(6_0);
- (CGRect)volumeThumbRectForBounds:(CGRect)bounds volumeSliderRect:(CGRect)rect value:(float)value NS_AVAILABLE_IOS(6_0);

// Route button customization

- (void)setRouteButtonImage:(UIImage *)image forState:(UIControlState)state NS_AVAILABLE_IOS(6_0);
- (UIImage *)routeButtonImageForState:(UIControlState)state NS_AVAILABLE_IOS(6_0);

- (CGRect)routeButtonRectForBounds:(CGRect)bounds NS_AVAILABLE_IOS(6_0);

@end

// Posted when the wirelessRoutesAvailable property changes.
MP_EXTERN NSString *const MPVolumeViewWirelessRoutesAvailableDidChangeNotification NS_AVAILABLE_IOS(7_0);

// Posted when the wirelessRouteActive property changes.
MP_EXTERN NSString *const MPVolumeViewWirelessRouteActiveDidChangeNotification NS_AVAILABLE_IOS(7_0);

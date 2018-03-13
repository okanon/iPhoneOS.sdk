//
//  WKInterfaceImage.h
//  WatchKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WatchKit/WKDefines.h>
#import <WatchKit/WKInterfaceObject.h>

@class UIImage;

WK_CLASS_AVAILABLE_IOS(8_2)
@interface WKInterfaceImage : WKInterfaceObject

- (void)setImage:(UIImage *)image;
- (void)setImageData:(NSData *)imageData;
- (void)setImageNamed:(NSString *)imageName;

- (void)setTintColor:(UIColor *)tintColor;

- (void)startAnimating;	      // play all images repeatedly using duration specified in interface description
- (void)startAnimatingWithImagesInRange:(NSRange)imageRange duration:(NSTimeInterval)duration repeatCount:(NSInteger)repeatCount; // play subset of images for a certain number of times. 0 means repeat until stop
- (void)stopAnimating;

@end

//
//  WKInterfaceGroup.h
//  WatchKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WatchKit/WKDefines.h>
#import <WatchKit/WKInterfaceObject.h>

@class UIColor, UIImage;

WK_CLASS_AVAILABLE_IOS(8_2)
@interface WKInterfaceGroup : WKInterfaceObject

- (void)setCornerRadius:(CGFloat)cornerRadius;

- (void)setBackgroundColor:(UIColor *)color;
- (void)setBackgroundImage:(UIImage *)image;
- (void)setBackgroundImageData:(NSData *)imageData;
- (void)setBackgroundImageNamed:(NSString *)imageName;

- (void)startAnimating;	      // play all images repeatedly using duration specified in interface description
- (void)startAnimatingWithImagesInRange:(NSRange)imageRange duration:(NSTimeInterval)duration repeatCount:(NSInteger)repeatCount; // play subset of images for a certain number of times. 0 means repeat until stop
- (void)stopAnimating;

@end

//
//  WKInterfaceButton.h
//  WatchKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WatchKit/WKDefines.h>
#import <WatchKit/WKInterfaceObject.h>

@class UIImage, UIColor;

WK_CLASS_AVAILABLE_IOS(8_2)
@interface WKInterfaceButton : WKInterfaceObject

- (void)setTitle:(NSString *)title;
- (void)setAttributedTitle:(NSAttributedString *)attributedTitle;

- (void)setBackgroundColor:(UIColor *)color;
- (void)setBackgroundImage:(UIImage *)image;
- (void)setBackgroundImageData:(NSData *)imageData;
- (void)setBackgroundImageNamed:(NSString *)imageName;

- (void)setEnabled:(BOOL)enabled;

@end

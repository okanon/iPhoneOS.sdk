//
//  UIImageView.h
//  UIKit
//
//  Copyright (c) 2006-2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>

@class UIImage;

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIImageView : UIView {
  @private
    id _storage;
}

- (instancetype)initWithImage:(UIImage *)image;
- (instancetype)initWithImage:(UIImage *)image highlightedImage:(UIImage *)highlightedImage NS_AVAILABLE_IOS(3_0);

@property(nonatomic,retain) UIImage *image;                                                     // default is nil
@property(nonatomic,retain) UIImage *highlightedImage NS_AVAILABLE_IOS(3_0);      // default is nil
@property(nonatomic,getter=isUserInteractionEnabled) BOOL userInteractionEnabled;               // default is NO

@property(nonatomic,getter=isHighlighted) BOOL highlighted NS_AVAILABLE_IOS(3_0); // default is NO

// these allow a set of images to be animated. the array may contain multiple copies of the same

@property(nonatomic,copy) NSArray *animationImages;            // The array must contain UIImages. Setting hides the single image. default is nil
@property(nonatomic,copy) NSArray *highlightedAnimationImages NS_AVAILABLE_IOS(3_0);            // The array must contain UIImages. Setting hides the single image. default is nil

@property(nonatomic) NSTimeInterval animationDuration;         // for one cycle of images. default is number of images * 1/30th of a second (i.e. 30 fps)
@property(nonatomic) NSInteger      animationRepeatCount;      // 0 means infinite (default is 0)

// When tintColor is non-nil, any template images set on the image view will be colorized with that color.
// The tintColor is inherited through the superview hierarchy. See UIView for more information.
@property (nonatomic, retain) UIColor *tintColor NS_AVAILABLE_IOS(7_0);

- (void)startAnimating;
- (void)stopAnimating;
- (BOOL)isAnimating;

@end

//
//  UIActivityIndicator.h
//  UIKit
//
//  Copyright (c) 2005-2014 Apple Inc. All rights reserved.
//

#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>

typedef NS_ENUM(NSInteger, UIActivityIndicatorViewStyle) {
    UIActivityIndicatorViewStyleWhiteLarge,
    UIActivityIndicatorViewStyleWhite,
    UIActivityIndicatorViewStyleGray,
};

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIActivityIndicatorView : UIView <NSCoding>
{ 
  @package
    CFTimeInterval               _duration;
    BOOL                         _animating;
    UIActivityIndicatorViewStyle _activityIndicatorViewStyle;
    UIActivityIndicatorViewStyle _actualActivityIndicatorViewStyle;
    BOOL                         _hidesWhenStopped;
}

- (instancetype)initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyle)style;     // sizes the view according to the style

@property(nonatomic) UIActivityIndicatorViewStyle activityIndicatorViewStyle; // default is UIActivityIndicatorViewStyleWhite
@property(nonatomic) BOOL                         hidesWhenStopped;           // default is YES. calls -setHidden when animating gets set to NO

@property (readwrite, nonatomic, retain) UIColor *color NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

- (void)startAnimating;
- (void)stopAnimating;
- (BOOL)isAnimating;
@end

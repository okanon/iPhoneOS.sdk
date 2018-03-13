//
//  UIMotionEffect.h
//  Copyright (c) 2013-2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIGeometry.h>

/*! UIMotionEffect is an abstract superclass which declaratively represents a rendering
    effect that depends on the motion of the device. Given some device pose, subclassers
    provide relative values which are to be applied to the keypaths of the target's view.
 
    Subclasses must implement conformance for NSCopying and NSCoding. */
NS_CLASS_AVAILABLE_IOS(7_0) @interface UIMotionEffect : NSObject <NSCopying, NSCoding>

/*! Abstract method. Given the `viewerOffset`, this method should compute a set of key paths
    and relative values pairs which will represent the effect of the device's motion on
    the target view. The return value is a dictionary whose keys and values are these
    key paths (as NSStrings) and relative values, respectively.

    The `viewerOffset` is an estimate of the viewer's position relative to direction the
    screen's facing. Values in each dimension range from -1 to 1. Facing straight at the
    viewer is (0, 0). Tilting the phone to the right produces a more positive horizontal
    value; tilting the phone down produces a more positive vertical value.

    `keyPaths` should be expressed relative to the effect's target view. Only key paths
    which would animate if set in an animation block may be targeted by motion effects.

    Example return value: `@{ @"center": [NSValue 
 valueFromCGPoint:CGPointMake(3.4, 1.2)],
                              @"layer.shadowOffset.x": @(-1.1) }` */
- (NSDictionary *)keyPathsAndRelativeValuesForViewerOffset:(UIOffset)viewerOffset;

@end

//---------------------------------------------------------------------

typedef NS_ENUM(NSInteger, UIInterpolatingMotionEffectType) {
    /*! Tracks the device being tilted left/right relative to the viewer. The minimum
        relative values maps to the device being tilted all the way to the left, the
        maximum to the right. */
    UIInterpolatingMotionEffectTypeTiltAlongHorizontalAxis,
    
    /*! Tracks the device being tilted up/down relative to the viewer. The minimum
        relative values maps to the device being tilted all the way down, the maximum
        all the way up. */
    UIInterpolatingMotionEffectTypeTiltAlongVerticalAxis
};

/*! This motion effect maps movement of a particular type (e.g. left/right tilt) to an
    interpolated output between two relative values provided by the client. Uses Core
    Animation's implementation of interpolation for all the standard types.
 
    `keyPath` should be expressed relative to the effect's target view. */
NS_CLASS_AVAILABLE_IOS(7_0) @interface UIInterpolatingMotionEffect : UIMotionEffect

- (instancetype)initWithKeyPath:(NSString *)keyPath type:(UIInterpolatingMotionEffectType)type; // designated initializer
@property (readonly, nonatomic) NSString *keyPath;
@property (readonly, nonatomic) UIInterpolatingMotionEffectType type;

@property (retain, nonatomic) id minimumRelativeValue;
@property (retain, nonatomic) id maximumRelativeValue;

@end

//---------------------------------------------------------------------

/*! Behaves like CAAnimationGroup. Merges key/value pairs of constituent
    using Core Animation's implementations of addition for all the standard types. */
NS_CLASS_AVAILABLE_IOS(7_0) @interface UIMotionEffectGroup : UIMotionEffect
@property (copy, nonatomic) NSArray *motionEffects;
@end

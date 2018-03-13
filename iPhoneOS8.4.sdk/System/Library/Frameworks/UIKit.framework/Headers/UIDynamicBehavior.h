//
//  UIDynamicBehavior.h
//  UIKit
//
//  Copyright (c) 2012-2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIGeometry.h>

@class UIDynamicAnimator;

@protocol UIDynamicItem <NSObject>

@property (nonatomic, readwrite) CGPoint center;
@property (nonatomic, readonly) CGRect bounds;
@property (nonatomic, readwrite) CGAffineTransform transform;

@end

NS_CLASS_AVAILABLE_IOS(7_0) @interface UIDynamicBehavior : NSObject

- (void)addChildBehavior:(UIDynamicBehavior *)behavior;
- (void)removeChildBehavior:(UIDynamicBehavior *)behavior;

@property (nonatomic, readonly, copy) NSArray* childBehaviors;

// When running, the dynamic animator calls the action block on every animation step.
@property (nonatomic,copy) void (^action)(void);

- (void)willMoveToAnimator:(UIDynamicAnimator *)dynamicAnimator; // nil when being removed from an animator

@property (nonatomic, readonly) UIDynamicAnimator *dynamicAnimator;


@end


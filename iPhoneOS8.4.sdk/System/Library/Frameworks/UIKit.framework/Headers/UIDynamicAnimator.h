//
//  UIDynamicAnimator.h
//  UIKit
//
//  Copyright (c) 2012-2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UICollectionViewLayout.h>

@class UIDynamicBehavior;
@class UIDynamicAnimator;

@protocol UIDynamicAnimatorDelegate <NSObject>

@optional
- (void)dynamicAnimatorWillResume:(UIDynamicAnimator*)animator;
- (void)dynamicAnimatorDidPause:(UIDynamicAnimator*)animator;

@end

NS_CLASS_AVAILABLE_IOS(7_0) @interface UIDynamicAnimator: NSObject

// When you initialize a dynamic animator with this method, you should only associates views with your behaviors.
// the behaviors (and their dynamic items) that you add to the animator employ the reference view’s coordinate system.
- (instancetype)initWithReferenceView:(UIView*)view;

- (void)addBehavior:(UIDynamicBehavior *)behavior;
- (void)removeBehavior:(UIDynamicBehavior *)behavior;
- (void)removeAllBehaviors;

@property (nonatomic, readonly) UIView* referenceView;
@property (nonatomic, readonly, copy) NSArray* behaviors;

// Returns the dynamic items associated with the animator’s behaviors that intersect a specified rectangle
- (NSArray*)itemsInRect:(CGRect)rect;
// Update the item state in the animator if an external change was made to this item 
- (void)updateItemUsingCurrentState:(id <UIDynamicItem>)item;

@property (nonatomic, readonly, getter = isRunning) BOOL running;
- (NSTimeInterval)elapsedTime;

@property (nonatomic, assign) id <UIDynamicAnimatorDelegate> delegate;

@end

@interface UIDynamicAnimator (UICollectionViewAdditions)

// When you initialize a dynamic animator with this method, you should only associate collection view layout attributes with your behaviors.
// The animator will employ thecollection view layout’s content size coordinate system.
- (instancetype)initWithCollectionViewLayout:(UICollectionViewLayout*)layout;

// The three convenience methods returning layout attributes (if associated to behaviors in the animator) if the animator was configured with collection view layout
- (UICollectionViewLayoutAttributes*)layoutAttributesForCellAtIndexPath:(NSIndexPath*)indexPath;
- (UICollectionViewLayoutAttributes*)layoutAttributesForSupplementaryViewOfKind:(NSString *)kind atIndexPath:(NSIndexPath *)indexPath;
- (UICollectionViewLayoutAttributes*)layoutAttributesForDecorationViewOfKind:(NSString*)decorationViewKind atIndexPath:(NSIndexPath *)indexPath;

@end

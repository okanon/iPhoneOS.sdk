//
//  NSTextContainer.h
//  UIKit
//
//  Copyright (c) 2011-2014 Apple Inc. All rights reserved.
//


#import <Foundation/NSObject.h>
#import <UIKit/NSParagraphStyle.h>
#import <UIKit/NSLayoutManager.h>


NS_CLASS_AVAILABLE_IOS(7_0) @interface NSTextContainer : NSObject <NSCoding, NSTextLayoutOrientationProvider>

/**************************** Initialization ****************************/

- (instancetype)initWithSize:(CGSize)size; // designated initializer


/**************************** Layout ****************************/

// Accessor for the NSLayoutManager object owning the receiver.
// Avoid assigning a layout manager directly through this property.  Adding a text container to a layout manager through -[NSLayoutManager addTextContainer:] will use the property for assigning the new layout manager.
@property(assign, NS_NONATOMIC_IOSONLY) NSLayoutManager *layoutManager;


/************************* Container shape properties *************************/

// Default value: CGSizeZero  Defines the maximum size for the layout area returned from -lineFragmentRectForProposedRect:writingDirection:remainingRect:.  0.0 and less means no limitation.
@property(NS_NONATOMIC_IOSONLY) CGSize size;

// Default value : nil  An array of UIBezierPath representing the exclusion paths inside the receiver's bounding rect.
@property(copy, NS_NONATOMIC_IOSONLY) NSArray *exclusionPaths;

// Default value: NSLineBreakByWordWrapping  The line break mode defines the behavior of the last line inside the text container.
@property(NS_NONATOMIC_IOSONLY) NSLineBreakMode lineBreakMode;


/************************* Layout constraint properties *************************/

// Default value: 5.0  The layout padding at the beginning and end of the line fragment rects insetting the layout width available for the contents.  This value is utilized by NSLayoutManager for determining the layout width.
@property(NS_NONATOMIC_IOSONLY) CGFloat lineFragmentPadding;

// Default value: 0 (no limit)  The maximum number of lines that can be stored in the receiver.  This value is utilized by NSLayoutManager for determining the maximum number of lines associated with the text container.
@property(NS_NONATOMIC_IOSONLY) NSUInteger maximumNumberOfLines;


/**************************** Line fragments ****************************/

// Returns the bounds of a line fragment rect inside the receiver for proposedRect.  This is the intersection of proposedRect and the receiver's bounding rect defined by -size property.  The regions defined by -exclusionPaths property are excluded from the return value.  charIndex is the character location inside the text storage for the line fragment being processed.  It is possible that proposedRect can be divided into multiple line fragments due to exclusion paths.  In that case, remainingRect returns the remainder that can be passed in as the proposed rect for the next iteration.  baseWritingDirection determines the direction of advancement for line fragments inside a visual horizontal line.  The values passed into the method are either NSWritingDirectionLeftToRight or NSWritingDirectionRightToLeft.  This method can be overridden by subclasses for further text container region customization.
- (CGRect)lineFragmentRectForProposedRect:(CGRect)proposedRect atIndex:(NSUInteger)characterIndex writingDirection:(NSWritingDirection)baseWritingDirection remainingRect:(CGRect *)remainingRect;


/**************************** View synchronization ****************************/

// Default value: NO  Define whether the text container view bounds changes can affect the text container size.
@property(NS_NONATOMIC_IOSONLY) BOOL widthTracksTextView;
@property(NS_NONATOMIC_IOSONLY) BOOL heightTracksTextView;

@end

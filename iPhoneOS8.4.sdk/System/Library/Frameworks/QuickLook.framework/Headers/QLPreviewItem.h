//
//  QLPreviewItem.h
//  Quick Look
//
//  Copyright 2008 Apple Inc. All rights reserved.
//


#import <Foundation/Foundation.h>

/*!
 * @abstract The QLPreviewItem protocol declares the methods that a QLPreviewController  instance uses to access the contents of a given item.
 */
@protocol QLPreviewItem <NSObject>

@required

/*!
 * @abstract The URL of the item to preview.
 * @discussion The URL must be a file URL. 
 */
@property(readonly) NSURL * previewItemURL;

@optional

/*!
 * @abstract The item's title this will be used as apparent item title.
 * @discussion The title replaces the default item display name. This property is optional.
 */
@property(readonly) NSString * previewItemTitle;


@end

/*!
 * @abstract This category makes NSURL instances as suitable items for the Preview Controller.
 */
@interface NSURL (QLPreviewConvenienceAdditions) <QLPreviewItem>
@end



//
//  PHContentEditingInput.h
//  Photos
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import <Photos/PhotosTypes.h>

@class PHAdjustmentData;
@class AVAsset, AVAudioMix, AVVideoComposition;
@class CLLocation;


NS_CLASS_AVAILABLE_IOS(8_0) @interface PHContentEditingInput : NSObject

@property (readonly, assign) PHAssetMediaType mediaType;
@property (readonly, assign) PHAssetMediaSubtype mediaSubtypes;
@property (readonly, copy) NSDate *creationDate;
@property (readonly, copy) CLLocation *location;
@property (readonly, copy) NSString *uniformTypeIdentifier;

// Adjustments to be applied onto the provided input image or video.
@property (readonly, strong) PHAdjustmentData *adjustmentData;

// Input image:
@property (readonly, strong) UIImage *displaySizeImage;
@property (readonly, copy) NSURL *fullSizeImageURL;
@property (readonly, assign) int fullSizeImageOrientation; // EXIF value

// Input video:
@property (readonly, strong) AVAsset *avAsset;

@end

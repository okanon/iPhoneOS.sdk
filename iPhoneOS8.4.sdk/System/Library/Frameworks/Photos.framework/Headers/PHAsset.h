//
//  PHAsset.h
//  Photos
//
//  Copyright (c) 2013 Apple Inc. All rights reserved.
//

#import <Photos/PHObject.h>
#import <Photos/PhotosTypes.h>
#import <Photos/PHPhotoLibrary.h>

#import <UIKit/UIImage.h>
#import <ImageIO/ImageIO.h>

@class CLLocation;
@class PHFetchResult;
@class PHFetchOptions;
@class PHAssetCollection;


NS_CLASS_AVAILABLE_IOS(8_0) @interface PHAsset : PHObject

#pragma mark - Properties

@property (nonatomic, assign, readonly) PHAssetMediaType mediaType;
@property (nonatomic, assign, readonly) PHAssetMediaSubtype mediaSubtypes;

@property (nonatomic, assign, readonly) NSUInteger pixelWidth;
@property (nonatomic, assign, readonly) NSUInteger pixelHeight;

@property (nonatomic, strong, readonly) NSDate *creationDate;
@property (nonatomic, strong, readonly) NSDate *modificationDate;

@property (nonatomic, strong, readonly) CLLocation *location;

@property (nonatomic, assign, readonly) NSTimeInterval duration;

// a hidden asset will be excluded from moment collections, but may still be included in other smart or regular album collections
@property (nonatomic, assign, readonly, getter=isHidden) BOOL hidden;

@property (nonatomic, assign, readonly, getter=isFavorite) BOOL favorite;

@property (nonatomic, strong, readonly) NSString *burstIdentifier;
@property (nonatomic, assign, readonly) PHAssetBurstSelectionType burstSelectionTypes;
@property (nonatomic, assign, readonly) BOOL representsBurst;

#pragma mark - Capabilities

- (BOOL)canPerformEditOperation:(PHAssetEditOperation)editOperation;

#pragma mark - Fetching assets

+ (PHFetchResult *)fetchAssetsInAssetCollection:(PHAssetCollection *)assetCollection options:(PHFetchOptions *)options;
+ (PHFetchResult *)fetchAssetsWithMediaType:(PHAssetMediaType)mediaType options:(PHFetchOptions *)options;
+ (PHFetchResult *)fetchAssetsWithLocalIdentifiers:(NSArray *)identifiers options:(PHFetchOptions *)options;
+ (PHFetchResult *)fetchKeyAssetsInAssetCollection:(PHAssetCollection *)assetCollection options:(PHFetchOptions *)options;
+ (PHFetchResult *)fetchAssetsWithBurstIdentifier:(NSString *)burstIdentifier options:(PHFetchOptions *)options;
+ (PHFetchResult *)fetchAssetsWithOptions:(PHFetchOptions *)options;

// assetURLs are URLs retrieved from ALAsset's ALAssetPropertyAssetURL
+ (PHFetchResult *)fetchAssetsWithALAssetURLs:(NSArray *)assetURLs options:(PHFetchOptions *)options;

@end

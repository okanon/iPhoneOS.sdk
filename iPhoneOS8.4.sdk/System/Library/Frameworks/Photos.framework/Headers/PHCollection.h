//
//  PHCollection.h
//  Photos
//
//  Copyright (c) 2013 Apple Inc. All rights reserved.
//

#import <Photos/PHObject.h>
#import <Photos/PhotosTypes.h>

@class PHAsset, PHCollectionList, PHFetchResult, PHFetchOptions;
@class CLLocation;


NS_CLASS_AVAILABLE_IOS(8_0) @interface PHCollection : PHObject

@property (nonatomic, assign, readonly) BOOL canContainAssets;
@property (nonatomic, assign, readonly) BOOL canContainCollections;
@property (nonatomic, strong, readonly) NSString *localizedTitle;

#pragma mark - Capabilities

- (BOOL)canPerformEditOperation:(PHCollectionEditOperation)anOperation;


#pragma mark - Fetching collections

+ (PHFetchResult *)fetchCollectionsInCollectionList:(PHCollectionList *)collectionList options:(PHFetchOptions *)options;
+ (PHFetchResult *)fetchTopLevelUserCollectionsWithOptions:(PHFetchOptions *)options;

@end


NS_CLASS_AVAILABLE_IOS(8_0) @interface PHAssetCollection : PHCollection

@property (nonatomic, assign, readonly) PHAssetCollectionType assetCollectionType;
@property (nonatomic, assign, readonly) PHAssetCollectionSubtype assetCollectionSubtype;

// These counts are just estimates; the actual count of objects returned from a fetch should be used if you care about accuracy. Returns NSNotFound if a count cannot be quickly returned.
@property (nonatomic, assign, readonly) NSUInteger estimatedAssetCount;

@property (nonatomic, strong, readonly) NSDate *startDate;
@property (nonatomic, strong, readonly) NSDate *endDate;

@property (nonatomic, strong, readonly) CLLocation *approximateLocation;
@property (nonatomic, strong, readonly) NSArray *localizedLocationNames;


#pragma mark - Fetching asset collections

+ (PHFetchResult *)fetchAssetCollectionsWithLocalIdentifiers:(NSArray *)identifiers options:(PHFetchOptions *)options;
+ (PHFetchResult *)fetchAssetCollectionsWithType:(PHAssetCollectionType)type subtype:(PHAssetCollectionSubtype)subtype options:(PHFetchOptions *)options;

// Smart Albums are not supported, only Albums and Moments
+ (PHFetchResult *)fetchAssetCollectionsContainingAsset:(PHAsset *)asset withType:(PHAssetCollectionType)type options:(PHFetchOptions *)options;

// assetGroupURLs are URLs retrieved from ALAssetGroup's ALAssetsGroupPropertyURL
+ (PHFetchResult *)fetchAssetCollectionsWithALAssetGroupURLs:(NSArray *)assetGroupURLs options:(PHFetchOptions *)options;


#pragma mark - Fetching moment asset collections

+ (PHFetchResult *)fetchMomentsInMomentList:(PHCollectionList *)momentList options:(PHFetchOptions *)options;
+ (PHFetchResult *)fetchMomentsWithOptions:(PHFetchOptions *)options;


#pragma mark - Transient asset collections
// These asset collections are only in-memory and are not persisted to disk

+ (PHAssetCollection *)transientAssetCollectionWithAssets:(NSArray *)assets title:(NSString *)title;
+ (PHAssetCollection *)transientAssetCollectionWithAssetFetchResult:(PHFetchResult *)fetchResult title:(NSString *)title;


@end


NS_CLASS_AVAILABLE_IOS(8_0) @interface PHCollectionList : PHCollection

@property (nonatomic, assign, readonly) PHCollectionListType collectionListType;
@property (nonatomic, assign, readonly) PHCollectionListSubtype collectionListSubtype;

@property (nonatomic, strong, readonly) NSDate *startDate;
@property (nonatomic, strong, readonly) NSDate *endDate;

@property (nonatomic, strong, readonly) NSArray *localizedLocationNames;


#pragma mark - Fetching collection lists

// A PHAssetCollectionTypeMoment will be contained by a PHCollectionListSubtypeMomentListCluster and a PHCollectionListSubtypeMomentListYear
// Non-moment PHAssetCollections will only be contained by a single collection list
+ (PHFetchResult *)fetchCollectionListsContainingCollection:(PHCollection *)collection options:(PHFetchOptions *)options;
+ (PHFetchResult *)fetchCollectionListsWithLocalIdentifiers:(NSArray *)identifiers options:(PHFetchOptions *)options;
+ (PHFetchResult *)fetchCollectionListsWithType:(PHCollectionListType)collectionListType subtype:(PHCollectionListSubtype)subtype options:(PHFetchOptions *)options;


#pragma mark - Fetching moment collection lists

+ (PHFetchResult *)fetchMomentListsWithSubtype:(PHCollectionListSubtype)momentListSubtype containingMoment:(PHAssetCollection *)moment options:(PHFetchOptions *)options;
+ (PHFetchResult *)fetchMomentListsWithSubtype:(PHCollectionListSubtype)momentListSubtype options:(PHFetchOptions *)options;


#pragma mark - Transient collection lists

// These collection lists are only in-memory and are not persisted to disk
+ (PHCollectionList *)transientCollectionListWithCollections:(NSArray *)collections title:(NSString *)title;
+ (PHCollectionList *)transientCollectionListWithCollectionsFetchResult:(PHFetchResult *)fetchResult title:(NSString *)title;

@end

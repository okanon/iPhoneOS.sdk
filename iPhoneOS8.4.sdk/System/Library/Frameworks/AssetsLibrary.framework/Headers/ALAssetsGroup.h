//
//  ALAssetsGroup.h
//  AssetsLibrary
//
//  Copyright 2010 Apple Inc. All rights reserved.
//
/*
 *
 * An ALAssetsGroup is a ordered set of assets. The order of its elements is the order that the user sees in the Photos application. 
 * Groups are synced via iTunes, created on the device, created to hold the users saved photos, or created during camera import. 
 * Synced groups cannot be directly modified using this API. Only user-created groups and the saved photos group can have assets added.
 */

#import <Foundation/Foundation.h>

#import <CoreGraphics/CoreGraphics.h>

#if __IPHONE_4_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED

@class ALAsset;
@class ALAssetsGroup;
@class ALAssetsFilter;

// This block is executed when a result is found. The result argument passed into the block is an ALAsset that
// matches the filter set by the caller.
// The index argument indicates which asset is being returned. In the case where no asset is found, index will be set to NSNotFound and stop to YES.
// When the enumeration is done, the block will be called with result set to nil and index set to NSNotFound.
// Setting the output argument stop to YES will finish the enumeration.
typedef void (^ALAssetsGroupEnumerationResultsBlock)(ALAsset *result, NSUInteger index, BOOL *stop);

// Groups Properties
extern NSString *const ALAssetsGroupPropertyName __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);              // An NSString with the name of the group
extern NSString *const ALAssetsGroupPropertyType __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);              // An ALAssetsGroupType wrapped in an NSNumber
extern NSString *const ALAssetsGroupPropertyPersistentID __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);      // An NSString with the group's persistent ID. 
extern NSString *const ALAssetsGroupPropertyURL __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_5_0);              // An NSURL that uniquely identifies the group



NS_CLASS_AVAILABLE(NA, 4_0)
@interface ALAssetsGroup : NSObject {
@package
    id _internal;
}

// Use this method to get information about the group.
- (id)valueForProperty:(NSString *)property;

// Returns a CGImage of the poster photo for the group.  The thumbnail will be in the correct orientation.
- (CGImageRef)posterImage;

// Set the ALAssetsFilter on the group to filter the group contents. This does not execute the filter. 
// For that, -enumerateAssetsUsingBlock:doneBlock: or -numberOfAssets needs to be called. 
// If no filter is set, the enumeration will return all the assets in the group.
// Only one filter is active at a time. Calling this method again resets the filter and does not affect any enumeration that may be in flight.
- (void)setAssetsFilter:(ALAssetsFilter *)filter;

// Get the number of assets in the group that match the filter.
// If no filter is set, it returns the count of all assets in the group.
- (NSInteger)numberOfAssets;

// These methods are used to retrieve the assets that match the filter.  
// The caller can specify which results are returned using an NSIndexSet. The index set's count or lastIndex cannot exceed -numberOfAssets.
// 'enumerationBlock' is used to pass back results to the caller and provide the opportunity to stop the filter.
// When the enumeration is done, 'enumerationBlock' will be called with result set to nil and index set to NSNotFound.
// If the application has not been granted access to the data, 'enumerationBlock' will be called with result set to nil, index set to NSNotFound, and stop set to YES.
- (void)enumerateAssetsUsingBlock:(ALAssetsGroupEnumerationResultsBlock)enumerationBlock;
- (void)enumerateAssetsWithOptions:(NSEnumerationOptions)options usingBlock:(ALAssetsGroupEnumerationResultsBlock)enumerationBlock;
- (void)enumerateAssetsAtIndexes:(NSIndexSet *)indexSet options:(NSEnumerationOptions)options usingBlock:(ALAssetsGroupEnumerationResultsBlock)enumerationBlock;

// Returns YES if the application is able to edit the group.  Returns NO if the application is not able to edit the group.
@property (nonatomic, readonly, getter=isEditable) BOOL editable __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_5_0);

// Add an existing ALAsset to the group.  An asset can belong to multiple ALAssetsGroups.
// The caller should check the editable property of the group to see if it is possible to add an asset to the group.
// Returns YES if the asset was added successfully.  Returns NO if the group is not editable, or if the asset was not able to be added to the group.
- (BOOL)addAsset:(ALAsset *)asset __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_5_0);

@end

#endif

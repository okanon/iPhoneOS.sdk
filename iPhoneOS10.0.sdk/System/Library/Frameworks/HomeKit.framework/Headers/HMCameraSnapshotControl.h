//
//  HMCameraSnapshotControl.h
//  HomeKit
//
//  Copyright © 2016 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <HomeKit/HMCameraControl.h>

#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@class HMCameraSnapshot;
@protocol HMCameraSnapshotControlDelegate;

/*!
 * @abstract This class can be used to take an image snapshot from a camera.
 */
__IOS_AVAILABLE(10_0) __WATCHOS_AVAILABLE(3_0) __TVOS_AVAILABLE(10_0)
@interface HMCameraSnapshotControl : HMCameraControl

/*!
 * @brief Delegate that receives updates on the camera stream changes.
 */
@property(weak, nonatomic) id<HMCameraSnapshotControlDelegate> delegate;

/*!
 * @brief Represents the most recent snapshot taken from the camera.
 */
@property(readonly, strong, nonatomic, nullable) HMCameraSnapshot *mostRecentSnapshot;

/*!
 * @brief Takes an image snapshot.
 *
 * @param resolution Desired video resolution of the stream. This parameter is only a suggested resolution.
 */
- (void)takeSnapshot;

@end


/*!
 * @brief This delegate receives updates on the camera stream.
 */
__IOS_AVAILABLE(10_0) __WATCHOS_AVAILABLE(3_0) __TVOS_AVAILABLE(10_0)
@protocol HMCameraSnapshotControlDelegate <NSObject>

@optional

/*!
 * @brief Informs the delegate that the snapshot was taken.
 *
 * @param cameraStreamControl Sender of this message.
 *
 * @param snapshot Snapshot will be valid if snapshot was successfully taken.
 *
 * @param error Error will be populated if the snapshot could not be taken.
 */
- (void)cameraSnapshotControl:(HMCameraSnapshotControl *)cameraSnapshotControl
              didTakeSnapshot:(HMCameraSnapshot *__nullable)snapshot
                        error:(NSError *__nullable)error;

@end

NS_ASSUME_NONNULL_END


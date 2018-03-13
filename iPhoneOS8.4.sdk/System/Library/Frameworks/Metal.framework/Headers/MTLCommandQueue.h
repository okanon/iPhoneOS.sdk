//
//  MTLCommandQueue.h
//  Metal
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Metal/MTLDefines.h>
#import <Metal/Metal.h>

@protocol MTLDevice;
@protocol MTLCommandBuffer;

/*!
 @protocol MTLCommandQueue
 @brief A serial queue of command buffers to be executed by the device.
 */
NS_AVAILABLE_IOS(8_0)
@protocol MTLCommandQueue <NSObject>

/*! @brief A string to help identify this object */
@property (copy, atomic) NSString *label;

/*! @brief The device this queue will submit to */
@property (readonly) id <MTLDevice> device;

/*! 
 @method commandBuffer
 @abstract Returns a new autoreleased command buffer used to encode work into this queue
*/
- (id <MTLCommandBuffer>)commandBuffer;

/*!
 @method commandBufferWithUnretainedReferences
 @abstract Returns a new autoreleased command buffer used to encode work into this queue
*/
- (id <MTLCommandBuffer>)commandBufferWithUnretainedReferences;

/*!
 @method insertDebugCaptureBoundary
 @abstract Inform Xcode about when debug capture should start and stop.
 */
- (void)insertDebugCaptureBoundary;

@end

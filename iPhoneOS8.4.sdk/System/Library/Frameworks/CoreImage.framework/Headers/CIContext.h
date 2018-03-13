/* CoreImage - CIContext.h

   Copyright (c) 2011 Apple, Inc.
   All rights reserved. */

#import <CoreImage/CIImage.h>
#import <CoreImage/CoreImageDefines.h>
#import <CoreVideo/CoreVideo.h>

#if TARGET_OS_IPHONE
 #import <OpenGLES/EAGL.h>
#else
 #import <OpenGL/CGLTypes.h>
#endif 

struct CIContextInternal;

@class CIFilter;

CORE_IMAGE_CLASS_EXPORT
@interface CIContext : NSObject
{
    struct CIContextInternal *_priv;
}

/* Keys that may be passed in the dictionary while creating contexts: */

/* A CGColorSpaceRef object defining the color space that images are
 * converted to before rendering into the context. */
CORE_IMAGE_EXPORT NSString * const kCIContextOutputColorSpace;

/* A CGColorSpaceRef object defining the color space in which all
 * intermediate operations are performed. */
CORE_IMAGE_EXPORT NSString * const kCIContextWorkingColorSpace;

/* An NSNumber with a CIFormat value defining the pixel format to use for intermediate buffers.
 * By default, this is RGBA8 on the GPU and RGBAf when using software rendering.
 * Also supported is RGBAh on the GPU. */
CORE_IMAGE_EXPORT NSString * const kCIContextWorkingFormat __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_8_0);

/* An NSNumber with a boolean value. When @YES the context will use
 * software rendering. */
CORE_IMAGE_EXPORT NSString * const kCIContextUseSoftwareRenderer;

/* An NSNumber with a boolean value. When @YES the context will use 
 * low priority rendering on the GPU. */
CORE_IMAGE_EXPORT NSString * const kCIContextPriorityRequestLow __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_8_0);

/* Create a new CoreImage context object, all output will be drawn
 * into the surface attached to the OpenGL context 'ctx'. If 'pf' is
 * non-null it should be the pixel format object used to create 'ctx';
 * it's required to be valid for the lifetime of the CIContext.
 * The colorspace should be set to the colorspace of your target otherwise
 * CI will take the colorspace from the CGLContext if available. */
#if !TARGET_OS_IPHONE
+ (CIContext *)contextWithCGLContext:(CGLContextObj)ctx
						 pixelFormat:(CGLPixelFormatObj)pf
						  colorSpace:(CGColorSpaceRef)cs
							 options:(NSDictionary *)dict __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);
#endif

/* DEPRECATED, please use the method above or if you need this
* for backward capability, make sure that you specify the colorspace
* in the options dictionary */
#if !TARGET_OS_IPHONE
+ (CIContext *)contextWithCGLContext:(CGLContextObj)ctx
						 pixelFormat:(CGLPixelFormatObj)pf
							 options:(NSDictionary *)dict
__OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_4,__MAC_10_6,__IPHONE_NA,__IPHONE_NA);
#endif

/* Create a new CoreImage context object, all output will be drawn
 * into the CG context 'ctx'. */
+ (CIContext *)contextWithCGContext:(CGContextRef)ctx
							options:(NSDictionary *)dict __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);

+ (CIContext *)contextWithOptions:(NSDictionary *)dict __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_5_0);

#if TARGET_OS_IPHONE
/* Create a new CoreImage context object using 'eaglContext' 
 * Calls to drawImage:atPoint:fromRect: and drawImage:inRect:fromRect:
 * will draw directly though the context. */
+ (CIContext *)contextWithEAGLContext:(EAGLContext *)eaglContext
    __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_5_0);

+ (CIContext *)contextWithEAGLContext:(EAGLContext *)eaglContext
                              options:(NSDictionary *)dict
    __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_5_0);
#endif

/* DEPRECATED - use -drawImage:inRect:fromRect:
 * Render the subregion 'src' of 'im' to point 'p' in the context's
 * destination. */
- (void)drawImage:(CIImage *)im atPoint:(CGPoint)p fromRect:(CGRect)src __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_4, __MAC_10_8, __IPHONE_5_0, __IPHONE_6_0);

/* Render the rectangle 'src' of 'im' to the rectangle 'dest' in the
 * context's destination. */
- (void)drawImage:(CIImage *)im inRect:(CGRect)dest fromRect:(CGRect)src;

/* Render the region 'r' of image 'im' into a temporary buffer using
 * the context, then create and return a new CoreGraphics image with
 * the results. The caller is responsible for releasing the returned
 * image. */
- (CGImageRef)createCGImage:(CIImage *)im fromRect:(CGRect)r 
    CF_RETURNS_RETAINED;

/* Create a new CGImage from the specified subrect of the image. If
 * non-nil the new image will be created in the specified format and
 * colorspace. */
- (CGImageRef)createCGImage:(CIImage *)im fromRect:(CGRect)r 
                     format:(CIFormat)f colorSpace:(CGColorSpaceRef)cs
    CF_RETURNS_RETAINED;

/* Create a CoreGraphics layer object suitable for creating content for
 * subsequently rendering into this CI context. The 'd' parameter is
 * passed into CGLayerCreate () as the auxiliaryInfo dictionary. */
- (CGLayerRef)createCGLayerWithSize:(CGSize)size info:(CFDictionaryRef)d __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);

/* Render to the given bitmap. Null colorspace means to use the context's
 output colorspace. */
- (void)render:(CIImage *)im
	  toBitmap:(void *)data
	  rowBytes:(ptrdiff_t)rb
		bounds:(CGRect)r
		format:(CIFormat)f
	colorSpace:(CGColorSpaceRef)cs;

#if !TARGET_OS_IPHONE
/* Render to the given IOSurface. */
- (void)render:(CIImage *)im
   toIOSurface:(IOSurfaceRef)surface
		bounds:(CGRect)r
	colorSpace:(CGColorSpaceRef)cs
__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);
#endif

/* Render 'image' into a CVPixelBuffer using the context. */
- (void)render:(CIImage *)image 
toCVPixelBuffer:(CVPixelBufferRef)buffer
    __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_5_0);

- (void)render:(CIImage *)image 
toCVPixelBuffer:(CVPixelBufferRef)buffer
        bounds:(CGRect)r
    colorSpace:(CGColorSpaceRef)cs
    __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_5_0);


/* Runs the context's garbage collector to reclaim any resources that
 * are no longer required (e.g. removes textures from the texture cache
 * that reference deleted images.) This method is called automatically
 * after every rendering operation. */
- (void)reclaimResources __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);

/* Frees any cached data (such as temporary images) associated with the
 * context. This also runs the garbage collector. */
- (void)clearCaches __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);

/* Returns the maximum dimension for input images that can be processed 
 * on the currect context. */
- (CGSize)inputImageMaximumSize __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_5_0);

/* Returns the maximum dimension for image that can be rendered 
 * on the currect context. */
- (CGSize)outputImageMaximumSize __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_5_0);

@end

#import <CoreImage/CoreImageDefines.h>
#import <Foundation/Foundation.h>


typedef CGRect (^CIKernelROICallback)(int index, CGRect rect);

@class CIImage;


CORE_IMAGE_CLASS_EXPORT
@interface CIKernel : NSObject
{
	void *_priv;
}

/* The string 's' should contain a program in the CoreImage dialect
 * of the OpenGL Shading Language. Each function marked as a kernel is
 * converted to a CIKernel, CIColorKernel, or CIWarpKernel object.
 * all objects are then returned in an array.
 */
+ (NSArray *)kernelsWithString:(NSString *)s;

/* The string 's' should contain a program with one kernel.
 * Returns a a CIKernel, CIColorKernel, or CIWarpKernel object.
 */
+ (instancetype) kernelWithString:(NSString *)string  __OSX_AVAILABLE_STARTING(__MAC_10_10, __IPHONE_8_0);

/* Returns the name of the kernel. */
- (NSString *)name;

- (CIImage *)applyWithExtent:(CGRect)extent
                 roiCallback:(CIKernelROICallback)callback
                   arguments:(NSArray*)args  __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_8_0);
@end


CORE_IMAGE_CLASS_EXPORT
@interface CIColorKernel : CIKernel
{
}
- (CIImage *)applyWithExtent:(CGRect)extent
                   arguments:(NSArray*)args  __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_8_0);
@end


CORE_IMAGE_CLASS_EXPORT
@interface CIWarpKernel : CIKernel
{
}
- (CIImage *)applyWithExtent:(CGRect)extent
                 roiCallback:(CIKernelROICallback)callback
                  inputImage:(CIImage*)image
                   arguments:(NSArray*)args  __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_8_0);
@end

/* CoreImage - CoreImage.h
 
 Copyright (c) 2011 Apple, Inc.
 All rights reserved. */

#ifdef __OBJC__

#import <Foundation/Foundation.h>

#import <CoreImage/CIColor.h>
#import <CoreImage/CIContext.h>
#import <CoreImage/CIFilter.h>
#if !TARGET_OS_IPHONE
#import <CoreImage/CIFilterGenerator.h>
#import <CoreImage/CIFilterShape.h>
#endif
#import <CoreImage/CIImage.h>
#if !TARGET_OS_IPHONE
#import <CoreImage/CIImageAccumulator.h>
#import <CoreImage/CIImageProvider.h>
#import <CoreImage/CIKernel.h>
#import <CoreImage/CIPlugIn.h>
#import <CoreImage/CIRAWFilter.h>
#import <CoreImage/CISampler.h>
#endif
#import <CoreImage/CIVector.h>
#import <CoreImage/CIDetector.h>
#import <CoreImage/CIFeature.h>
#import <CoreImage/CIKernel.h>

#endif /* __OBJC__ */

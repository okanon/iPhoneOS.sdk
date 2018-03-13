/* CoreImage - CIFilter.h

   Copyright (c) 2011 Apple, Inc.
   All rights reserved. */


#import <Foundation/Foundation.h>
#import <CoreImage/CoreImageDefines.h>

@class NSURL;



/* Filter attribute strings. */

/* Keys */

/** Name of the filter */
CORE_IMAGE_EXPORT NSString *kCIAttributeFilterName;

/** Name of the filter intended for UI display (eg. localized) */
CORE_IMAGE_EXPORT NSString *kCIAttributeFilterDisplayName;

/** Description of the filter intended for UI display (eg. localized) - Available in Leopard onwards. */
CORE_IMAGE_EXPORT NSString *kCIAttributeDescription __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);

/** URL for the reference documentation of the filter. See localizedReferenceDocumentationForFilterName - Available in Leopard onwards. */
CORE_IMAGE_EXPORT NSString *kCIAttributeReferenceDocumentation __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);

/** Array of filter category names (see below) */
CORE_IMAGE_EXPORT NSString *kCIAttributeFilterCategories;

/** Class name of the filter. */
CORE_IMAGE_EXPORT NSString *kCIAttributeClass;

/** The type of the attribute e.g. scalar, time, distance, etc. */
CORE_IMAGE_EXPORT NSString *kCIAttributeType;

/** Minimum value for the attribute. */
CORE_IMAGE_EXPORT NSString *kCIAttributeMin;

/** Maximum value for the attribute. */
CORE_IMAGE_EXPORT NSString *kCIAttributeMax;

/** Minimum value for the slider. */
CORE_IMAGE_EXPORT NSString *kCIAttributeSliderMin;

/** Maximum value for the slider. */
CORE_IMAGE_EXPORT NSString *kCIAttributeSliderMax;

/** Default value for the slider. */
CORE_IMAGE_EXPORT NSString *kCIAttributeDefault;

/** The identity value is the value at which the filter has no effect. */
CORE_IMAGE_EXPORT NSString *kCIAttributeIdentity;

/** The non-localized name of the attribute. */
CORE_IMAGE_EXPORT NSString *kCIAttributeName;

/** The localized name of the attribute to be used for display to the user. */
CORE_IMAGE_EXPORT NSString *kCIAttributeDisplayName;

/** Key to request the desired set of controls in a filter UIView - defined values are CIUISetBasic, CIUISetIntermediate, CIUISetAdvanced and CIUISetDevelopment. */
CORE_IMAGE_EXPORT NSString *kCIUIParameterSet __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);

/** Constant for requesting controls that are appropiate in an basic user scenario, meaning the bare minimum of settings to control the filter. */
CORE_IMAGE_EXPORT NSString *kCIUISetBasic __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);

/** Constant for requesting controls that are appropiate in an intermediate user scenario. */
CORE_IMAGE_EXPORT NSString *kCIUISetIntermediate __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);

/** Constant for requesting controls that are appropiate in an advanced user scenario. */
CORE_IMAGE_EXPORT NSString *kCIUISetAdvanced __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);

/** Constant for requesting controls that should only be visible for development purposes. */
CORE_IMAGE_EXPORT NSString *kCIUISetDevelopment __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);


/* Types for numbers */

CORE_IMAGE_EXPORT NSString *kCIAttributeTypeTime;
CORE_IMAGE_EXPORT NSString *kCIAttributeTypeScalar;
CORE_IMAGE_EXPORT NSString *kCIAttributeTypeDistance;
CORE_IMAGE_EXPORT NSString *kCIAttributeTypeAngle;
CORE_IMAGE_EXPORT NSString *kCIAttributeTypeBoolean;

/** Indicates that the key uses integer values. */
CORE_IMAGE_EXPORT NSString *kCIAttributeTypeInteger __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_5_0);


/** Indicates that the key uses non negative integer values. */
CORE_IMAGE_EXPORT NSString *kCIAttributeTypeCount __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_5_0);

/* Types for 2-element vectors */
CORE_IMAGE_EXPORT NSString *kCIAttributeTypePosition;
CORE_IMAGE_EXPORT NSString *kCIAttributeTypeOffset;

/* Types for 3-element vectors */
CORE_IMAGE_EXPORT NSString *kCIAttributeTypePosition3;

/* Types for 4-element vectors */
CORE_IMAGE_EXPORT NSString *kCIAttributeTypeRectangle;

/* Types for colors */
CORE_IMAGE_EXPORT NSString *kCIAttributeTypeColor;

/* Types for images */
CORE_IMAGE_EXPORT NSString *kCIAttributeTypeGradient  __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_NA);
CORE_IMAGE_EXPORT NSString *kCIAttributeTypeImage __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_5_0);
CORE_IMAGE_EXPORT NSString *kCIAttributeTypeTransform __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_5_0);

/* Categories */
CORE_IMAGE_EXPORT NSString *kCICategoryDistortionEffect;
CORE_IMAGE_EXPORT NSString *kCICategoryGeometryAdjustment;
CORE_IMAGE_EXPORT NSString *kCICategoryCompositeOperation;
CORE_IMAGE_EXPORT NSString *kCICategoryHalftoneEffect;
CORE_IMAGE_EXPORT NSString *kCICategoryColorAdjustment;
CORE_IMAGE_EXPORT NSString *kCICategoryColorEffect;
CORE_IMAGE_EXPORT NSString *kCICategoryTransition;
CORE_IMAGE_EXPORT NSString *kCICategoryTileEffect;
CORE_IMAGE_EXPORT NSString *kCICategoryGenerator;
CORE_IMAGE_EXPORT NSString *kCICategoryReduction __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_5_0);
CORE_IMAGE_EXPORT NSString *kCICategoryGradient;
CORE_IMAGE_EXPORT NSString *kCICategoryStylize;
CORE_IMAGE_EXPORT NSString *kCICategorySharpen;
CORE_IMAGE_EXPORT NSString *kCICategoryBlur;

CORE_IMAGE_EXPORT NSString *kCICategoryVideo;
CORE_IMAGE_EXPORT NSString *kCICategoryStillImage;
CORE_IMAGE_EXPORT NSString *kCICategoryInterlaced;
CORE_IMAGE_EXPORT NSString *kCICategoryNonSquarePixels;
CORE_IMAGE_EXPORT NSString *kCICategoryHighDynamicRange;

CORE_IMAGE_EXPORT NSString *kCICategoryBuiltIn;
CORE_IMAGE_EXPORT NSString *kCICategoryFilterGenerator __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);

/* Keys for apply: method options. */

CORE_IMAGE_EXPORT NSString *kCIApplyOptionExtent __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);
CORE_IMAGE_EXPORT NSString *kCIApplyOptionDefinition __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);
CORE_IMAGE_EXPORT NSString *kCIApplyOptionUserInfo __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);

/* If used, the value of the kCIApplyOptionColorSpace key be must be an RGB CGColorSpaceRef.
 * Using this option specifies that the output of the kernel is in this color space. 
 * If not specified, the output of the kernel is in the working color space of the rendering CIContext. */
CORE_IMAGE_EXPORT NSString *kCIApplyOptionColorSpace __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);

/* common filter parameter keys */

CORE_IMAGE_EXPORT NSString *kCIOutputImageKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_5_0);
CORE_IMAGE_EXPORT NSString *kCIInputBackgroundImageKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_5_0);
CORE_IMAGE_EXPORT NSString *kCIInputImageKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_5_0);
CORE_IMAGE_EXPORT NSString *kCIInputTimeKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputTransformKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputScaleKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputAspectRatioKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputCenterKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputRadiusKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputAngleKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputRefractionKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
CORE_IMAGE_EXPORT NSString *kCIInputWidthKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputSharpnessKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputIntensityKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputEVKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputSaturationKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputColorKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputBrightnessKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputContrastKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputGradientImageKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
CORE_IMAGE_EXPORT NSString *kCIInputMaskImageKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputShadingImageKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
CORE_IMAGE_EXPORT NSString *kCIInputTargetImageKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputExtentKey __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_7_0);
CORE_IMAGE_EXPORT NSString *kCIInputVersionKey __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_6_0);

@class NSArray, NSDictionary;
@class CIKernel, CIImage;
@protocol CIFilterConstructor;

/** CIFilter are filter objects for Core Image that encapsulate the filter with its attributes
 
 The CIFilter class produces a CIImage object as output. Typically, a filter takes one or more images as input. Some filters, however, generate an image based on other types of input parameters. The parameters of a CIFilter object are set and retrieved through the use of key-value pairs. You use the CIFilter object in conjunction with the CIImage, CIContext, CIVector, CIImageAccumulator, and CIColor objects to take advantage of the built-in Core Image filters when processing images. CIFilter objects are also used along with CIKernel, CISampler, and CIFilterShape objects to create custom filters. */
CORE_IMAGE_CLASS_EXPORT
@interface CIFilter : NSObject <NSCoding, NSCopying>
{
    void *_priv[8];
}

@property (readonly, nonatomic) CIImage *outputImage;

/* name of the filter */
- (NSString*)name __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_5_0);

/** Returns an array containing the names of all inputs in the filter. */
- (NSArray *)inputKeys;

/** Returns an array containing the names of all outputs in the filter. */
- (NSArray *)outputKeys;

/** Sets all inputs to their default values (where default values are defined, other inputs are left as-is). */
- (void)setDefaults;

/** Returns a dictionary containing key/value pairs describing the filter. (see description of keys below) */
- (NSDictionary *)attributes;
	

/** Used by CIFilter subclasses to apply the array of argument values 'args' to the kernel function 'k'. The supplied arguments must be type-compatible with the function signature of the kernel.
 
 The key-value pairs defined by 'dict' (if non-nil) are used to control exactly how the kernel is evaluated. Valid keys include:
 kCIApplyOptionExtent: the size of the produced image. Value is a four element NSArray [X Y WIDTH HEIGHT].
 kCIApplyOptionDefinition: the Domain of Definition of the produced image. Value is either a CIFilterShape object, or a four element NSArray defining a rectangle.
 @param  k         CIKernel of the filter
 @param  args      Array of arguments that are applied to the kernel
 @param  options   Array of additional options
*/
- (CIImage *)apply:(CIKernel *)k
		 arguments:(NSArray *)args
		   options:(NSDictionary *)dict __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);

/** Similar to above except that all argument values and option key-value are specified inline. The list of key-value pairs must be terminated by the 'nil' object. */
- (CIImage *)apply:(CIKernel *)k, ... NS_REQUIRES_NIL_TERMINATION __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);

@end


/** Methods to register a filter and get access to the list of registered filters
 Use these methods to create filters and find filters. */
@interface CIFilter (CIFilterRegistry)

/** Creates a new filter of type 'name'. 
 All input values will be set to default values. */
+ (CIFilter *) filterWithName:(NSString *) name;

/** Creates a new filter of type 'name'.
 The filter's input parameters are set from the list of key-value pairs which must be nil-terminated.
 Any of the filter's input parameters not specified in the list will be left with default values. */
+ (CIFilter *)filterWithName:(NSString *)name keysAndValues:key0, ... NS_REQUIRES_NIL_TERMINATION;

/** Creates a new filter of type 'name'.
 The filter's input parameters are set from the dictionary of key-value pairs.
 Any of the filter's input parameters not specified in the list will be left with default values. */
+ (CIFilter *)filterWithName:(NSString *)name withInputParameters:(NSDictionary*)params __OSX_AVAILABLE_STARTING(__MAC_10_10, __IPHONE_8_0);


/** Returns an array containing all published filter names in a category. */
+ (NSArray *)filterNamesInCategory:(NSString *)category;

/** Returns an array containing all published filter names that belong to all listed categories. */
+ (NSArray *)filterNamesInCategories:(NSArray *)categories;


/** Publishes a new filter called 'name'.
 
 The constructor object 'anObject' should implement the filterWithName: method, it will be invoked with the name of the filter to create. The class attributes must have akCIAttributeFilterCategories key associated with a set of categories.
 @param   attributes    Dictionary of the registration attributes of the filter. See below for attribute keys.
*/
+ (void)registerFilterName:(NSString *)name
			   constructor:(id<CIFilterConstructor>)anObject
		   classAttributes:(NSDictionary *)attributes __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);

/** Returns the localized name of a filter for display in the UI. */
+ (NSString *)localizedNameForFilterName:(NSString *)filterName __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);

/** Returns the localized name of a category for display in the UI. */
+ (NSString *)localizedNameForCategory:(NSString *)category __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);

/** Returns the localized description of a filter for display in the UI. */
+ (NSString *)localizedDescriptionForFilterName:(NSString *)filterName __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);

/** Returns the URL to the localized reference documentation describing the filter.
    
 The URL can be a local file or a remote document on a webserver. It is possible, that this method returns nil (like filters that predate this feature). A client of this API has to handle this case gracefully. */
+ (NSURL *)localizedReferenceDocumentationForFilterName:(NSString *)filterName __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);

@end


/** Methods to serialize arrays of filters to xmp. */
@interface CIFilter (CIFilterXMPSerialization)

/* Given an array of filters, serialize the filters' parameters 
   into XMP form that is suitable for embedding in to an image.
   At this time the only filters classes that are serialized
   are, CIAffineTransform, CICrop, and the filters returned by 
   [CIImage autoAdjustmentFilters].  
   The parameters of other filter classes will not be serialized.
 */
+ (NSData*)serializedXMPFromFilters:(NSArray *)filters
                   inputImageExtent:(CGRect)extent
   __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_6_0);

/* Return an array of CIFilters de-serialized from XMP data.
 */
+ (NSArray*)filterArrayFromSerializedXMP:(NSData *)xmpData
                        inputImageExtent:(CGRect)extent
                                   error:(NSError **)outError
   __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_6_0);

@end

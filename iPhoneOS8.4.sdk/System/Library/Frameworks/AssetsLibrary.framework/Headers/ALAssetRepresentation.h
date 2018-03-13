//
//  ALAssetRepresentation.h
//  AssetsLibrary
//
//  Copyright 2010 Apple Inc. All rights reserved.
//
/*
 *
 * An ALAssetRepresentation encapsulates one of the representations of a given ALAsset.
 * For example: in the case of a camera shooting RAW + JPEG, the resulting asset will have two representations,
 *              one for the RAW file and one for the JPEG file.
 *
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <AssetsLibrary/AssetsLibrary.h>

#if __IPHONE_4_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED

NS_CLASS_AVAILABLE(NA, 4_0)
@interface ALAssetRepresentation : NSObject {
@package
    id _internal;
}

// Returns the representation's UTI.
- (NSString *)UTI;

// Returns the dimensions of this representation.  If the representation does not have valid dimensions, this method will return CGSizeZero.
- (CGSize)dimensions;

// Returns the size of the file for this representation. Callers can use this to allocate buffers of the right size for -getBytes:fromOffset:length:error:
- (long long)size;

// Copies the specified range of bytes into the buffer given by the caller.
// The method returns the number of bytes actually written to the buffer. The number of bytes read will be 
// less than the requested range if the range exceeds the file's size.
// If an error occurs, the method returns 0 and upon return contains an NSError object that describes the problem. Pass NULL if you do not want error information.
- (NSUInteger)getBytes:(uint8_t *)buffer fromOffset:(long long)offset length:(NSUInteger)length error:(NSError **)error;

// This is a convenience method for -[ALAssetRepresentation CGImageWithOptions:] where options is nil.
- (CGImageRef)fullResolutionImage;

// This is a convenience method that returns a full resolution CGImage of the representation. It takes a dictionary
// of options as described for CGImageSourceCreateWithData() or CGImageSourceCreateWithURL()
- (CGImageRef)CGImageWithOptions:(NSDictionary *)options;

// Returns a CGImage of the representation that is appropriate for displaying full screen.
// The dimensions of this image will be dependent on the hardware that the application is running on and does not mean it will match the dimensions of the screen.
- (CGImageRef)fullScreenImage;

// Returns a persistent URL uniquely identifying the representation
- (NSURL *)url;

// Returns a dictionary of dictionaries of metadata for the representation.
// If the representation is one that the system cannot interpret, nil is returned.
- (NSDictionary *)metadata;

// Returns the representation's orientation as defined in ALAssetOrientation.
- (ALAssetOrientation)orientation;

// Returns the representation's scale.
- (float)scale;

// Returns a string representing the filename of the representation on disk.  
// For representations synced from iTunes, this will be the filename of the represenation on the host.
- (NSString *)filename __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_5_0);

@end

#endif

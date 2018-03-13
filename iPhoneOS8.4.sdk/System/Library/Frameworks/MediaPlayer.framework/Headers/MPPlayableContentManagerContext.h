//
//  MPPlayableContentManagerContext.h
//  MobileMusicPlayer
//
//  Copyright © 2015 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MediaPlayer/MediaPlayerDefines.h>


/// MPPlayableContentManagerContext represents the current state of
/// the playable content endpoint. A context is retrievable from an instance
/// of MPPlayableContentManager.
MP_EXTERN_CLASS_AVAILABLE(8_4)
@interface MPPlayableContentManagerContext : NSObject

/// The number of items the content server will display when content limiting is enforced.
@property (nonatomic, readonly) NSInteger enforcedContentItemsCount;

/// The depth of the navigation hierarchy the content server will allow. Exceeding this limit will result in a crash.
@property (nonatomic, readonly) NSInteger enforcedContentTreeDepth;

/// Represents whether content limits are being enforced by the content server or not.
@property (nonatomic, readonly) BOOL contentLimitsEnabled;

/// Represents whether the content server is available or not.
@property (nonatomic, readonly) BOOL endpointAvailable;

@end

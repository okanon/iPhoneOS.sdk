//
//  EventKitDefines.h
//  EventKit
//
//  Copyright 2010 Apple Inc. All rights reserved.
//

#ifdef __cplusplus
#define EVENTKIT_EXTERN		extern "C" __attribute__((visibility ("default")))
#else
#define EVENTKIT_EXTERN	        extern __attribute__((visibility ("default")))
#endif

#define EVENTKIT_CLASS_AVAILABLE(_macIntro, _iphoneIntro) __attribute__((visibility("default"))) NS_CLASS_AVAILABLE(_macIntro, _iphoneIntro)
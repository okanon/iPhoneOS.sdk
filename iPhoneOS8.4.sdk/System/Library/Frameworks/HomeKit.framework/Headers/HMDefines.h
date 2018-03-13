//
// HMDefines.h
// HomeKit
//
//  Copyright (c) 2013-2014 Apple Inc. All rights reserved.
//

#ifndef HM_EXTERN
#ifdef __cplusplus
#define HM_EXTERN   extern "C" __attribute__((visibility ("default")))
#else
#define HM_EXTERN   extern __attribute__((visibility ("default")))
#endif
#endif

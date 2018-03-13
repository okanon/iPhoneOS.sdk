/* CoreImage - CoreImageDefines.h
 
 Copyright (c) 2011 Apple, Inc.
 All rights reserved. */

#ifndef COREIMAGEDEFINES_H
#define COREIMAGEDEFINES_H

#include <TargetConditionals.h>
#include <Availability.h>

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <CoreGraphics/CoreGraphics.h>

#ifdef __cplusplus
 #define CI_EXTERN_C_BEGIN  extern "C" {
 #define CI_EXTERN_C_END  }
#else
 #define CI_EXTERN_C_BEGIN
 #define CI_EXTERN_C_END
#endif

#ifdef __cplusplus
# define CORE_IMAGE_EXPORT extern "C" __attribute__((visibility("default")))
#else
# define CORE_IMAGE_EXPORT extern __attribute__((visibility("default")))
#endif

#define CORE_IMAGE_CLASS_EXPORT __attribute__((visibility("default")))

#endif /* COREIMAGEDEFINES_H */

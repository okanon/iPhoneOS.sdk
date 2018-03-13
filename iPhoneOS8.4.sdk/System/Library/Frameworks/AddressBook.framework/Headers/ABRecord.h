/*
 *  ABRecord.h
 *  AddressBook
 *
 *  Copyright (c) 2010 Apple Inc. All rights reserved.
 *
 *  An ABRecord corresponds to a persistent item, currently either
 *  a contact or a group. Records have a unique persistent integer
 *  ID and a collection of properties with integer keys.
 *
 */

#ifndef __ABRecord__
#define __ABRecord__

#include <AddressBook/AddressBookDefines.h>
#include <CoreFoundation/CoreFoundation.h>
        
typedef CFTypeRef ABRecordRef;

typedef int32_t ABRecordID;
typedef int32_t ABPropertyID;

typedef uint32_t ABRecordType;
enum {
    kABPersonType = 0,
    kABGroupType  = 1,
    kABSourceType = 2
};

#define kABMultiValueMask (1 << 8)
#define kABRecordInvalidID -1
#define kABPropertyInvalidID -1

typedef uint32_t ABPropertyType;
enum {
    kABInvalidPropertyType         = 0x0,
    kABStringPropertyType          = 0x1,
    kABIntegerPropertyType         = 0x2,
    kABRealPropertyType            = 0x3,
    kABDateTimePropertyType        = 0x4,
    kABDictionaryPropertyType      = 0x5,
    kABMultiStringPropertyType     = kABMultiValueMask | kABStringPropertyType,
    kABMultiIntegerPropertyType    = kABMultiValueMask | kABIntegerPropertyType,
    kABMultiRealPropertyType       = kABMultiValueMask | kABRealPropertyType,
    kABMultiDateTimePropertyType   = kABMultiValueMask | kABDateTimePropertyType,
    kABMultiDictionaryPropertyType = kABMultiValueMask | kABDictionaryPropertyType,
};

AB_EXTERN ABRecordID ABRecordGetRecordID(ABRecordRef record);
AB_EXTERN ABRecordType ABRecordGetRecordType(ABRecordRef record);

AB_EXTERN CFTypeRef ABRecordCopyValue(ABRecordRef record, ABPropertyID property);
AB_EXTERN bool ABRecordSetValue(ABRecordRef record, ABPropertyID property, CFTypeRef value, CFErrorRef* error);
AB_EXTERN bool ABRecordRemoveValue(ABRecordRef record, ABPropertyID property, CFErrorRef* error);
    
AB_EXTERN CFStringRef ABRecordCopyCompositeName(ABRecordRef record);

#endif


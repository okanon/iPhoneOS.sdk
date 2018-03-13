/*
 *  ABMultiValue.h
 *  AddressBook
 *
 *  Copyright (c) 2010 Apple Inc. All rights reserved.
 *
 *  MultiValues are ordered, homogeneous collections of values. Each
 *  value has a unique persistent identifier which can be use to
 *  identify the value across changes to the MultiValue (ie. when
 *  the value's index may have changed). Each value may also have a
 *  non-unique string label.
 *
 */

#ifndef __ABMultiValue__
#define __ABMultiValue__

#include <CoreFoundation/CoreFoundation.h>
#include <AddressBook/AddressBookDefines.h>
#include <AddressBook/ABRecord.h>

typedef CFTypeRef ABMultiValueRef;

typedef int32_t ABMultiValueIdentifier;
#define kABMultiValueInvalidIdentifier -1

// Type of the contained values
AB_EXTERN ABPropertyType ABMultiValueGetPropertyType(ABMultiValueRef multiValue);

AB_EXTERN CFIndex ABMultiValueGetCount(ABMultiValueRef multiValue);

AB_EXTERN CFTypeRef ABMultiValueCopyValueAtIndex(ABMultiValueRef multiValue, CFIndex index);
AB_EXTERN CFArrayRef ABMultiValueCopyArrayOfAllValues(ABMultiValueRef multiValue);

AB_EXTERN CFStringRef ABMultiValueCopyLabelAtIndex(ABMultiValueRef multiValue, CFIndex index);
    
AB_EXTERN CFIndex ABMultiValueGetIndexForIdentifier(ABMultiValueRef multiValue, ABMultiValueIdentifier identifier);
AB_EXTERN ABMultiValueIdentifier ABMultiValueGetIdentifierAtIndex(ABMultiValueRef multiValue, CFIndex index);
    
AB_EXTERN CFIndex ABMultiValueGetFirstIndexOfValue(ABMultiValueRef multiValue, CFTypeRef value);

// Mutable multivalues

typedef CFTypeRef ABMutableMultiValueRef;

AB_EXTERN ABMutableMultiValueRef ABMultiValueCreateMutable(ABPropertyType type);
AB_EXTERN ABMutableMultiValueRef ABMultiValueCreateMutableCopy(ABMultiValueRef multiValue);
 
AB_EXTERN bool ABMultiValueAddValueAndLabel(ABMutableMultiValueRef multiValue, CFTypeRef value, CFStringRef label, ABMultiValueIdentifier *outIdentifier);
AB_EXTERN bool ABMultiValueInsertValueAndLabelAtIndex(ABMutableMultiValueRef multiValue, CFTypeRef value, CFStringRef label, CFIndex index, ABMultiValueIdentifier *outIdentifier);
AB_EXTERN bool ABMultiValueRemoveValueAndLabelAtIndex(ABMutableMultiValueRef multiValue, CFIndex index);
AB_EXTERN bool ABMultiValueReplaceValueAtIndex(ABMutableMultiValueRef multiValue, CFTypeRef value, CFIndex index);
AB_EXTERN bool ABMultiValueReplaceLabelAtIndex(ABMutableMultiValueRef multiValue, CFStringRef label, CFIndex index);
    
#endif


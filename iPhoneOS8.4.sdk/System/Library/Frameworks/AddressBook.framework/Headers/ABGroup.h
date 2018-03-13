/*
 *  ABGroup.h
 *  AddressBook
 *
 *  Copyright (c) 2010 Apple Inc. All rights reserved.
 *
 *  An ABGroup is a non-ordered collection of records.
 *
 */

#ifndef __ABGroup__
#define __ABGroup__

#include <AddressBook/AddressBookDefines.h>
#include <AddressBook/ABAddressBook.h>
#include <AddressBook/ABRecord.h>
#include <AddressBook/ABPerson.h>
#include <AddressBook/ABSource.h>

AB_EXTERN const int kABGroupNameProperty;

// ABGroupCreate creates a new group in the default source
AB_EXTERN ABRecordRef ABGroupCreate(void);
AB_EXTERN ABRecordRef ABGroupCreateInSource(ABRecordRef source) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

AB_EXTERN ABRecordRef ABGroupCopySource(ABRecordRef group) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

AB_EXTERN CFArrayRef ABGroupCopyArrayOfAllMembers(ABRecordRef group);
AB_EXTERN CFArrayRef ABGroupCopyArrayOfAllMembersWithSortOrdering(ABRecordRef group, ABPersonSortOrdering sortOrdering);
AB_EXTERN bool ABGroupAddMember(ABRecordRef group, ABRecordRef person, CFErrorRef* error);
AB_EXTERN bool ABGroupRemoveMember(ABRecordRef group, ABRecordRef member, CFErrorRef* error);

// Finding groups
AB_EXTERN ABRecordRef ABAddressBookGetGroupWithRecordID(ABAddressBookRef addressBook, ABRecordID recordID);
AB_EXTERN CFIndex ABAddressBookGetGroupCount(ABAddressBookRef addressBook);

AB_EXTERN CFArrayRef ABAddressBookCopyArrayOfAllGroups(ABAddressBookRef addressBook);
AB_EXTERN CFArrayRef ABAddressBookCopyArrayOfAllGroupsInSource(ABAddressBookRef addressBook, ABRecordRef source) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

#endif


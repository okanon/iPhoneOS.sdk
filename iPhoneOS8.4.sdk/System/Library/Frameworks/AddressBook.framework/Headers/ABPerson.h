/*
 *  ABPerson.h
 *  AddressBook
 *
 *  Copyright (c) 2010 Apple Inc. All rights reserved.
 *
 *  An ABPerson corresponds to a contact such as a person or organization.
 *
 */

#ifndef __ABPerson__
#define __ABPerson__

#include <CoreFoundation/CoreFoundation.h>

#include <AddressBook/AddressBookDefines.h>
#include <AddressBook/ABAddressBook.h>
#include <AddressBook/ABRecord.h>
#include <AddressBook/ABSource.h>

#include <Availability.h>

// ABPersonCreate creates a new person in the default source
AB_EXTERN ABRecordRef ABPersonCreate(void);
AB_EXTERN ABRecordRef ABPersonCreateInSource(ABRecordRef source) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

AB_EXTERN ABRecordRef ABPersonCopySource(ABRecordRef person) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

// Returns an array of all the linked people, including the person passed in. If the person is not linked, returns an array with the person passed in.
AB_EXTERN CFArrayRef ABPersonCopyArrayOfAllLinkedPeople(ABRecordRef person) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

AB_EXTERN ABPropertyType ABPersonGetTypeOfProperty(ABPropertyID property);
AB_EXTERN CFStringRef ABPersonCopyLocalizedPropertyName(ABPropertyID property);

typedef uint32_t ABPersonSortOrdering;
enum {
    kABPersonSortByFirstName = 0,
    kABPersonSortByLastName  = 1
};

AB_EXTERN ABPersonSortOrdering ABPersonGetSortOrdering(void);

typedef uint32_t ABPersonCompositeNameFormat;
enum  {
    kABPersonCompositeNameFormatFirstNameFirst = 0,
    kABPersonCompositeNameFormatLastNameFirst  = 1
};

// Composite Names
AB_EXTERN ABPersonCompositeNameFormat ABPersonGetCompositeNameFormat(void) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_NA,__MAC_NA,__IPHONE_2_0,__IPHONE_7_0); // Deprecated. Call ABPersonGetCompositeNameFormatForRecord passing NULL for the record argument instead.
AB_EXTERN ABPersonCompositeNameFormat ABPersonGetCompositeNameFormatForRecord(ABRecordRef record) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0); // The appropriate "First, Last" or "Last, First" order for the contact depending on the detected locale of the contact's name. If the record has no first, middle and last name, or if the record is NULL, then the Contacts Display Order preference is returned.
AB_EXTERN CFStringRef ABPersonCopyCompositeNameDelimiterForRecord(ABRecordRef record) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0); // The delimiter that should be used to separate name components. If the record has no first, middle and last name, or if the record is NULL, then a default delimiter is returned.

// Images
typedef enum {
    kABPersonImageFormatThumbnail = 0,      // the square thumbnail
    kABPersonImageFormatOriginalSize = 2    // the original image as set by ABPersonSetImageData
} ABPersonImageFormat;

AB_EXTERN bool ABPersonSetImageData(ABRecordRef person, CFDataRef imageData, CFErrorRef* error);
AB_EXTERN CFDataRef ABPersonCopyImageData(ABRecordRef person);
AB_EXTERN CFDataRef ABPersonCopyImageDataWithFormat(ABRecordRef person, ABPersonImageFormat format) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_1);

AB_EXTERN bool ABPersonHasImageData(ABRecordRef person);
AB_EXTERN bool ABPersonRemoveImageData(ABRecordRef person, CFErrorRef* error);

// Sorting
AB_EXTERN CFComparisonResult ABPersonComparePeopleByName(ABRecordRef person1, ABRecordRef person2, ABPersonSortOrdering ordering);

// Finding people
AB_EXTERN CFIndex ABAddressBookGetPersonCount(ABAddressBookRef addressBook);
AB_EXTERN ABRecordRef ABAddressBookGetPersonWithRecordID(ABAddressBookRef addressBook, ABRecordID recordID);

AB_EXTERN CFArrayRef ABAddressBookCopyArrayOfAllPeople(ABAddressBookRef addressBook);
AB_EXTERN CFArrayRef ABAddressBookCopyArrayOfAllPeopleInSource(ABAddressBookRef addressBook, ABRecordRef source) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);
AB_EXTERN CFArrayRef ABAddressBookCopyArrayOfAllPeopleInSourceWithSortOrdering(ABAddressBookRef addressBook, ABRecordRef source, ABPersonSortOrdering sortOrdering) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

AB_EXTERN CFArrayRef ABAddressBookCopyPeopleWithName(ABAddressBookRef addressBook, CFStringRef name);

// VCard
    // Creates an array of people from a vcard representation. Source is optional. The people
    // will be created in the source given as the first argument, or the default source if NULL.
AB_EXTERN CFArrayRef ABPersonCreatePeopleInSourceWithVCardRepresentation(ABRecordRef source, CFDataRef vCardData) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
    // Creates a vCard representation of the people passed in.
AB_EXTERN CFDataRef ABPersonCreateVCardRepresentationWithPeople(CFArrayRef people) __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);

// Generic labels
AB_EXTERN const CFStringRef kABWorkLabel;
AB_EXTERN const CFStringRef kABHomeLabel;
AB_EXTERN const CFStringRef kABOtherLabel;

// Property keys
AB_EXTERN const ABPropertyID kABPersonFirstNameProperty;          // First name - kABStringPropertyType
AB_EXTERN const ABPropertyID kABPersonLastNameProperty;           // Last name - kABStringPropertyType
AB_EXTERN const ABPropertyID kABPersonMiddleNameProperty;         // Middle name - kABStringPropertyType
AB_EXTERN const ABPropertyID kABPersonPrefixProperty;             // Prefix ("Sir" "Duke" "General") - kABStringPropertyType
AB_EXTERN const ABPropertyID kABPersonSuffixProperty;             // Suffix ("Jr." "Sr." "III") - kABStringPropertyType
AB_EXTERN const ABPropertyID kABPersonNicknameProperty;           // Nickname - kABStringPropertyType
AB_EXTERN const ABPropertyID kABPersonFirstNamePhoneticProperty;  // First name Phonetic - kABStringPropertyType
AB_EXTERN const ABPropertyID kABPersonLastNamePhoneticProperty;   // Last name Phonetic - kABStringPropertyType
AB_EXTERN const ABPropertyID kABPersonMiddleNamePhoneticProperty; // Middle name Phonetic - kABStringPropertyType
AB_EXTERN const ABPropertyID kABPersonOrganizationProperty;       // Company name - kABStringPropertyType
AB_EXTERN const ABPropertyID kABPersonJobTitleProperty;           // Job Title - kABStringPropertyType
AB_EXTERN const ABPropertyID kABPersonDepartmentProperty;         // Department name - kABStringPropertyType
AB_EXTERN const ABPropertyID kABPersonEmailProperty;              // Email(s) - kABMultiStringPropertyType
AB_EXTERN const ABPropertyID kABPersonBirthdayProperty;           // Birthday associated with this person - kABDateTimePropertyType
AB_EXTERN const ABPropertyID kABPersonNoteProperty;               // Note - kABStringPropertyType
AB_EXTERN const ABPropertyID kABPersonCreationDateProperty;       // Creation Date (when first saved)
AB_EXTERN const ABPropertyID kABPersonModificationDateProperty;   // Last saved date

// Addresses
AB_EXTERN const ABPropertyID kABPersonAddressProperty;            // Street address - kABMultiDictionaryPropertyType
AB_EXTERN const CFStringRef kABPersonAddressStreetKey;
AB_EXTERN const CFStringRef kABPersonAddressCityKey;
AB_EXTERN const CFStringRef kABPersonAddressStateKey;
AB_EXTERN const CFStringRef kABPersonAddressZIPKey;
AB_EXTERN const CFStringRef kABPersonAddressCountryKey;
AB_EXTERN const CFStringRef kABPersonAddressCountryCodeKey;

/*
 * kABPersonAddressCountryCodeKey code must be in the form of 2 character iso 3166 country codes
 *
 * eg:
 *    fr = France
 *    us = United States
 * etc.
 *
 */

// Dates
AB_EXTERN const ABPropertyID kABPersonDateProperty;               // Dates associated with this person - kABMultiDatePropertyType
AB_EXTERN const CFStringRef kABPersonAnniversaryLabel;

// Kind
AB_EXTERN const ABPropertyID kABPersonKindProperty;               // Person/Organization - kABIntegerPropertyType
AB_EXTERN const CFNumberRef kABPersonKindPerson;
AB_EXTERN const CFNumberRef kABPersonKindOrganization;

// Phone numbers
AB_EXTERN const ABPropertyID kABPersonPhoneProperty;              // Generic phone number - kABMultiStringPropertyType
AB_EXTERN const CFStringRef kABPersonPhoneMobileLabel;
AB_EXTERN const CFStringRef kABPersonPhoneIPhoneLabel __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0);
AB_EXTERN const CFStringRef kABPersonPhoneMainLabel;
AB_EXTERN const CFStringRef kABPersonPhoneHomeFAXLabel;
AB_EXTERN const CFStringRef kABPersonPhoneWorkFAXLabel;
AB_EXTERN const CFStringRef kABPersonPhoneOtherFAXLabel __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
AB_EXTERN const CFStringRef kABPersonPhonePagerLabel;

// IM
AB_EXTERN const ABPropertyID kABPersonInstantMessageProperty;     // Instant Messaging - kABMultiDictionaryPropertyType
AB_EXTERN const CFStringRef kABPersonInstantMessageServiceKey;     // Service ("Yahoo", "Jabber", etc.)
AB_EXTERN const CFStringRef kABPersonInstantMessageServiceYahoo;
AB_EXTERN const CFStringRef kABPersonInstantMessageServiceJabber;
AB_EXTERN const CFStringRef kABPersonInstantMessageServiceMSN;
AB_EXTERN const CFStringRef kABPersonInstantMessageServiceICQ;
AB_EXTERN const CFStringRef kABPersonInstantMessageServiceAIM;
AB_EXTERN const CFStringRef kABPersonInstantMessageServiceQQ __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
AB_EXTERN const CFStringRef kABPersonInstantMessageServiceGoogleTalk __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
AB_EXTERN const CFStringRef kABPersonInstantMessageServiceSkype __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
AB_EXTERN const CFStringRef kABPersonInstantMessageServiceFacebook __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
AB_EXTERN const CFStringRef kABPersonInstantMessageServiceGaduGadu __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);

AB_EXTERN const CFStringRef kABPersonInstantMessageUsernameKey;    // Username

// URLs
AB_EXTERN const ABPropertyID kABPersonURLProperty;                // URL - kABMultiStringPropertyType
AB_EXTERN const CFStringRef kABPersonHomePageLabel; // Home Page

// Related names
AB_EXTERN const ABPropertyID kABPersonRelatedNamesProperty;       // Names - kABMultiStringPropertyType
AB_EXTERN const CFStringRef kABPersonFatherLabel;    // Father
AB_EXTERN const CFStringRef kABPersonMotherLabel;    // Mother
AB_EXTERN const CFStringRef kABPersonParentLabel;    // Parent
AB_EXTERN const CFStringRef kABPersonBrotherLabel;   // Brother
AB_EXTERN const CFStringRef kABPersonSisterLabel;    // Sister
AB_EXTERN const CFStringRef kABPersonChildLabel;      // Child
AB_EXTERN const CFStringRef kABPersonFriendLabel;    // Friend
AB_EXTERN const CFStringRef kABPersonSpouseLabel;    // Spouse
AB_EXTERN const CFStringRef kABPersonPartnerLabel;   // Partner
AB_EXTERN const CFStringRef kABPersonAssistantLabel; // Assistant
AB_EXTERN const CFStringRef kABPersonManagerLabel;   // Manager
    
// Social Profile
AB_EXTERN const ABPropertyID kABPersonSocialProfileProperty __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);		// kABMultiDictionaryPropertyType
AB_EXTERN const CFStringRef kABPersonSocialProfileURLKey __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);			// string representation of a url for the social profile
    // the following properties are optional
    AB_EXTERN const CFStringRef kABPersonSocialProfileServiceKey __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);			// string representing the name of the service (Twitter, Facebook, LinkedIn, etc.)
    AB_EXTERN const CFStringRef kABPersonSocialProfileUsernameKey __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);			// string representing the user visible name
    AB_EXTERN const CFStringRef kABPersonSocialProfileUserIdentifierKey __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);	// string representing the service specific identifier (optional)

AB_EXTERN const CFStringRef kABPersonSocialProfileServiceTwitter __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
AB_EXTERN const CFStringRef kABPersonSocialProfileServiceSinaWeibo __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_6_0);
AB_EXTERN const CFStringRef kABPersonSocialProfileServiceGameCenter __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
AB_EXTERN const CFStringRef kABPersonSocialProfileServiceFacebook __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
AB_EXTERN const CFStringRef kABPersonSocialProfileServiceMyspace __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
AB_EXTERN const CFStringRef kABPersonSocialProfileServiceLinkedIn __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);
AB_EXTERN const CFStringRef kABPersonSocialProfileServiceFlickr __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);

// Alternate birthday
AB_EXTERN const ABPropertyID kABPersonAlternateBirthdayProperty __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_8_0);                // kABDictionaryPropertyType
AB_EXTERN const CFStringRef kABPersonAlternateBirthdayCalendarIdentifierKey __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_8_0);    // string representing the calendar identifier for CFCalendarRef
AB_EXTERN const CFStringRef kABPersonAlternateBirthdayEraKey __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_8_0);                   // CFNumberRef - kCFNumberNSIntegerType
AB_EXTERN const CFStringRef kABPersonAlternateBirthdayYearKey __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_8_0);                  // CFNumberRef - kCFNumberNSIntegerType
AB_EXTERN const CFStringRef kABPersonAlternateBirthdayMonthKey __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_8_0);                 // CFNumberRef - kCFNumberNSIntegerType
AB_EXTERN const CFStringRef kABPersonAlternateBirthdayIsLeapMonthKey __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_8_0);           // CFNumberRef - kCFNumberCharType (aka NSNumber Bool type)
AB_EXTERN const CFStringRef kABPersonAlternateBirthdayDayKey __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_8_0);                   // CFNumberRef - kCFNumberNSIntegerType

#endif

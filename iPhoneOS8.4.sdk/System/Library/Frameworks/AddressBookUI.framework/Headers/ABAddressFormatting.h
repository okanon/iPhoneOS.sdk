//
//  ABAddressFormatting.h
//  AddressBookUI
//
//  Copyright (c) 2010 Apple Inc. All rights reserved.
//

#import <AddressBook/AddressBook.h>

#if defined(__cplusplus)
extern "C" {
#endif    

    // address: an address dictionary obtained representing the address (kABPersonAddressProperty) of a person (ABRecordRef)
    // addCountryName: whether to always include the country name in the address string, regardless of whether it is specified
    //                 in the dictionary. If not specified by the user a localized country name will be added.
    // returns a formatted multi line string that contains the full address. The string is likely to contain line endings.
NSString *ABCreateStringWithAddressDictionary(NSDictionary *address, BOOL addCountryName) NS_RETURNS_RETAINED;

#if defined(__cplusplus)
}
#endif

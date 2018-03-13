
#import <Foundation/Foundation.h>
#import <PassKit/PKPass.h>

/* Threading contract: no concurrent usage.
 */

typedef NS_ENUM(NSInteger, PKPassLibraryAddPassesStatus) {
    PKPassLibraryDidAddPasses,
    PKPassLibraryShouldReviewPasses,
    PKPassLibraryDidCancelAddPasses,
} NS_ENUM_AVAILABLE_IOS(7_0);


NS_CLASS_AVAILABLE_IOS(6_0)
@interface PKPassLibrary : NSObject

/* The library is not available on iPad in 6.0.
 */
+ (BOOL)isPassLibraryAvailable;

/* These return only passes the process is entitled to access.
 */
- (NSArray *)passes;
- (PKPass *)passWithPassTypeIdentifier:(NSString *)identifier serialNumber:(NSString *)serialNumber;
- (NSArray *)passesOfType:(PKPassType)passType NS_AVAILABLE_IOS(8_0);
- (void)removePass:(PKPass *)pass;

/* This returns YES even if the process is not entitled to access the pass in the library.
 An app like Mail is not entitled to get pass from the library, but it should avoid presenting UI for adding an email attachment pass that is already in the library.
 */ 
- (BOOL)containsPass:(PKPass *)pass;

/* This will fail if a pass with matching identifier and serial number is not already present in the library, or if the process is not entitled to access the pass.
 To add a completely new pass, use PKAddPassesViewController.
 */
- (BOOL)replacePassWithPass:(PKPass *)pass;

/* The user will be prompted to grant permission for the calling process to add passes to the Pass Library. The user may respond by allowing the passes to be added, or requesting to review the passes. The selection will be returned in the completionHandler as a PKPassLibraryAddPassesStatus. If PKPassLibraryPassesPresentReview is returned, you must present a PKPAddPassesViewController initialized with the passes so that the user may review and add the passes manually. The completion handler for this method is called on an arbitrary queue - dispatch to the main queue if you're presenting UI.
 */
- (void)addPasses:(NSArray *)passes withCompletionHandler:(void(^)(PKPassLibraryAddPassesStatus status))completion NS_AVAILABLE_IOS(7_0);

/* If device supports adding payment passes, this method will return YES. Otherwise, NO will be returned.
 */
+ (BOOL)isPaymentPassActivationAvailable NS_AVAILABLE_IOS(8_0);

/*
 * Opens the card setup flow (in Passbook on iPhone, Settings on iPad).
 * Use this to direct a user to card setup directly from your app
 */
- (void)openPaymentSetup NS_AVAILABLE_IOS(8_3);

/* These methods may be utilized to activate a payment pass that is provisioned but currently in the inactive state, by providing either a cryptographic OTP, or an activation code.
 */
- (void)activatePaymentPass:(PKPaymentPass *)paymentPass withActivationData:(NSData *)activationData completion:(void(^)(BOOL success, NSError* error))completion NS_AVAILABLE_IOS(8_0);
- (void)activatePaymentPass:(PKPaymentPass *)paymentPass withActivationCode:(NSString *)activationCode completion:(void(^)(BOOL success, NSError* error))completion NS_AVAILABLE_IOS(8_0);

@end

/* This notification is issued by a library instance, with that instance as the sender.  If there are no instantiated library objects, no notifications.
 There are no guarantees about what thread or queue these come in on.
 */
extern NSString *const PKPassLibraryDidChangeNotification NS_AVAILABLE_IOS(6_0);

/* Entries in user info dictionary for PKPassLibraryDidChangeNotification.

 PKPassLibraryAddedPassesUserInfoKey is the key for an array of passes
 PKPassLibraryReplacementPassesUserInfoKey is the key for an array of passes
 PKPassLibraryRemovedPassInfosUserInfoKey is the key for an array of dictionaries, each of which has keys PKPassLibraryPassTypeIdentifierUserInfoKey and PKPassLibrarySerialNumberUserInfoKey mapping to strings.
  */
extern NSString *const PKPassLibraryAddedPassesUserInfoKey NS_AVAILABLE_IOS(6_0);
extern NSString *const PKPassLibraryReplacementPassesUserInfoKey NS_AVAILABLE_IOS(6_0);
extern NSString *const PKPassLibraryRemovedPassInfosUserInfoKey NS_AVAILABLE_IOS(6_0);

extern NSString *const PKPassLibraryPassTypeIdentifierUserInfoKey NS_AVAILABLE_IOS(6_0);
extern NSString *const PKPassLibrarySerialNumberUserInfoKey NS_AVAILABLE_IOS(6_0);

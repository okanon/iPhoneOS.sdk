
/*!
 @header     MFMessageComposeViewController
 @abstract   The MFMessageComposeViewController class provides an interface for editing and sending a text
			 message.
 @discussion MFMessageComposeViewController is used for implementing a simple interface for users to enter
			 and send a text message including multimedia attachments.
 @copyright  Copyright 2009 - 2012 Apple Inc. All rights reserved.
 */
#import <UIKit/UIKit.h>

/*!
 @enum       MessageComposeResult
 @abstract   Composition result sent to the delegate upon user completion.
 @discussion This result will inform the client of the user's message composition action.  If the
			 user cancels the composition, <tt>MessageComposeResultCancelled</tt> will be sent to the delegate.
			 Typically <tt>MessageComposeResultSent</tt> will be sent, but <tt>MessageComposeResultFailed</tt> will
			 be sent in the case of failure. </p>Send may only be interpreted as a successful queueing of
			 the message for later sending. The actual send will occur when the device is able to send.
 @constant   MessageComposeResultCancelled   User canceled the composition.
 @constant   MessageComposeResultSent        User successfully sent/queued the message.
 @constant   MessageComposeResultFailed      User's attempt to save or send was unsuccessful.
 */

enum MessageComposeResult {
    MessageComposeResultCancelled,
    MessageComposeResultSent,
    MessageComposeResultFailed
};
typedef enum MessageComposeResult MessageComposeResult;   // available in iPhone 4.0

/*!
 @constant  MFMessageComposeViewControllerAttachmentURL   The url for the given attachment.
*/
extern NSString *const MFMessageComposeViewControllerAttachmentURL;

/*!
 @constant  MFMessageComposeViewControllerAttachmentAlternateFilename   The alternate filename for the given attachment.
 */
extern NSString *const MFMessageComposeViewControllerAttachmentAlternateFilename;

/*!
 @const      MFMessageComposeViewControllerTextMessageAvailabilityDidChangeNotification
 @abstract   Notification posted when the value of <tt>+[MFMessageComposeViewController canSendText]</tt> has changed.
 @discussion This notification is posted when the value of <tt>+[MFMessageComposeViewController canSendText]</tt>
             has changed. Clients should invalidate any caches and update UI as appropriate.
*/
extern NSString *const MFMessageComposeViewControllerTextMessageAvailabilityDidChangeNotification __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);

/*!
 @const      MFMessageComposeViewControllerTextMessageAvailabilityKey
 @abstract   UserInfo key for MFMessageComposeViewControllerTextMessageAvailabilityDidChangeNotification
             containing the value of <tt>+[MFMessageComposeViewController canSendText]</tt>
 @discussion The value of this key is an NSNumber containing a BOOL value. This value matches
             the result of <tt>+[MFMessageComposeViewController canSendText]</tt>.
*/
extern NSString *const MFMessageComposeViewControllerTextMessageAvailabilityKey __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_5_0);

@protocol MFMessageComposeViewControllerDelegate;

/*!
 @class       MFMessageComposeViewController
 @abstract    The MFMessageComposeViewController class provides an interface for editing and sending a message.
 @discussion  The MFMessageComposeViewController class manages all user interaction.  The client needs to set
			  the recipient or recipients.  The client may also set the body of the message. After setup, the
			  client needs to only display the view.
			  </p>The provided delegate will be informed of the user's composition completion and how they chose
			  to complete the operation.
			  <p>Prior to use, clients should verify the user has set up the device for sending messages via
			  <tt>+[MFMessageComposeViewController canSendText]</tt>.
 */
NS_CLASS_AVAILABLE(NA, 4_0)
@interface MFMessageComposeViewController : UINavigationController {
}

/*!
 @method     canSendText
 @abstract   Returns <tt>YES</tt> if the user has set up the device for sending text only messages.
 @discussion If the return value is YES, the client can set the recipients and body of the message.
			 If the return value is NO, the client may notify the user of the failure, or the
			 client may open an SMS URL via <tt>-[UIApplication openURL:]</tt>.
 */
+ (BOOL)canSendText  __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

/*!
 @method     canSendSubject
 @abstract   Returns <tt>YES</tt> if the user has set up the device for including subjects in messages.</tt>.
 */
+ (BOOL)canSendSubject __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0);

/*!
 @method     canSendAttachments
 @abstract   Returns <tt>YES</tt> if the user has set up the device for including attachments in messages.</tt>.
 */
+ (BOOL)canSendAttachments __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0);

/*!
 @method     isSupportedAttachmentUTI:
 @abstract   Returns <tt>YES</tt>if the attachment at the specified URL could be accepted by the current composition.
 @discussion If the return value is YES, the UTI is acceptable for attachment to a message, a return value of NO
 indicates that the given UTI is unsupported.
 */
+ (BOOL)isSupportedAttachmentUTI:(NSString *)uti __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0);

/*!
 @property   messageComposeDelegate
 @abstract   This property is the delegate for the MFMessageComposeViewController method callbacks.
 */
@property(nonatomic,assign) id<MFMessageComposeViewControllerDelegate> messageComposeDelegate /*__OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0)*/;

/*!
 @method     disableUserAttachments;
 @abstract   Calling this method will disable the camera/attachment button in the view controller.  After the controller has been presented,
             this call will have no effect.  The camera / attachment button is visible by default.
 */
- (void)disableUserAttachments __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0);

/*!
 @property   recipients
 @abstract   This property sets the initial value of the To field for the message to the specified addresses.
 @discussion This property will set the initial value of the To field for the message from an NSArray of
			 NSString instances specifying the message addresses of recipients. This should be called prior
			 to display.
			 </p>After the view has been presented to the user, this property will no longer change the value.
 */
@property(nonatomic,copy) NSArray *recipients /*__OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0)*/;

/*!
 @property   body
 @abstract   This property sets the initial value of the body of the message to the specified content.
 @discussion This property will set the initial value of the body of the message.  This should be called prior
			 to display.
			 </p>After the view has been presented to the user, this property will no longer change the value.
 */
@property(nonatomic,copy) NSString *body /*__OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0)*/;

/*!
 @property   subject
 @abstract   This property sets the initial value of the subject of the message to the specified content.
 @discussion This property will set the initial value of the subject of the message.  This should be called prior
 to display.
 </p>After the view has been presented to the user, this property will no longer change the value.
 */
@property(nonatomic,copy) NSString *subject /*__OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0)*/;

/*!
 @property   attachments
 @abstract   This property returns an NSArray of NSDictionaries describing the properties of the current attachments.
 @discussion This property returns an NSArray of NSDictionaries describing the properties of the current attachments.
             See MFMessageComposeViewControllerAttachmentURL, MFMessageComposeViewControllerAttachmentAlternateFilename.
 */
@property(nonatomic,copy, readonly) NSArray *attachments /*__OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0)*/;

/*!
 @method     addAttachmentURL:withAlternateFilename:
 @abstract   Returns <tt>YES</tt>if the attachment at the specified URL was added to the composition successfully.
 @discussion If the return value is YES, the attachment was added to the composition. If the return value is NO,
             the attachment was not added to the composition.  All attachment URLs must be file urls.  The file
             URL must not be NIL.  The alternate filename will be display to the user in leiu of the attachments URL.
             The alternate filename may be NIL.
 */
- (BOOL)addAttachmentURL:(NSURL *)attachmentURL withAlternateFilename:(NSString *)alternateFilename __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0);

/*!
 @method     addAttachmentData:typeIdentifier:filename:
 @abstract   Returns <tt>YES</tt>if the attachment was added to the composition successfully.
 @discussion If the return value is YES, the attachment was added to the composition. If the return value is NO,
 the attachment was not added to the composition.  The data and typeIdentifer must be non-nil.  typeIdentifier should be a valid Uniform Type Identifier.
 */
- (BOOL)addAttachmentData:(NSData *)attachmentData typeIdentifier:(NSString *)uti filename:(NSString *)filename __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0);

@end


/*!
 @protocol    MFMessageComposeViewControllerDelegate
 @abstract    Protocol for delegate callbacks to MFMessageComposeViewControllerDelegate instances.
 @discussion  This protocol will be implemented by delegates of MFMessageComposeViewController instances.
			  It will be called at various times while the user is composing, sending, or canceling
			  message composition.
 */
@protocol MFMessageComposeViewControllerDelegate <NSObject>
@required
/*!
 @method     messageComposeViewController:didFinishWithResult:
 @abstract   Delegate callback which is called upon user's completion of message composition.
 @discussion This delegate callback will be called when the user completes the message composition.
			 How the user chose to complete this task will be given as one of the parameters to the
			 callback.  Upon this call, the client should remove the view associated with the controller,
			 typically by dismissing modally.
 @param      controller   The MFMessageComposeViewController instance which is returning the result.
 @param      result       MessageComposeResult indicating how the user chose to complete the composition process.
 */
- (void)messageComposeViewController:(MFMessageComposeViewController *)controller didFinishWithResult:(MessageComposeResult)result;

@end

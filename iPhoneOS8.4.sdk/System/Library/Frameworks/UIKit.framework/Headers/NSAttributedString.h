//
//  NSAttributedString.h
//  UIKit
//
//  Copyright (c) 2011-2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

/************************ Attributes ************************/

/* Predefined character attributes for text. If the key is not in the dictionary, then use the default values as described below.
 */
UIKIT_EXTERN NSString *const NSFontAttributeName NS_AVAILABLE_IOS(6_0);                // UIFont, default Helvetica(Neue) 12
UIKIT_EXTERN NSString *const NSParagraphStyleAttributeName NS_AVAILABLE_IOS(6_0);      // NSParagraphStyle, default defaultParagraphStyle
UIKIT_EXTERN NSString *const NSForegroundColorAttributeName NS_AVAILABLE_IOS(6_0);     // UIColor, default blackColor
UIKIT_EXTERN NSString *const NSBackgroundColorAttributeName NS_AVAILABLE_IOS(6_0);     // UIColor, default nil: no background
UIKIT_EXTERN NSString *const NSLigatureAttributeName NS_AVAILABLE_IOS(6_0);            // NSNumber containing integer, default 1: default ligatures, 0: no ligatures
UIKIT_EXTERN NSString *const NSKernAttributeName NS_AVAILABLE_IOS(6_0);                // NSNumber containing floating point value, in points; amount to modify default kerning. 0 means kerning is disabled.
UIKIT_EXTERN NSString *const NSStrikethroughStyleAttributeName NS_AVAILABLE_IOS(6_0);  // NSNumber containing integer, default 0: no strikethrough
UIKIT_EXTERN NSString *const NSUnderlineStyleAttributeName NS_AVAILABLE_IOS(6_0);      // NSNumber containing integer, default 0: no underline
UIKIT_EXTERN NSString *const NSStrokeColorAttributeName NS_AVAILABLE_IOS(6_0);         // UIColor, default nil: same as foreground color
UIKIT_EXTERN NSString *const NSStrokeWidthAttributeName NS_AVAILABLE_IOS(6_0);         // NSNumber containing floating point value, in percent of font point size, default 0: no stroke; positive for stroke alone, negative for stroke and fill (a typical value for outlined text would be 3.0)
UIKIT_EXTERN NSString *const NSShadowAttributeName NS_AVAILABLE_IOS(6_0);              // NSShadow, default nil: no shadow
UIKIT_EXTERN NSString *const NSTextEffectAttributeName NS_AVAILABLE_IOS(7_0);          // NSString, default nil: no text effect

UIKIT_EXTERN NSString *const NSAttachmentAttributeName NS_AVAILABLE_IOS(7_0);          // NSTextAttachment, default nil
UIKIT_EXTERN NSString *const NSLinkAttributeName NS_AVAILABLE_IOS(7_0);                // NSURL (preferred) or NSString
UIKIT_EXTERN NSString *const NSBaselineOffsetAttributeName NS_AVAILABLE_IOS(7_0);      // NSNumber containing floating point value, in points; offset from baseline, default 0
UIKIT_EXTERN NSString *const NSUnderlineColorAttributeName NS_AVAILABLE_IOS(7_0);      // UIColor, default nil: same as foreground color
UIKIT_EXTERN NSString *const NSStrikethroughColorAttributeName NS_AVAILABLE_IOS(7_0);  // UIColor, default nil: same as foreground color
UIKIT_EXTERN NSString *const NSObliquenessAttributeName NS_AVAILABLE_IOS(7_0);         // NSNumber containing floating point value; skew to be applied to glyphs, default 0: no skew
UIKIT_EXTERN NSString *const NSExpansionAttributeName NS_AVAILABLE_IOS(7_0);           // NSNumber containing floating point value; log of expansion factor to be applied to glyphs, default 0: no expansion

UIKIT_EXTERN NSString *const NSWritingDirectionAttributeName NS_AVAILABLE_IOS(7_0);    // NSArray of NSNumbers representing the nested levels of writing direction overrides as defined by Unicode LRE, RLE, LRO, and RLO characters.  The control characters can be obtained by masking NSWritingDirection and NSTextWritingDirection values.  LRE: NSWritingDirectionLeftToRight|NSTextWritingDirectionEmbedding, RLE: NSWritingDirectionRightToLeft|NSTextWritingDirectionEmbedding, LRO: NSWritingDirectionLeftToRight|NSTextWritingDirectionOverride, RLO: NSWritingDirectionRightToLeft|NSTextWritingDirectionOverride,

UIKIT_EXTERN NSString *const NSVerticalGlyphFormAttributeName NS_AVAILABLE_IOS(6_0);   // An NSNumber containing an integer value.  0 means horizontal text.  1 indicates vertical text.  If not specified, it could follow higher-level vertical orientation settings.  Currently on iOS, it's always horizontal.  The behavior for any other value is undefined.

/* This defines currently supported values for NSUnderlineStyleAttributeName and NSStrikethroughStyleAttributeName.
 */
typedef NS_ENUM(NSInteger, NSUnderlineStyle) {
    NSUnderlineStyleNone                                = 0x00,
    NSUnderlineStyleSingle                              = 0x01,
    NSUnderlineStyleThick NS_ENUM_AVAILABLE_IOS(7_0)    = 0x02,
    NSUnderlineStyleDouble NS_ENUM_AVAILABLE_IOS(7_0)   = 0x09,

    NSUnderlinePatternSolid NS_ENUM_AVAILABLE_IOS(7_0)      = 0x0000,
    NSUnderlinePatternDot NS_ENUM_AVAILABLE_IOS(7_0)        = 0x0100,
    NSUnderlinePatternDash NS_ENUM_AVAILABLE_IOS(7_0)       = 0x0200,
    NSUnderlinePatternDashDot NS_ENUM_AVAILABLE_IOS(7_0)    = 0x0300,
    NSUnderlinePatternDashDotDot NS_ENUM_AVAILABLE_IOS(7_0) = 0x0400,

    NSUnderlineByWord NS_ENUM_AVAILABLE_IOS(7_0) = 0x8000
} NS_ENUM_AVAILABLE_IOS(6_0);

/* NSTextWritingDirection values used by NSWritingDirectionAttributeName. Can specify the formatting controls defined by Unicode Bidirectional Algorithm.
 */
typedef NS_ENUM(NSInteger, NSTextWritingDirection) {
    NSTextWritingDirectionEmbedding     = (0 << 1),
    NSTextWritingDirectionOverride      = (1 << 1)
} NS_ENUM_AVAILABLE_IOS(7_0);

/* This defines the currently supported value for NSTextEffectAttributeName as of iOS 7.0
 */
UIKIT_EXTERN NSString *const NSTextEffectLetterpressStyle NS_AVAILABLE_IOS(7_0);

/************************ Attribute fixing ************************/

@interface NSMutableAttributedString (NSMutableAttributedStringKitAdditions)
// This method fixes attribute inconsistencies inside range.  It ensures NSFontAttributeName covers the characters, NSParagraphStyleAttributeName is only changing at paragraph boundaries, and NSTextAttachmentAttributeName is assigned to NSTextAttachmentCharacter.  NSTextStorage automatically invokes this method via -ensureAttributesAreFixedInRange:.
- (void)fixAttributesInRange:(NSRange)range NS_AVAILABLE_IOS(7_0);

@end


/************************ Document formats ************************/

// Supported document types for the NSDocumentTypeDocumentAttribute key in the document attributes dictionary.
UIKIT_EXTERN NSString *const NSPlainTextDocumentType NS_AVAILABLE_IOS(7_0);
UIKIT_EXTERN NSString *const NSRTFTextDocumentType NS_AVAILABLE_IOS(7_0);
UIKIT_EXTERN NSString *const NSRTFDTextDocumentType NS_AVAILABLE_IOS(7_0);
UIKIT_EXTERN NSString *const NSHTMLTextDocumentType NS_AVAILABLE_IOS(7_0);


// Keys for NSLayoutOrientationSectionsAttribute.
UIKIT_EXTERN NSString *const NSTextLayoutSectionOrientation NS_AVAILABLE_IOS(7_0); // NSNumber containing NSTextLayoutOrientation value. default: NSTextLayoutOrientationHorizontal
UIKIT_EXTERN NSString *const NSTextLayoutSectionRange NS_AVAILABLE_IOS(7_0); // NSValue containing NSRange representing a character range. default: a range covering the whole document


// Keys for options and document attributes dictionaries.  They are in and out document properties used by both read/write methods.

UIKIT_EXTERN NSString *const NSDocumentTypeDocumentAttribute NS_AVAILABLE_IOS(7_0);  // @"DocumentType", one of the document types declared above.  For reader methods, this key in options can specify the document type for interpreting the contents.  Upon return, the document attributes can contain this key for indicating the actual format used to read the contents.  For write methods, this key specifies the format for generating the data.


// NSPlainTextDocumentType document attributes
UIKIT_EXTERN NSString *const NSCharacterEncodingDocumentAttribute NS_AVAILABLE_IOS(7_0);  // @"CharacterEncoding", NSNumber containing integer specifying NSStringEncoding for the file; default for plain text is the default encoding.  This key in options can specify the string encoding for reading the data.  Upon return, the document attributes can contain the actual encoding used.  For writing methods, this value is used for generating the plain text data.
UIKIT_EXTERN NSString *const NSDefaultAttributesDocumentAttribute NS_AVAILABLE_IOS(7_0);  // @"DefaultAttributes", NSDictionary containing attributes to be applied to plain files.  Used by reader methods.  This key in options can specify the default attributes applied to the entire document contents.  The document attributes can contain this key indicating the actual attributes used.


// NSRTFTextDocumentType and NSRTFDTextDocumentType document attributes
// Document dimension
// They are document attributes used by read/write methods.
UIKIT_EXTERN NSString *const NSPaperSizeDocumentAttribute NS_AVAILABLE_IOS(7_0);  // @"PaperSize", NSValue containing CGSize (in points)
UIKIT_EXTERN NSString *const NSPaperMarginDocumentAttribute NS_AVAILABLE_IOS(7_0);  // @"PaperMargin", NSValue containing UIEdgeInsets

UIKIT_EXTERN NSString *const NSViewSizeDocumentAttribute NS_AVAILABLE_IOS(7_0);  // @"ViewSize", NSValue containing CGSize (in points)
UIKIT_EXTERN NSString *const NSViewZoomDocumentAttribute NS_AVAILABLE_IOS(7_0);  // @"ViewZoom", NSNumber containing floating point value (100 == 100% zoom)
UIKIT_EXTERN NSString *const NSViewModeDocumentAttribute NS_AVAILABLE_IOS(7_0);  // @"ViewMode", NSNumber containing integer; 0 = normal; 1 = page layout

// Document settings
// They are document attributes used by read/write methods.
UIKIT_EXTERN NSString *const NSReadOnlyDocumentAttribute NS_AVAILABLE_IOS(7_0);  // @"ReadOnly", NSNumber containing integer; if missing, or 0 or negative, not readonly; 1 or more, readonly. Note that this has nothing to do with the file system protection on the file, but instead, on how the file should be displayed to the user
UIKIT_EXTERN NSString *const NSBackgroundColorDocumentAttribute NS_AVAILABLE_IOS(7_0);  // @"BackgroundColor", UIColor, representing the document-wide page background color
UIKIT_EXTERN NSString *const NSHyphenationFactorDocumentAttribute NS_AVAILABLE_IOS(7_0);  // @"HyphenationFactor", NSNumber containing floating point value (0=off, 1=full hyphenation)
UIKIT_EXTERN NSString *const NSDefaultTabIntervalDocumentAttribute NS_AVAILABLE_IOS(7_0);  // @"DefaultTabInterval", NSNumber containing floating point value, representing the document-wide default tab stop interval, in points
UIKIT_EXTERN NSString *const NSTextLayoutSectionsAttribute NS_AVAILABLE_IOS(7_0);  // NSArray of dictionaries.  Each dictionary describing a layout orientation section.  The dictionary can have two attributes: NSTextLayoutSectionOrientation and NSTextLayoutSectionRange.  When there is a gap between sections, it's assumed to have NSTextLayoutOrientationHorizontal.


@interface NSAttributedString (NSAttributedStringDocumentFormats)
// Methods initializing the receiver contents with an external document data.  options specify document attributes for interpreting the document contents.  NSDocumentTypeDocumentAttribute, NSCharacterEncodingDocumentAttribute, and NSDefaultAttributesDocumentAttribute are supported options key.  When they are not specified, these methods will examine the data and do their best to detect the appropriate attributes.  If dict is non-NULL, it will return a dictionary with various document-wide attributes accessible via NS...DocumentAttribute keys.
- (instancetype)initWithFileURL:(NSURL *)url options:(NSDictionary *)options documentAttributes:(NSDictionary **)dict error:(NSError **)error NS_AVAILABLE_IOS(7_0);
- (instancetype)initWithData:(NSData *)data options:(NSDictionary *)options documentAttributes:(NSDictionary **)dict error:(NSError **)error NS_AVAILABLE_IOS(7_0);

// Generates an NSData object for the receiver contents in range.  It requires a document attributes dict specifying at least the NSDocumentTypeDocumentAttribute to determine the format to be written.
- (NSData *)dataFromRange:(NSRange)range documentAttributes:(NSDictionary *)dict error:(NSError **)error NS_AVAILABLE_IOS(7_0);

// Returns an NSFileWrapper object for the receiver contents in range.  It requires a document attributes dict specifying at least the NSDocumentTypeDocumentAttribute to determine the format to be written.  The method returns a directory file wrapper for those document types represented by a file package such as NSRTFDTextDocumentType; otherwise, it returns a regular-file file wrapper.
- (NSFileWrapper *)fileWrapperFromRange:(NSRange)range documentAttributes:(NSDictionary *)dict error:(NSError **)error NS_AVAILABLE_IOS(7_0);

@end

@interface NSMutableAttributedString (NSMutableAttributedStringDocumentFormats)
// Methods replacing the receiver contents with an external document data.  options specify document attributes for interpreting the document contents.  NSDocumentTypeDocumentAttribute, NSCharacterEncodingDocumentAttribute, and NSDefaultAttributesDocumentAttribute are supported options key.  When they are not specified, these methods will examine the data and do their best to detect the appropriate attributes.  If dict is non-NULL, it will return a dictionary with various document-wide attributes accessible via NS...DocumentAttribute keys.
- (BOOL)readFromFileURL:(NSURL *)url options:(NSDictionary *)opts documentAttributes:(NSDictionary **)dict error:(NSError **)error NS_AVAILABLE_IOS(7_0);
- (BOOL)readFromData:(NSData *)data options:(NSDictionary *)opts documentAttributes:(NSDictionary **)dict error:(NSError **)error NS_AVAILABLE_IOS(7_0);
@end



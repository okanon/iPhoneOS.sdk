//
//  UIInputViewController.h
//  UIKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UIKit/UIInputView.h>
#import <UIKit/UITextInput.h>

@class UILexicon;

@protocol UITextDocumentProxy <UIKeyInput>

@property (nonatomic, readonly) NSString *documentContextBeforeInput;
@property (nonatomic, readonly) NSString *documentContextAfterInput;

- (void)adjustTextPositionByCharacterOffset:(NSInteger)offset;

@end

NS_CLASS_AVAILABLE_IOS(8_0) @interface UIInputViewController : UIViewController <UITextInputDelegate>

@property (nonatomic, retain) UIInputView *inputView;

@property (nonatomic, readonly) NSObject <UITextDocumentProxy> *textDocumentProxy;

// The primary language of the UIInputViewController.  A BCP 47 language identifier such as en-US
// If specified, this will supersede any PrimaryLanguage in the Info.plist.
@property (nonatomic, copy) NSString *primaryLanguage;

- (void)dismissKeyboard;
- (void)advanceToNextInputMode;

// This will not provide a complete repository of a language's vocabulary.
// It is solely intended to supplement existing lexicons.
- (void)requestSupplementaryLexiconWithCompletion:(void (^)(UILexicon *))completionHandler;

@end

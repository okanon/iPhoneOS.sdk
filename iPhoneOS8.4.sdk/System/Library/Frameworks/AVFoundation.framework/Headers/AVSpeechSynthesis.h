/*
 File:  AVSpeechSynthesis.h
 
 Framework:  AVFoundation
 
 Copyright 2013 Apple Inc. All rights reserved.
 */

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, AVSpeechBoundary) {
    AVSpeechBoundaryImmediate,
    AVSpeechBoundaryWord
} NS_ENUM_AVAILABLE_IOS(7_0);

AVF_EXPORT const float AVSpeechUtteranceMinimumSpeechRate;
AVF_EXPORT const float AVSpeechUtteranceMaximumSpeechRate;
AVF_EXPORT const float AVSpeechUtteranceDefaultSpeechRate;

@protocol AVSpeechSynthesizerDelegate;

/*!
 @class AVSpeechSynthesisVoice
 @abstract
 AVSpeechSynthesisVoice encapsulates the attributes of the voice used to synthesize speech on the system.
 
 @discussion
 Retrieve a voice by specifying the language code your text should be spoken in.
 */
NS_CLASS_AVAILABLE_IOS(7_0)
@interface AVSpeechSynthesisVoice : NSObject<NSSecureCoding>

+ (NSArray *)speechVoices;
+ (NSString *)currentLanguageCode;

/*!
 @method        voiceWithLanguage:
 @abstract      Use a BCP-47 language tag to specify the desired language and region.
 @param			language
 Specifies the BCP-47 language tag that represents the voice.
 @discussion
 The default is the system's region and language.
 Passing in nil will return the default synthesizer.
 Passing in an invalid languageCode will return nil.
 Examples: en-US (U.S. English), fr-CA (French Canadian)
 */
+ (AVSpeechSynthesisVoice *)voiceWithLanguage:(NSString *)language;

@property(nonatomic, readonly) NSString *language;

@end

/*!
 @class AVSpeechUtterance
 @abstract
 AVSpeechUtterance is the atom of speaking a string or pausing the synthesizer.
 
 @discussion
 To start speaking, specify the AVSpeechSynthesisVoice and the string to be spoken, then optionally change the rate, pitch or volume if desired.
 */
NS_CLASS_AVAILABLE_IOS(7_0)
@interface AVSpeechUtterance : NSObject<NSCopying, NSSecureCoding>

+ (instancetype)speechUtteranceWithString:(NSString *)string;

- (instancetype)initWithString:(NSString *)string;

/* If no voice is specified, the system's default will be used. */
@property(nonatomic, retain) AVSpeechSynthesisVoice *voice;

@property(nonatomic, readonly) NSString *speechString;

/* Setting these values after a speech utterance has been enqueued will have no effect. */

@property(nonatomic) float rate;             // Values are pinned between AVSpeechUtteranceMinimumSpeechRate and AVSpeechUtteranceMaximumSpeechRate.
@property(nonatomic) float pitchMultiplier;  // [0.5 - 2] Default = 1
@property(nonatomic) float volume;           // [0-1] Default = 1

@property(nonatomic) NSTimeInterval preUtteranceDelay;    // Default is 0.0
@property(nonatomic) NSTimeInterval postUtteranceDelay;   // Default is 0.0


@end

/*!
 @class AVSpeechSynthesizer
 @abstract
 AVSpeechSynthesizer allows speaking of speech utterances with a basic queuing mechanism.
 
 @discussion
 Create an instance of AVSpeechSynthesizer to start generating synthesized speech by using AVSpeechUtterance objects.
 */
NS_CLASS_AVAILABLE_IOS(7_0)
@interface AVSpeechSynthesizer : NSObject

@property(nonatomic, assign) id<AVSpeechSynthesizerDelegate> delegate;

@property(nonatomic, readonly, getter=isSpeaking) BOOL speaking;
@property(nonatomic, readonly, getter=isPaused) BOOL paused;

/* AVSpeechUtterances are queued by default. If an AVSpeechUtterance is already enqueued or is speaking, this method will raise an exception. */
- (void)speakUtterance:(AVSpeechUtterance *)utterance;

/* These methods will operate on the speech utterance that is speaking. Returns YES if it succeeds, NO for failure. */

/* Call stopSpeakingAtBoundary: to interrupt current speech and clear the queue. */
- (BOOL)stopSpeakingAtBoundary:(AVSpeechBoundary)boundary;
- (BOOL)pauseSpeakingAtBoundary:(AVSpeechBoundary)boundary;
- (BOOL)continueSpeaking;

@end

/*!
 @protocol AVSpeechSynthesizerDelegate
 @abstract
 Defines an interface for delegates of AVSpeechSynthesizer to receive notifications of important speech utterance events.
 */
@protocol AVSpeechSynthesizerDelegate <NSObject>

@optional
- (void)speechSynthesizer:(AVSpeechSynthesizer *)synthesizer didStartSpeechUtterance:(AVSpeechUtterance *)utterance;
- (void)speechSynthesizer:(AVSpeechSynthesizer *)synthesizer didFinishSpeechUtterance:(AVSpeechUtterance *)utterance;
- (void)speechSynthesizer:(AVSpeechSynthesizer *)synthesizer didPauseSpeechUtterance:(AVSpeechUtterance *)utterance;
- (void)speechSynthesizer:(AVSpeechSynthesizer *)synthesizer didContinueSpeechUtterance:(AVSpeechUtterance *)utterance;
- (void)speechSynthesizer:(AVSpeechSynthesizer *)synthesizer didCancelSpeechUtterance:(AVSpeechUtterance *)utterance;

- (void)speechSynthesizer:(AVSpeechSynthesizer *)synthesizer willSpeakRangeOfSpeechString:(NSRange)characterRange utterance:(AVSpeechUtterance *)utterance;
@end

/*
    NSPersistentHistoryChangeRequest.h
    Core Data
    Copyright (c) 2014-2017, Apple Inc.
    All rights reserved.
*/

#import <Foundation/NSArray.h>
#import <Foundation/NSDate.h>
#import <CoreData/NSPersistentStoreRequest.h>
#import <CoreData/NSPersistentStoreResult.h>

NS_ASSUME_NONNULL_BEGIN

@class NSPersistentHistoryTransaction;
@class NSPersistentHistoryToken;

API_AVAILABLE(macosx(10.13),ios(11.0),tvos(11.0),watchos(4.0))
@interface NSPersistentHistoryChangeRequest : NSPersistentStoreRequest {
}

+ (nonnull instancetype)fetchHistoryAfterDate:(NSDate *)date;
+ (nonnull instancetype)fetchHistoryAfterToken:(nullable NSPersistentHistoryToken *)token;
+ (nonnull instancetype)fetchHistoryAfterTransaction:(nullable NSPersistentHistoryTransaction *)transaction;

+ (nonnull instancetype)deleteHistoryBeforeDate:(NSDate *)date;
+ (nonnull instancetype)deleteHistoryBeforeToken:(nullable NSPersistentHistoryToken *)token;
+ (nonnull instancetype)deleteHistoryBeforeTransaction:(nullable NSPersistentHistoryTransaction *)transaction;

// The type of result that should be returned from this request. Defaults to NSPersistentHistoryResultTypeTransactionsAndChanges
@property NSPersistentHistoryResultType resultType;
@property (nullable,readonly,strong) NSPersistentHistoryToken *token;

@end

NS_ASSUME_NONNULL_END

/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSObject.h"

@interface ABFileManager : NSObject
{
}

+ (id)createDirectoryIfNonExistent:(id)arg1;
+ (id)directoryForSearchPath:(unsigned int)arg1;
+ (id)cachesDirectory;
+ (id)documentsDirectory;
+ (id)subCacheDirectory:(id)arg1;
+ (id)subDocumentsDirectory:(id)arg1;
+ (id)multipartPOSTDataDirectory;
+ (id)tweetieComposeAttachmentsDirectory;
+ (id)tweetieProfileImageCacheDirectory;
+ (id)databaseCacheDirectory;
+ (id)miscCacheDirectory;
+ (id)applicationStateDirectory;
+ (id)storedStreamsDirectory;

@end


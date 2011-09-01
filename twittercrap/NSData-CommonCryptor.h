/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2010 by Steve Nygard.
 */

#import "NSData.h"

@interface NSData (CommonCryptor)
+ (id)randomAES256InitializationVector;
- (id)AES256EncryptedDataUsingKey:(id)arg1 initializationVector:(id)arg2 error:(id *)arg3;
- (id)AES256EncryptedDataUsingKey:(id)arg1 error:(id *)arg2;
- (id)decryptedAES256DataUsingKey:(id)arg1 error:(id *)arg2;
- (id)DESEncryptedDataUsingKey:(id)arg1 error:(id *)arg2;
- (id)decryptedDESDataUsingKey:(id)arg1 error:(id *)arg2;
- (id)CASTEncryptedDataUsingKey:(id)arg1 error:(id *)arg2;
- (id)decryptedCASTDataUsingKey:(id)arg1 error:(id *)arg2;
@end


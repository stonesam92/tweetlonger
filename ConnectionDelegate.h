
#import <Foundation/Foundation.h>

@interface ConnectionDelegate : NSObject {
    NSMutableData *receivedData;
    volatile BOOL isComplete;
    volatile BOOL didFail;
}

- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response;
- (void)connectionDidFinishLoading:(NSURLConnection *)connection;
- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data;
- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error;

@property (assign, nonatomic) NSMutableData *receivedData;
@property (assign) volatile BOOL isComplete;
@property (assign) volatile BOOL didFail;
@end

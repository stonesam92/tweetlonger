
#import "ConnectionDelegate.h"

@implementation ConnectionDelegate

- (id)init
{
    self = [super init];
    if (self) {
        isComplete = NO;
        didFail = NO;
        receivedData = [[NSMutableData data] retain];
    }
    
    return self;
}

- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response
{
    [receivedData setLength:0];
    NSLog(@"connection started");
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection
{
    NSLog(@"did finish loading connection");
    isComplete = YES;
}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data
{
    [receivedData appendData:data];
    NSLog(@"received some data");
}

- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error 
{
    isComplete = YES;
    didFail = YES;
    NSLog(@"connection failed");
}

- (void)dealloc
{
    [receivedData release];
    [super dealloc];
}

@synthesize receivedData;
@synthesize isComplete;
@synthesize didFail;

@end

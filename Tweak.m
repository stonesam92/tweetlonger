/*-------------------------------------------------------------------------------------------------------------------------- 
 
 TweetLonger by Sam Stone, created 08/2011. All rights reserved.
 
 Expands TwitLonger links inline rather than opening up a browser 
 window and wasting data and time loading the images, ads etc.
 
 compiles with theos. (obviously)
 
--------------------------------------------------------------------------------------------------------------------------*/




#import <Foundation/Foundation.h>

#pragma mark constants

#define UNSHORTME           @"http://api.unshort.me/?r=%@&t=xml"
#define USMRESPONSESTART    @"<resolvedURL>"
#define USMRESPONSEEND      @"</resolvedURL>"
#define TLRESPONSESTART     @"<article>\n\t\t\t\t\t\t\t\t\t\t\n\t\t\t\t\t<p>\n\t\t\t\t\t\t"
#define TLRESPONSEEND       @"\t\t\t\t\t\t\n\t\t\t\t\t\t<span id=\"postactions\">"
#define USMRESPONSETYPE     0
#define TLRESPONSETYPE      1


typedef int responseType;

static NSString *nextExpandedText = nil;
static id lastUsedTweetViewController = nil;
static id lastUsedTwitterStatus = nil;
static BOOL lastUsedIsAnimated = NULL;
static int lastUsedDirectionToGo = NULL;
static NSString *originalText = nil;



#pragma mark Helper Functions



NSString * parseResponse(NSString *response, responseType kind) { //takes a html/xml response from a site and spits out the relevent part
    
    NSString *startString, *endString;
    
    if (kind == USMRESPONSETYPE) {
        startString = USMRESPONSESTART;
        endString   = USMRESPONSEEND;
    }
    if (kind == TLRESPONSETYPE) {
        startString = TLRESPONSESTART;
        endString   = TLRESPONSEEND;
    }
    NSRange starttag = [response rangeOfString:startString], endtag = [response rangeOfString:endString];
    NSRange urlrange = {(starttag.location + starttag.length), (endtag.location - (starttag.location + starttag.length))};  //obtain the range of the resolved url
    NSString *parsedResponse = [[NSString alloc] initWithString:[response substringWithRange:urlrange]];
    NSLog(@"PARSED %d RESPONSE OBTAINED: %@, has %i references", kind, parsedResponse, [parsedResponse retainCount]);
    
    
    return [parsedResponse autorelease];
}

id isLinkTwitLonger(NSString *shortURL) { //should be a method instead?
    NSURL *USMRequestURL = [[NSURL alloc] initWithString:[NSString stringWithFormat:UNSHORTME, shortURL]];                     //combines unshortme url with the given short url to expand
    NSString *USMResponse = [[NSString alloc] initWithContentsOfURL:USMRequestURL encoding:NSUTF8StringEncoding error:nil];       //get XML from unshortme. should be done asynchronously?
    if (!USMResponse) {
        NSLog(@"got no USM response, no connection");
        [USMResponse release];
        [USMRequestURL release];
    }
    NSLog(@"got USM response: %@", USMResponse);
    NSString *longURL = [parseResponse(USMResponse, USMRESPONSETYPE) retain];
    NSLog(@"longURL has %i references", [longURL retainCount]);
    NSLog(@"Requsturl and response have %i and %i references", [USMRequestURL retainCount], [USMResponse retainCount]);
    
    [USMRequestURL release];
    [USMResponse release];
    
    if (([longURL length] >= 30) && [[longURL substringToIndex:30] isEqualToString:@"http://www.twitlonger.com/show"]) { //check if it is a twitlonger link
        NSLog(@"Tweetlonger link obtained: %@", longURL);
        return [longURL autorelease];
    }
    
    [longURL release];
    return nil;
}
    
    
#pragma mark Hooks

%hook TweetieTweetViewController

- (BOOL)webView:(id)webView shouldStartLoadWithRequest:(id)request navigationType:(unsigned int)navigationType {

    NSURL *linkURL = [request URL];
    if ([[[linkURL description] substringToIndex:7] isEqualToString:@"http://"]) { //a non-internal link has been clicked
        NSLog(@"link clicked: %@", [linkURL description]);
        NSString *TwitLongerLink = nil;
        
        if ((TwitLongerLink = isLinkTwitLonger([linkURL description])) != nil) {
            NSLog(@"inside the twitlonger if block");
            NSURL *TwitLongerURL = [[NSURL alloc] initWithString:TwitLongerLink];
            NSString *TwitLongerResponse = [[NSString alloc] initWithContentsOfURL:TwitLongerURL];
            nextExpandedText = [parseResponse(TwitLongerResponse, TLRESPONSETYPE) retain];
            NSLog(@"nextExpandedText is now set to %@", nextExpandedText);
            [lastUsedTweetViewController _navigateToStatus:lastUsedTwitterStatus animated:lastUsedIsAnimated];
            NSLog(@"function is still executing, its fine");
            [TwitLongerURL release];
            [TwitLongerResponse release];
            return NO;
        }
    }

    else NSLog(@"tweet clicked");

    return %orig;
    

}
/* bad ideaaa 
- (void)setStatus:(id)statusToSet animated:(BOOL)isAnimated direction:(int)directionToGo {
    if (lastUsedTweetViewController != self) {
        NSLog(@"changing TweetViewController to %@", [self description]);
        if (lastUsedTweetViewController != nil) [lastUsedTweetViewController release];
        lastUsedTweetViewController = [self retain];
    }
    if (lastUsedTwitterStatus != statusToSet) {
        NSLog(@"changing TwitterStatus to %@", [statusToSet description]);
        if (lastUsedTwitterStatus != nil) [lastUsedTwitterStatus release];
        lastUsedTwitterStatus = [statusToSet retain];
    }
    lastUsedIsAnimated = isAnimated;
    lastUsedDirectionToGo = directionToGo;
    NSLog(@"status text is %@, displayText is %@", [statusToSet text], [statusToSet displayText]);
    %orig;
}
*/
%end

%hook TweetieStatusListViewController

-(void)_navigateToStatus:(id)statusToSet animated:(BOOL)isAnimated {
    if (lastUsedTweetViewController != self) {
        NSLog(@"changing TweetViewController from %@ to %@", [lastUsedTweetViewController description], [self description]);
        if (lastUsedTweetViewController != nil) {
            NSLog(@"inside if block")
            [lastUsedTweetViewController release];//crashes here?
        }
        lastUsedTweetViewController = [self retain]; //or here?
    }
    if (lastUsedTwitterStatus != statusToSet) { //or in this block
        NSLog(@"changing TwitterStatus to %@", [statusToSet description]);
        if (lastUsedTwitterStatus != nil) [lastUsedTwitterStatus release];
        lastUsedTwitterStatus = [statusToSet retain];
    }
    lastUsedIsAnimated = isAnimated;
    %orig;
}

%end

%hook TwitterStatus

- (NSString *)displayText {
    static int timesCalled = 1;
    NSLog(@"inside custom displayText");
    if (!nextExpandedText) {
        return %orig;
    }
    else {
        NSLog(@"reading from nextExpandedText");
        NSLog(@"been called %d times", timesCalled);
        if (timesCalled == 3) {
            timesCalled = 1;
            NSString *temp = [nextExpandedText retain];
            [nextExpandedText release];
            nextExpandedText = nil;
            return [temp autorelease];
        }
        else {
            timesCalled++;
            return nextExpandedText;
        }
        
    }
}

%end

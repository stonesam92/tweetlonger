/*-------------------------------------------------------------------------------------------------------------------------- 
 TweetLonger by Sam Stone, created 08/2011. All rights reserved.
 
 Expands TwitLonger (a̶l̶s̶o̶ ̶d̶e̶c̶k̶.̶l̶y̶ ̶s̶o̶o̶n̶ edit: I guess not, as of 15/09/11 deck.ly is dicontinued) links in-line rather than opening up a browser 
 window and wasting data and time loading the images, ads etc.
 
 builds with theos. (obviously)
 
--------------------------------------------------------------------------------------------------------------------------*/




#import     <Foundation/Foundation.h>
#import     <UIKit/UIKit.h>
#import     "ConnectionDelegate.h"
#include    <stdio.h>
#include    <string.h>

#pragma mark defines

#define UNSHORTME               @"http://api.unshort.me/?r=%@&t=xml"
#define USMRESPONSESTART        @"<resolvedURL>"
#define USMRESPONSEEND          @"</resolvedURL>"
#define TLRESPONSESTART         @"<article>\n\t\t\t\t\t\t\t\t\t\t\n\t\t\t\t\t<p>\n\t\t\t\t\t\t"
#define TLRESPONSEEND           @"\t\t\t\t\t\t\n\t\t\t\t\t\t<span id=\"postactions\">"
#define USERNAMEUNIQUESTRING    "class=\"twitter-anywhere-user\">"
#define USERNAMESCANSTRING      "class=\"twitter-anywhere-user\">%[^<]</a>"
#define HASHTAGUNIQUESTRING     "<a href=\"http://search.twitter.com/search?q=%23"
#define HASHTAGSCANSTRING       "<a href=\"http://search.twitter.com/search?q=%%23%[^\"]\">"
#define LINKUNIQUESTRING        "<a href=\""
#define LINKSCANSTRING          "<a href=\"%[^\"]\""
#define USERNAMEBASELENGTH      63
#define HASHTAGBASELENGTH       52
#define LINKBASELENGTH          15
#define USMRESPONSETYPE         0
#define TLRESPONSETYPE          1
#define NOTREACHABLE            0
#define REACHABLEVIAWIFI        1
#define REACHABLEVIAWWAN        2

typedef struct _entityInfo {
    int location;
    int length;
    char *replacementString;
    struct _entityInfo *next;
} entityInfo;

typedef int responseType;

static NSMutableDictionary  *cachedStatuses             = nil; 
static NSString             *nextExpandedText           = nil;
static id                   lastUsedTweetViewController = nil;
static id                   lastUsedTwitterStatus       = nil;
static BOOL                 lastUsedIsAnimated          = YES;
static BOOL                 overrideEntities            = NO;


#pragma mark Parsing Functions

entityInfo * parseUserNames(char *toParse, entityInfo *lastItem, entityInfo *entityItem, int searchedSoFar) {
    
        
    char *locationOfUN = NULL, parsedOutput[25];
    int lengthOfUN;
    
    locationOfUN = strstr(toParse, USERNAMEUNIQUESTRING);
    if (!locationOfUN) {
        NSLog(@"about to free");
        free(entityItem);
        NSLog(@"freed");
        return lastItem;
    }
    
    sscanf(locationOfUN, USERNAMESCANSTRING, parsedOutput);
    NSLog(@"parsed username: %s", parsedOutput);
    
    lengthOfUN = strlen(parsedOutput);
    locationOfUN = locationOfUN - (29+(lengthOfUN));
    entityItem->location = (locationOfUN + searchedSoFar - toParse); //the difference between the two pointers is how many chars into the status it is
    entityItem->replacementString = (char *) malloc(lengthOfUN + 1); //plus one byte for the '\0'
    strcpy(entityItem->replacementString, parsedOutput);
    entityItem->length = ((2*lengthOfUN) + USERNAMEBASELENGTH);
    entityItem->next = (entityInfo *) malloc(sizeof(entityInfo));
    if (!entityItem) {
        NSLog(@"malloc failed. shiiiiiiit");
        return NULL;
    }

    return parseUserNames(locationOfUN + entityItem->length, entityItem, entityItem->next, entityItem->location + entityItem->length); 
    
}

entityInfo * parseHashtags(char *toParse, entityInfo *lastItem, entityInfo *entityItem, int searchedSoFar) {
    
    
    char *locationOfHT = NULL, parsedOutput[30] = "#";
    int lengthOfHT;
    
    locationOfHT = strstr(toParse, HASHTAGUNIQUESTRING);
    NSLog(@"location of hashtag is %s, toParse is %s", locationOfHT, toParse);
    if (!locationOfHT) {
        
        NSLog(@"about to free");
        free(entityItem);
        NSLog(@"freed");
        return lastItem;
    }
    
    sscanf(locationOfHT, HASHTAGSCANSTRING, parsedOutput+1); // parsedOutput+1 so the '#' already in the buffer isn't overwritten
    NSLog(@"parsed hashtag: %s", parsedOutput);
    
    lengthOfHT = strlen(parsedOutput);
    entityItem->location = (locationOfHT + searchedSoFar - toParse); //the difference between the two pointers is how many chars into the status it is
    entityItem->replacementString = (char *) malloc(lengthOfHT + 1); //plus one for the '\0' terminator
    strcpy(entityItem->replacementString, parsedOutput);
    entityItem->length = ((2*lengthOfHT) + HASHTAGBASELENGTH);
    entityItem->next = (entityInfo *) malloc(sizeof(entityInfo));
    if (!entityItem) {
        NSLog(@"malloc failed. shiiiiiiit");
        return NULL;
    }
    
    return parseHashtags(locationOfHT + entityItem->length, entityItem, entityItem->next, entityItem->location + entityItem->length); 
    
}

entityInfo * parseLinks(char *toParse, entityInfo *lastItem, entityInfo *entityItem, int searchedSoFar) {
    
    
    char *locationOfURL = NULL, parsedOutput[150];
    int lengthOfURL;
    
    locationOfURL = strstr(toParse, LINKUNIQUESTRING);
    NSLog(@"location of link is %s, toparse is %s", locationOfURL, toParse);
    if (!locationOfURL) {
        
        NSLog(@"about to free");
        free(entityItem);
        NSLog(@"freed");
        return lastItem;
    }
    
    sscanf(locationOfURL, LINKSCANSTRING, parsedOutput); 
    NSLog(@"parsed link: %s", parsedOutput);
    
    lengthOfURL = strlen(parsedOutput);
    entityItem->location = (locationOfURL + searchedSoFar - toParse); //the difference between the two pointers is how many chars into the status it is
    entityItem->replacementString = (char *) malloc(lengthOfURL + 1); //plus one for the '\0' terminator
    strcpy(entityItem->replacementString, parsedOutput);
    entityItem->length = ((2*lengthOfURL) + LINKBASELENGTH);
    entityItem->next = (entityInfo *) malloc(sizeof(entityInfo));
    if (!entityItem) {
        NSLog(@"malloc failed. shiiiiiiit");
        return NULL;
    }
    
    return parseLinks(locationOfURL + entityItem->length, entityItem, entityItem->next, entityItem->location + entityItem->length); 
    
}

void writeChangesToStatus(char *status, entityInfo *entityList) {

    int s1offset = 0, s2offset = 0;
    while (entityList != NULL) {
        NSLog(@"about to replace from index %d to %d with %s", entityList->location, entityList->length, entityList->replacementString);
        int i, j;                   //counters for the two for loops coming up
        for (i=0; i + s2offset < entityList->location; i++) {
            *(status+i+s1offset) = *(status + s2offset + i);
        }
        NSLog(@"about to enter second loop, i is at %d", i);
        for (j=0; j < strlen(entityList->replacementString); j++) {
            NSLog(@"inside the second loop, j is at %d, replacement is still %s, char on this loop is %c", j, entityList->replacementString, *((entityList->replacementString) + j));
            *(status+i+j+s1offset) = *((entityList->replacementString) + j);
        }
        NSLog(@"status is now set to %s, i is %d, j is %d", status, i, j);
        s1offset += i + j;
        s2offset += i + entityList->length;
        entityInfo *temp = entityList->next;
        NSLog(@"about to free the alloc'd thing");
        free(entityList);
        NSLog(@"freed the second thing");
        entityList = temp;
    }
    int i=0;
    char c;
    
    while ((c = *(status + i + s2offset)) != '\0') {
        *(status + s1offset + (i++)) = c;
    }
    *(status + s1offset + i) = '\0';
}


#pragma mark Helper Functions



NSString * parseStatusHTML(NSString * input) {
    
    /*
     Needs to be change to only make a max of 2 passes of writeChanges by changing hashtag func
     */
    
    entityInfo *entitiesList, *endOfTail;
    char *toParse = (char*) [input UTF8String];
    
    entitiesList = (entityInfo *) malloc(sizeof(entityInfo));
    endOfTail    = parseUserNames(toParse, NULL, entitiesList, 0);
    if (endOfTail != NULL) {
        endOfTail->next = NULL;
        writeChangesToStatus(toParse, entitiesList);
    }
    NSLog(@"wrote usernames back to status");
    entitiesList = (entityInfo *) malloc(sizeof(entityInfo));
    endOfTail    = parseHashtags(toParse, NULL, entitiesList, 0);
    if (endOfTail != NULL) {
        endOfTail->next = NULL;
        writeChangesToStatus(toParse, entitiesList);
    }
    NSLog(@"wrote hashtags back to status");
    entitiesList = (entityInfo *) malloc(sizeof(entityInfo));
    endOfTail    = parseLinks(toParse, NULL, entitiesList, 0);
    if (endOfTail != NULL) {
        endOfTail->next = NULL;
        writeChangesToStatus(toParse, entitiesList);
    }
    NSLog(@"wrote links back to status");
    
    return [NSString stringWithUTF8String:toParse];
    
}



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
    
    NSLog(@"got here, with response %@ and range:{%d,%d}", response, urlrange.location, urlrange.length);
    
    NSString *parsedResponse = [[NSString alloc] initWithString:[response substringWithRange:urlrange]];                    
    
    NSLog(@"PARSED %d RESPONSE OBTAINED: %@, has %i references", kind, parsedResponse, [parsedResponse retainCount]);
    
    return [parsedResponse autorelease];
}

id isLinkTwitLonger() {
   /* 
    NSURLRequest *USMRequest = [[NSURLRequest alloc]initWithURL:[NSURL URLWithString:[NSString stringWithFormat:UNSHORTME, shortURL]]
                                             cachePolicy:NSURLRequestReloadIgnoringLocalAndRemoteCacheData
                                         timeoutInterval:30.0];
    
    NSURLConnection *connection = [[NSURLConnection alloc] initWithRequest:USMRequest 
                                                                  delegate:connectionDelegate];

    NSLog(@"started connection %@ with request %@, delegate %@", connection, USMRequest, connectionDelegate);
//    NSLog(@"current runloop is %@, main is %@, current mode is %@, main mode is %@", [NSRunLoop currentRunLoop], [NSRunLoop mainRunLoop], 
//          [[NSRunLoop currentRunLoop] currentMode], [[NSRunLoop mainRunLoop] currentMode]);;
    NSString *USMResponse = nil;
    
    while (![connectionDelegate isComplete] && [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode beforeDate:[NSDate distantFuture]]) {
        NSLog(@"connection does still exist? %@,  %@", connection, connectionDelegate);
//        NSLog(@"inside this infinite loop.......");
    }
    NSLog(@"got out of infinite loop");
    if (![connectionDelegate didFail]) {
        USMResponse = [[NSString alloc] initWithData:[connectionDelegate receivedData] encoding:NSUTF8StringEncoding]; 
    }
    if (!USMResponse) {
            
        NSLog(@"got no USM response, no connection");
        
        [USMResponse release];
        [connection release];
        [USMRequest release];
        return nil;
    }
    
    NSLog(@"got USM response: %@", USMResponse);
    
    NSString *longURL = [parseResponse(USMResponse, USMRESPONSETYPE) retain];
    
    [USMRequest release];
    [USMResponse release];
    [connection release];
*/
    id urlsArray = [[lastUsedTwitterStatus entities]  urls] ;
    NSString *longURL = [[[urlsArray objectAtIndex:([urlsArray count]-1)] expandedURL] absoluteString];
    NSLog(@"longURL is %@", longURL);
    if ((([longURL length] >= 30) && [[longURL substringToIndex:30] isEqualToString:@"http://www.twitlonger.com/show"]) ||
         (([longURL length] >= 13) &&[[longURL substringToIndex:13] isEqualToString:@"http://tl.gd/"])) { //check if it is a twitlonger link
            
        NSLog(@"Tweetlonger link obtained: %@", longURL);
        return longURL;
    }
    
    //[longURL release];
    return nil;

}
    
    
#pragma mark Hooks

%hook TweetieTweetViewController
- (BOOL)webView:(id)webView shouldStartLoadWithRequest:(id)request navigationType:(unsigned int)navigationType {
    
    if (!lastUsedTweetViewController || !lastUsedTwitterStatus) {                            
        NSLog(@"controller/status was nil, returing %orig");
        return %orig;
    }
    
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

    NSURL *linkURL = [request URL];
    if ([[[linkURL description] substringToIndex:7] isEqualToString:@"http://"]) { //a non-internal link has been clicked
        
        [nextExpandedText release];
        
        if (nextExpandedText = [cachedStatuses objectForKey:request]) {
            NSLog(@"status is already cached: %@", nextExpandedText);
            [lastUsedTweetViewController _navigateToStatus:lastUsedTwitterStatus animated:lastUsedIsAnimated];
            [pool drain];
            return NO;
        }
        
        int networkStatus = (int) [[%c(ABReachability) sharedReachability] currentReachabilityStatus];
        switch (networkStatus) {
                
            case NOTREACHABLE: {
                NSLog(@"no internet connection detected");
                UIAlertView *internetWarning = [[UIAlertView alloc] initWithTitle:@"No Internet Connection Available" 
                                                                          message:@"Could not load link" 
                                                                         delegate:nil 
                                                                cancelButtonTitle:@"Okay" 
                                                                otherButtonTitles:nil];
                [internetWarning show];
                [internetWarning autorelease];
                return NO;
                break;
            }
            
            case REACHABLEVIAWWAN: {
                NSLog(@"no wifi connection");
                return %orig;
                break;
                // should put this case above the wifi one. then don't break so it falls through. set up the activity indicator in here then let it fall through to the asynchronous 
                // nsurlconnection. 
            }
        }
        
        NSLog(@"link clicked: %@", [linkURL description]);
        NSString *TwitLongerLink = nil;
        
        if (TwitLongerLink = isLinkTwitLonger()) {
            ConnectionDelegate *connectionDelegate = [[ConnectionDelegate alloc] init];
            
            NSLog(@"inside the twitlonger if block, tl link is %@", TwitLongerLink);
            
            NSString *statusHTML = nil;
            NSURL *TwitLongerURL = [[NSURL alloc] initWithString:TwitLongerLink];
            NSLog(@"about to get response");
            NSString *TwitLongerResponse = [[NSString alloc] initWithContentsOfURL:TwitLongerURL];
            NSLog(@"got response %@", TwitLongerResponse);
            statusHTML = [parseResponse(TwitLongerResponse, TLRESPONSETYPE) stringByReplacingOccurrencesOfString:@"<br />" withString:@"\n"];
            statusHTML = [parseStatusHTML(statusHTML) retain];
            nextExpandedText = [statusHTML retain];
            
            if (!cachedStatuses) {
                cachedStatuses = [[NSMutableDictionary alloc] initWithCapacity:1];
                NSLog(@"just made the cached dictionary");
            }
            [cachedStatuses setObject:nextExpandedText forKey:request];
            NSLog(@"dictionary of cached status is now %@", cachedStatuses);
            
            NSLog(@"nextExpandedText is now set to %@", nextExpandedText);
            
            [lastUsedTweetViewController _navigateToStatus:lastUsedTwitterStatus animated:lastUsedIsAnimated];
            
            [TwitLongerURL release];
            [TwitLongerResponse release];
            [pool drain];
            return NO;
        }
        else {
            NSLog(@"non-tl link clicked");
        }
    }    
            
    else {
        NSLog(@"tweet clicked");
    }
    
    [pool drain];
    return %orig;
    

}

%end

%hook TweetieStatusListViewController

-(void)_navigateToStatus:(id)statusToSet animated:(BOOL)isAnimated {
    
    if (![self isKindOfClass:[%c(TweetieUserRecentsViewController) class]] && lastUsedTweetViewController != self) {
        
        NSLog(@"changing TweetViewController from %@ to %@", [lastUsedTweetViewController description], [self description]);
        if (lastUsedTweetViewController !=nil) {
            [lastUsedTweetViewController release];
        }
        lastUsedTweetViewController = [self retain];
        NSLog(@"new controller retained");
    }
    if ([self isKindOfClass:[%c(TweetieUserRecentsViewController) class]])
        NSLog(@"self is a user controller, skipping");
    if (lastUsedTwitterStatus != statusToSet) { 
        NSLog(@"changing TwitterStatus to %@, animated is %d", [statusToSet description], isAnimated);
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
//    NSLog(@"inside custom displayText");
    if (!nextExpandedText) {
        return %orig;
    }
    else {
        NSLog(@"reading from nextExpandedText");
        NSLog(@"been called %d times", timesCalled);
        overrideEntities = YES;
        if (timesCalled == 2) {                   
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

- (NSArray *)displayTextRanges {
//    NSLog(@"inside custom displayTextRanges");
    if (!overrideEntities)
        return %orig;
    overrideEntities = NO;
    return [NSArray array];
}

%end

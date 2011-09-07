/*-------------------------------------------------------------------------------------------------------------------------- 
 TweetLonger by Sam Stone, created 08/2011. All rights reserved.
 
 Expands TwitLonger (also deck.ly soon) links in-line rather than opening up a browser 
 window and wasting data and time loading the images, ads etc.
 
 compiles with theos. (obviously)
 
--------------------------------------------------------------------------------------------------------------------------*/




#import     <Foundation/Foundation.h>
#include    <stdio.h>
#include    <string.h>

#pragma mark constants

#define UNSHORTME           @"http://api.unshort.me/?r=%@&t=xml"
#define USMRESPONSESTART    @"<resolvedURL>"
#define USMRESPONSEEND      @"</resolvedURL>"
#define TLRESPONSESTART     @"<article>\n\t\t\t\t\t\t\t\t\t\t\n\t\t\t\t\t<p>\n\t\t\t\t\t\t"
#define TLRESPONSEEND       @"\t\t\t\t\t\t\n\t\t\t\t\t\t<span id=\"postactions\">"
#define USMRESPONSETYPE     0
#define TLRESPONSETYPE      1

typedef struct _entityInfo {
    int location;
    int length;
    char replacementString[25];
    struct _entityInfo *next;
} entityInfo;

typedef int responseType;

static NSString *nextExpandedText = nil;
static id lastUsedTweetViewController = nil;
static id lastUsedTwitterStatus = nil;
static BOOL lastUsedIsAnimated = NULL;

#pragma mark Parsing Functions

entityInfo * parseUserNames(char *toParse, entityInfo *lastItem, entityInfo *entityItem, int searchedSoFar) {
    
        
    char *locationOfUN = NULL, parsedOutput[25];
    int lengthOfUN;
    
    locationOfUN = strstr(toParse, "class=\"twitter-anywhere-user\">");
    if (!locationOfUN) {
        NSLog(@"about to free");
        free(entityItem);
        NSLog(@"freed");
        entityItem = NULL; //doesn't actually NULL the original pointer, just the local reference :/
        return lastItem;
    }
    
    sscanf(locationOfUN, "class=\"twitter-anywhere-user\">%[^<]</a>", parsedOutput);
    NSLog(@"parsed username: %s", parsedOutput);
    
    lengthOfUN = strlen(parsedOutput);
    locationOfUN = locationOfUN - (29+(lengthOfUN));
    entityItem->location = (locationOfUN + searchedSoFar - toParse); //the difference between the two pointers is how many chars into the status it is
    strcpy(entityItem->replacementString, parsedOutput);
    entityItem->length = ((2*lengthOfUN) +63);
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
    
    locationOfHT = strstr(toParse, "<a href=\"http://search.twitter.com/search?q=%23");
    NSLog(@"location of hashtag is %s, toparse is %s", locationOfHT, toParse);
    if (!locationOfHT) {
        
        NSLog(@"about to free");
        free(entityItem);
        NSLog(@"freed");
        //entityItem = NULL; //doesn't actually NULL the original pointer, just the local reference :/
        return lastItem;
    }
    
    sscanf(locationOfHT, "<a href=\"http://search.twitter.com/search?q=%%23%[^\"]\">", parsedOutput+1);
    NSLog(@"parsed hashtag: %s", parsedOutput);
    
    lengthOfHT = strlen(parsedOutput);
    //locationOfHT = locationOfHT - (29+(lengthOfUN));
    entityItem->location = (locationOfHT + searchedSoFar - toParse); //the difference between the two pointers is how many chars into the status it is
    strcpy(entityItem->replacementString, parsedOutput);
    entityItem->length = ((2*lengthOfHT) +52);
    entityItem->next = (entityInfo *) malloc(sizeof(entityInfo));
    if (!entityItem) {
        NSLog(@"malloc failed. shiiiiiiit");
        return NULL;
    }
    
    return parseHashtags(locationOfHT + entityItem->length, entityItem, entityItem->next, entityItem->location + entityItem->length); 
    
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
    entityInfo *entitiesList, *endOfTail;
    char *toParse = (char*) [input UTF8String];
    entitiesList = (entityInfo *) malloc(sizeof(entityInfo));
    endOfTail    = parseUserNames(toParse, NULL, entitiesList, 0);
    if (endOfTail != NULL) {
        endOfTail->next = NULL;
        writeChangesToStatus(toParse, entitiesList);
    }
    entitiesList = (entityInfo *) malloc(sizeof(entityInfo));
    endOfTail    = parseHashtags(toParse, NULL, entitiesList, 0);
    if (endOfTail != NULL) {
        endOfTail->next = NULL;
        writeChangesToStatus(toParse, entitiesList);
    }
    
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
    
    NSString *parsedResponse = [[NSString alloc] initWithString:[response substringWithRange:urlrange]];                    //could this be better done with sscanf?
    
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
        return nil;
    }
    
    NSLog(@"got USM response: %@", USMResponse);
    
    NSString *longURL = [parseResponse(USMResponse, USMRESPONSETYPE) retain];
    
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
        
        if (TwitLongerLink = isLinkTwitLonger([linkURL description])) {
            
            NSLog(@"inside the twitlonger if block");
            NSString *statusHTML = nil;
            NSURL *TwitLongerURL = [[NSURL alloc] initWithString:TwitLongerLink];
            NSString *TwitLongerResponse = [[NSString alloc] initWithContentsOfURL:TwitLongerURL];
            statusHTML = [parseResponse(TwitLongerResponse, TLRESPONSETYPE) stringByReplacingOccurrencesOfString:@"<br />" withString:@"\n"];
            statusHTML = [parseStatusHTML(statusHTML) retain];
            [nextExpandedText release];
            nextExpandedText = [statusHTML retain];
            
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

%end

%hook TweetieStatusListViewController

-(void)_navigateToStatus:(id)statusToSet animated:(BOOL)isAnimated {
    
    if (![self isKindOfClass:[%c(TweetieUserRecentsViewController) class]] && lastUsedTweetViewController != self) {
        
        NSLog(@"changing TweetViewController from %@ to %@", [lastUsedTweetViewController description], [self description]);
        if (lastUsedTweetViewController !=nil) {
            [lastUsedTweetViewController release];//crashes here?
        }
        lastUsedTweetViewController = [self retain];//or here?
        NSLog(@"new controller retained");
    }
    if (![self isKindOfClass:[%c(TweetieUserRecentsViewController) class]])
        NSLog(@"self is a user controller, skipping");
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

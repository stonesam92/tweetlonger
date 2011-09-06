four things to parse:

1. newlines:
* <br />
* \n
* stringbyreplacingoccurrencesof:with:

2. usernames:
* <a href="http://twitter.com/username" class="twitter-anywhere-user">@username</a>
* @username, entity?
* "%[^<]<a href=\"http://twitter.com/%[^\"]\" class=\"twitter-anywhere-user\">%[^<]</a>%[^]"
- strsrt(orig, "class=\twitter-anywhere-user\">")
- get username from that on the result of strstr
- work out length of the whole string, 

3. hashtags:
* <a href="http://search.twitter.com/search?q%23HASHTAG">#HASHTAG</a>
* #hashtag, entity?
* …

4. links
* <a href="linkdisplayname">linkurl</a>
* linkurl, entity
* … 



/**
* Wildcard Matching
* Implement wildcard pattern matching with support for '?' and '*'
* '?' Matches any single character.
* '*' Matches any sequence of characters (including the empty sequence).
* Solution: Just need to trace back at the nearest star position
*/
class Solution {
public:
	bool isMatch(const char *s, const char *p);
};
bool Solution::isMatch(const char *s, const char *p){
	const char * ss=NULL, *pp=NULL;
	while (*s != '\0'){
		if (*p == '?'){
			s++;
			p++;
		}
		else if (*p == '*'){
			while (*(p + 1) == '*') p++;
			ss = s;
			pp = p++;
		}
		else if (*s == *p) {
			s++;
			p++;
		}
		else if (pp!=NULL){
			s = ++ss;
			p = pp + 1;
		}
		else return false;
	}
	while (*p=='*') p++;
	return *s == '\0' && *p == '\0';
}

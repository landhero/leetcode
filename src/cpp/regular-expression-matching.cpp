/**
* Regular Expression Matching
* Implement regular expression matching with support for '.' and '*'
* '.' Matches any single character
* '*' Matches zero or more of preceding element.
* Solution: Use dynamic programming
*/

class Solution {
public:
	bool isMatch(const char *s, const char *p);
};

bool Solution::isMatch(const char *s, const char *p){
	int n = strlen(s);
	vector<bool>f(n+1, false);
	f[0] = true;
	while ( *p!='\0' ){
		char c = *p++;
		bool is_star = ( *p == '*');
		if (is_star) p++;
		if (is_star){
			for (int i=1; i<=n; i++)
				f[i] = f[i] || (f[i-1] && (c==s[i-1] || c=='.'));
		}else{
			for (int i=n; i>0; i--)
				f[i] = f[i-1] && (c==s[i-1] || c=='.');
			f[0] = false;  //important
		}
	}
	return f[n];
}

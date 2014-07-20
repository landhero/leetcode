/*
easy
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    bool isPalindrome(string s);
};
int getID(char c){
	if (c>='a' && c<='z')
	    return c-'a';
	if (c>='A' && c<= 'Z')
	    return c-'A';
	if (c>='0' && c<='9')
	    return 30 + (c-'0');
	return -1;
}
bool Solution::isPalindrome(string s) {
    int len = s.length();
	int i =0, j = len-1;
	while (i<j && i<len && j>=0){
	    int a = getID(s[i]);
	    if (a==-1){
		    i++;
		    continue;
	    }
	    int b = getID(s[j]);
	    if (b==-1){
		    j--;
		    continue;
	    }
	    if (a!=b)
		    return false;
	    i++;
	    j--;
	}
	return true;
}

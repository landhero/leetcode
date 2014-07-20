/**
* 56ms, my origin solution is 16ms. But this code is easier to read.
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length()!=s2.length())
            return false;
        if (s1 == s2)
            return true;
	    string ts1 = s1, ts2 = s2;
	    sort(ts1.begin(),ts1.end());
	    sort(ts2.begin(), ts2.end());
	    if (ts1!=ts2)
	        return false;
	    int len = s1.length();
	    for (int i=1; i<len; i++){
	        if (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i,len-i), s2.substr(i,len-i)))
	            return true;
	        if (isScramble(s1.substr(0,i), s2.substr(len-i,i)) && isScramble(s1.substr(i,len-i), s2.substr(0,len-i)))
	            return true;
	    }
	    return false;
    }
};

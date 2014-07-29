/**
* @author Hansheng Zhang
*/
class Solution {
public:
    int lengthOfLongestSubstring(string);
};
int Solution::lengthOfLongestSubstring(string s){
    int len = s.length();
    if (len <= 0)
        return 0;
    int rlt = -1;
    const char * p  = s.c_str();
    const char * q = p;
    bool flag[256];
    memset(flag, 0, 256*sizeof(char));
    int curLen = 0;
    while (*p !='\0' && *q !='\0'){
        if(!flag[*q]){
            curLen ++;
            flag[*q] = true;
            q++;
        }
        else{
            if (curLen>rlt)
                rlt = curLen;
            while (*p != *q) {
                flag[*p] = false; //waring, important!
                p++;
                curLen--;
            }
            p++;
            curLen--;
            flag[*q] = false;
        }
    }
    if (curLen>rlt)
        rlt = curLen;
    return rlt;
}
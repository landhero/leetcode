/**
* @author Hansheng Zhang
*/
class Solution {
public:
    int lengthOfLastWord(const char *);
};

int Solution::lengthOfLastWord(const char * s){
    int len = strlen(s), rlt = 0;
    const char * itr = s + len - 1;
    while (itr >= s){
        if (*itr != ' ')
            rlt++;
        else if (rlt != 0)
            return rlt;
        itr = itr - 1;
    }
    return rlt;
}
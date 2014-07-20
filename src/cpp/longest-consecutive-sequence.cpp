/*
use hash map
is there a better solution?
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    int longestConsecutive(vector<int> &);
};
int Solution::longestConsecutive(vector<int> &num){
    int n = num.size();
    int rlt = 0;
    unordered_map<int,unsigned> flags;
    for (int i=0; i<n; i++){
        flags[num[i]] = 0;
    }
    for (int i=0; i<n; i++){
        unordered_map<int,unsigned>::iterator curItr = flags.find(num[i]);
        if (curItr->second != 0)
            continue;
        int curValue = num[i];
        int len = 1;
        int j;
        for (j=curValue+1; ; j++){
            unordered_map<int, unsigned>::iterator itr = flags.find(j);
            if (itr==flags.end())
                break;
            if (itr->second!=0){
                len += itr->second;
                break;
            }
            len++;
        }
        if (len>rlt)
            rlt = len;
        while (curValue<j){
            flags[curValue++] = len--;
        }
    }
    return rlt;
}

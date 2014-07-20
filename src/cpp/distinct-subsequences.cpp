/*
dp: update flags reversely to avoid muiti-updates
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    int numDistinct(string, string);
};
int Solution::numDistinct(string S, string T){
    int slen = S.length();
    int tlen = T.length();
    if (tlen > slen)
        return 0;
    vector<int> flags(tlen+1,0);
    flags[0] = 1;
    for (int i=0; i<slen; i++){
        int j = min(i, tlen-1);
        while (j>=0){
            if (T[j] == S[i])
                flags[j+1] += flags[j];
            j--;
        }
    }
    return flags[tlen];
}
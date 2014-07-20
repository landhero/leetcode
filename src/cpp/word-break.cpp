/**
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    bool wordBreak(string &, int, unordered_set<string> &, int*);
    bool wordBreak(string, unordered_set<string>&);
};

bool Solution::wordBreak(string &s, int index, unordered_set<string> &dict, int* flag){
    if (flag[index]!=0)
        return flag[index]==1 ? true:false;
    int len = s.length()-index;
    string header;
    bool ans = false;
    for (int i=index; i<s.length(); i++){
        header = header+s.at(i);
        if (dict.find(header)!=dict.end())
            if (wordBreak(s, i+1, dict,flag)){
                ans = true;
                break;
            }
    }
    if (ans)
        flag[index] = 1;
    else flag[index] = -1;
    return ans;
}

bool Solution::wordBreak(string s, unordered_set<string> &dict) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
    int* flag = new int[s.length()+1];
    flag[s.length()] = 1;
    for (int i=0; i<s.length(); i++)
        flag[i] = 0;
    bool ans = wordBreak(s, 0, dict, flag);
    delete []flag;
    return ans;
}

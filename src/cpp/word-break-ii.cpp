/**
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    vector<vector<string>> rlts;
    int * flag;
    bool wordBreak(string &s, int index, unordered_set<string> &dict){
        if (flag[index]==-1)
            return false;
        if (!rlts[index].empty())
            return true;
        int len = s.length()-index;
        if (len==0){
            return true;
        }
        string header;
        bool ans = false;
        for (int i=index; i<s.length(); i++){
            header = header+s.at(i);
            if (dict.find(header)!=dict.end())
                if (wordBreak(s, i+1, dict)){
                    ans = true;
                    if (i==s.length()-1)
                        rlts[index].push_back(header);
                    else {
                        int sz = rlts[i+1].size();
                        for (int j =0; j<sz; j++)
                            rlts[index].push_back(header +" "+ rlts[i+1][j]);
                    }
                }
        }
        if (ans == false)
            flag[index] = -1;
        return ans;
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        rlts.clear();
        flag = new int[s.length()+1];
        for (int i=0; i<s.length()+1; i++){
            rlts.push_back(vector<string>());
            flag[i] = 0;
        }
        wordBreak(s, 0,dict);
        return rlts[0];
    }
};
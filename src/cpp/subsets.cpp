/**
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(S.begin(), S.end());
        int n = S.size();
        vector<vector<int>> rlt;
        rlt.push_back(vector<int>());
        int i, j;
        for (i=0; i<n; i++){
            int m = rlt.size();
            for (j=0; j<m; j++){
                vector<int> tmp = rlt[j];
                tmp.push_back(S[i]);
                rlt.push_back(tmp);
            }
        }
        return rlt;
    }
};

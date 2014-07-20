/*
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int>> rlt;
        if (numRows<=0)
            return rlt;
        vector<int> tmp;
        tmp.push_back(1);
        rlt.push_back(tmp);
        for (int i=1; i<numRows; i++){
            vector<int> iv;
            iv.push_back(1);
            for (int j=1; j<i; j++){
                iv.push_back(rlt[i-1][j-1]+rlt[i-1][j]);
            }
            iv.push_back(1);
            rlt.push_back(iv);
        }
        return rlt;
    }
};

/*
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> rlt(rowIndex+1, 1);
        for (int i=0; i<=rowIndex; i++){
            int last = 1;
            int cur = 1;
            for (int j=1; j<i; j++){
                cur = rlt[j];
                rlt[j] = cur + last;
                last = cur;
            }
        }
        return rlt;
    }
};
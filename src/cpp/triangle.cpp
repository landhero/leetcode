/*
easy: just be careful
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        const int maxN = 1000000000;
        int n = triangle.size();
        if (n<=0)
            return 0;
        vector<int> rlt(n,0);
        rlt[0] = triangle[0][0];
        int last, cur;
        for (int i=1; i<n; i++){
            last = rlt[0];
            rlt[0]=rlt[0]+triangle[i][0];
            for (int j=1; j<i; j++){
                cur = rlt[j];
                rlt[j] = (cur<=last?cur:last) + triangle[i][j];
                last = cur;
            }
            rlt[i] = last+triangle[i][i];
        }
        int min = rlt[0];
        for (int i=1; i<n; i++)
            if (rlt[i]<min)
                min = rlt[i];
        return min;
    }
};
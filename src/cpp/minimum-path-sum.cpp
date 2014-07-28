class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (grid.size()<=0 || grid[0].size()<=0)
            return -1;
        int m = grid.size(), n=grid[0].size();
        int * sums = new int[n+1];
        int i, j;
        const int maxNum = 1000000000;
        sums[0] = 0;
        for (i=1; i<=n; i++)
            sums[i] = maxNum;
        for (i=0; i<m; i++){
            for (j=1; j<=n; j++){
                if (sums[j]>sums[j-1])
                    sums[j]=sums[j-1]+grid[i][j-1];
                else sums[j] = sums[j] + grid[i][j-1];
            }
            sums[0] = maxNum;
        }
        int rlt = sums[n];
        delete []sums;
        return rlt;
    }
};
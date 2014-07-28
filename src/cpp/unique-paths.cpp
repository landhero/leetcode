/**
* @author Hansheng Zhang
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (m<=0 || n<=0)
            return 0;
        int * f = new int[n];
        for (int i=0; i<n; i++)
            f[i] = 1;
        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++){
                f[j] += f[j-1];
            }
        int rlt = f[n-1];
        delete []f;
        return rlt;
    }
};
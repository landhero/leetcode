/**
* Easy. Think carefully
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ans = 0;
        if (n<=0)
            return 0;
        int * f = new int[n+1];
        f[0] = 1;
        for (int i=1; i<=n; i++){
            f[i]=0;
            for (int j=1; j<=i; j++){
                f[i] += f[j-1]*f[i-j];
            }
        }
        ans = f[n];
        delete []f;
        return ans;
    }
};

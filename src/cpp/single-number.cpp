/**
* @author Hansheng Zhang (http://zhanghs.com)
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n<=0)
            return 0;
        int ans=0;
        for (int i=0; i<n; i++)
            ans ^= A[i];
        return ans;
    }
};
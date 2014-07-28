/**
* @author Hansheng Zhang
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (n<=0)
            return vector<int>(2,-1);
        int l = 0, r = n-1;
        int m;
        int left, right;
        while (l<=r){
            m = (l+r)/2;
            if (A[m]>=target)
                r = m-1;
            else 
                l = m+1;
        }
        if (A[m]==target)
            left = m;
        else if (m+1<n && A[m+1]==target)
            left = m +1;
        else 
            return vector<int>(2,-1);
        l = left, r=n-1;
        while (l<=r){
            m = (l+r)/2;
            if (A[m]>target)
                r=m-1;
            else l = m+1;
        }
        if (A[m]==target)
            right = m;
        else if (m-1>=left && A[m-1]==target)
            right = m-1;
        vector<int> rlt;
        rlt.push_back(left);
        rlt.push_back(right);
        return rlt;
    }
};
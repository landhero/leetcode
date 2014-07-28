/**
* @author Hansheng Zhang
*/
class Solution {
public:
    bool canJump(int A[], int n) {
        if (n<=1)
            return true;
        for (int i=1; i<n; i++){
            int cur = A[i-1] - 1;
            if (cur < 0)
                return false;
            A[i] = max(A[i], cur);
        }
        return true;
    }
};

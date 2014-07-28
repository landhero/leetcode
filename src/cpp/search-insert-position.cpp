/**
* @author Hansheng Zhang
*/
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n<=0)
            return-1;
        if (A[0]>=target)
            return 0;
        if (A[n-1]==target)
            return n-1;
        if (A[n-1]<target)
            return n;
        int left =0, right=n-1;
        int mid = 0;
        while (left + 1< right){
            mid = (left+right)/2;
            if (A[mid]==target)
                return mid;
            else if (A[mid]>target)
                right = mid;
            else left = mid;
        }
        return right;
    }
};

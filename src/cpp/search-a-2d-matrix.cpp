/**
* twice binary searce
* @author Hansheng Zhang
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int m =matrix.size();
        if (m<=0)
            return false;
        int n = matrix[0].size();
        if (n<=0)
            return false;
        int left=0, right=m-1, mid;
        while(left<=right){
            mid = (left+right)/2;
            if (matrix[mid][0]<=target && matrix[mid][n-1]>=target)
                break;
            if (matrix[mid][0]>target)
                right=mid-1;
            if (matrix[mid][n-1]<target)
                left = mid+1;
        }
        vector<int> row = matrix[mid];
        if (row[0]>target || row[n-1]<target)
            return false;
        left = 0, right = n-1;
        while (left<=right){
            mid = (left+right)/2;
            if (row[mid]==target)
                return true;
            if(row[mid]>target)
                right = mid-1;
            else left = mid+1;
        }
        return false;
    }
};
/**
* Find Minimum in Rotated Sorted Array II 
* Follow up for "Find Minimum in Rotated Sorted Array":
* What if duplicates are allowed?
* Would this affect the run-time complexity? How and why?
* Solution: easy
*/

class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0, right=num.size()-1;
        while (left+1<right){
            int middle = (left+right) / 2;
            if (num[middle]<num[left])
                right = middle;
            else if (num[middle]>num[left]){
                if (num[right]<=num[left])
                    left = middle + 1;
                else right = left;
            }else if (num[right]>num[middle]){
                right = left;
            }else if (num[right]<num[middle]){
                left = middle+1;
            }else {
                ++left;
                --right;
            }
        }
        return min(num[left], num[right]);
    }
};

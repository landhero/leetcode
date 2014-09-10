/**
* Search in Rotated Sorted Array II 
* Follow up for "Search in Rotated Sorted Array":
* What if duplicates are allowed?
* Solution: compare left and middle in the outmost loop
*/

class Solution {
public:
    bool search(int [], int, int);
};

bool Solution::search(int a[], int n, int target) {
    int left = 0, right = n-1;
    while (left <= right){
        int middle = (left + right) /2;
        if (a[middle] == target || a[left]==target || a[right]==target)
            return true;
        if (a[left]<a[middle]){
            if (a[middle]<target)
                left = middle + 1;
            else if (a[left]<target)
                right = middle - 1;
            else left = middle + 1; 
        }else if (a[left]>a[middle]){
            if (a[middle] > target)
                right = middle-1;
            else if (a[right] > target)
                left = middle + 1;
            else right = middle -1;
        }else if (a[right]==a[middle]){
            left = left  + 1;
            right = right - 1;
        }else left = middle + 1;
    }
    return false;
}

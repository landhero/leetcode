/**
* important 
* @author Hansheng Zhang (http://zhanghs.com)
*/ 
 
class Solution {
public:
    int search(int[], int, int);
};

int Solution::search(int a[], int n, int target) {
    if (n <= 0)
        return - 1;
    int left = 0, right = n-1;
    while ( left <= right ){
        int middle = (left+right)/2;
        if (a[middle]==target)
            return middle;
        if (a[left] <= a[middle]){
            if (a[middle]<target)
                left = middle+1;
            else if (a[left] <= target)
                right = middle -1;
            else
                left = middle + 1;
        }else if (a[middle]>target){
            right = middle -1;
        }else if (a[right]>=target)
            left = middle + 1;
        else right = middle - 1;
    }
    return -1;
}
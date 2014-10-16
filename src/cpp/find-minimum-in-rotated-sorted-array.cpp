/**
* Find Minimum in Rotated Sorted Array
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* Find the minimum element.
* You may assume no duplicate exists in the array.
* Solution: Think carefully
*/

class Solution {
public:
	int findMin(vector<int> &num);
	int findMin(vector<int> &num, int start, int end);
};
 
int Solution::findMin(vector<int> &num, int start, int end){
	if (start > end)
    	return INT_MAX;
	else if (start == end)
    	return num[start];
	else if (start + 1 == end)
    	return min (num[start], num[end]);
	if (num[start] < num[end]) // not rotated
    	return num[start];
	int middle = (start + end) / 2;
	if (num[middle] < num[start])
    	return findMin(num, start+1, middle);
	return findMin(num, middle+1, end);
}
 
int Solution::findMin(vector<int> &num){
	int n = num.size();
	if (n<=0) return INT_MAX;
	return findMin(num, 0, n-1);
}

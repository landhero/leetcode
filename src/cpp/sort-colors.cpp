/**
* Sort Colors
* Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, 
* 	with the colors in the order red, white and blue.
* Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
* Solution: Keep A[0..k] to be 0, 0, ..., 1, 1.
*/

class Solution {
public:
    void sortColors(int A[], int n);
};

void Solution::sortColors(int A[], int n){
	int i=0, j=n-1;
	for (int k=i; k<=j; k++){
		while (A[k]==2 && k<j)
			swap(A[k], A[j--]);
		if (A[k]==0)
			swap(A[k], A[i++]);
	}
}

/**
* Single Number II
* Given an array of integers, every element appears three times except for one. Find that single one.
* Solution: use three number to record bits
*/

class Solution {
public:
    int singleNumber(int A[], int n);
};

int Solution::singleNumber(int A[], int n){
	int bits_3 = 0, bits_2 = 0, bits_1 = 0;
	for (int i=0; i<n; i++){
		bits_3 = bits_3 & ~A[i] | bits_2 & A[i];
		bits_2 = bits_1 & A[i] | bits_2 & ~A[i];
		bits_1 = bits_1 & ~A[i] | A[i] & ~bits_3 & ~bits_2;
	}
	return bits_1;
}

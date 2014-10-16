/**
 * Maximum Product Subarray
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product. 
 * Solution: Record max positive product and min negative product
 */

class Solution {
public:
	int maxProduct(int A[], int n);
};

int Solution::maxProduct(int A[], int n){
	int maxPos = 0;
	int minNeg = 0;
	int maxProduct = A[0]; // n>0
	for (int i = 0; i<n; i++){
		if (A[i]>0){
			maxPos = A[i] * (maxPos == 0 ? 1 : maxPos);
			minNeg = A[i] * minNeg;
		}
		else if (A[i]<0){
			int tmp = A[i] * minNeg;
			minNeg = A[i] * (maxPos == 0 ? 1 : maxPos);
			maxPos = tmp;
		}
		else {
			maxPos = 0;
			minNeg = 0;
		}
		if (maxPos>0)
			maxProduct = max(maxProduct, maxPos);
		else maxProduct = max(maxProduct, A[i]);
	}
	return maxProduct;
}

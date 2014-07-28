/**
* @author Hansheng Zhang
*/
class Solution {
public:
	int firstMissingPositive(int A[], int n);
};

int Solution::firstMissingPositive(int A[], int n){
	for (int i = 0; i < n; i++){
		if (A[i]>n || A[i] <= 0)
			A[i] = 0;
	}
	for (int i = 0; i < n; i++){
		if (A[i] <= 0)
			continue;
		int j = A[i] - 1; //set A[A[i]-1] to -1
		if (A[j]>0 && A[ A[j]-1 ] != -1){ // A[j] has not been visited yet, A[j] -> A[i]
			A[i] = A[j];
			i--; // consider A[i] again;
		}
		else A[i] = 0;
		A[j] = -1;
	}
	int rlt = 0;
	while (rlt < n && A[rlt] == -1)
		rlt++;
	return rlt + 1;
}

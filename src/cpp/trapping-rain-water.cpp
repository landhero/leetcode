/**
* double pointer.
* @author Hansheng Zhang
*/
class Solution {
public:
	int trap(int A[], int n) {
		int left = 0, right = n - 1, rlt = 0;
		int ensured_height = 0;
		while (left <= right){
			if (A[left] <= A[right]){
				ensured_height = max(A[left], ensured_height);
				rlt += ensured_height - A[left++];
			}
			else{
				ensured_height = max(A[right], ensured_height);
				rlt += ensured_height - A[right--];
			}
		}
		return rlt;
	}
};

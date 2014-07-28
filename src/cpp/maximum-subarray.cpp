/**
* @author Hansheng Zhang
*/

class Solution {
public:
  int maxSubArray(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (n<=0)
      return 0;
    int maxSum = -2000000000;
    int b = maxSum, i;
    for (i=0; i<n; i++){
      if (b<0)
        b = A[i];
      else b += A[i];
      if (b>maxSum)
        maxSum = b;
    }
    return maxSum;
  }
};
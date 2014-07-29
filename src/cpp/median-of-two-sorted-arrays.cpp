/**
* @author Hansheng Zhang
*/

class Solution {
public:
    int findKth(int A[], int m, int B[], int n, int k);
    double findMedianSortedArrays(int A[], int m, int B[], int n);
};

int Solution::findKth(int A[], int m, int B[], int n, int k){
    if (m>n)
        return findKth(B, n, A, m, k);
    if (m==0)
        return B[k-1];
    if (k==1)
        return min(A[0], B[0]);
    int a = min(k/2, m);
    int b = k - a;
    if (A[a-1] == B[b-1])
        return A[a-1];
    if (A[a-1] < B[b-1])
        return findKth(A+a, m-a, B, n, k-a);
    return findKth(A, m, B+b, n-b, k-b);
}

double Solution::findMedianSortedArrays(int A[], int m, int B[], int n){
    int total = m+n;
    if (total % 2 == 1)
        return findKth(A, m, B, n, total/2 + 1);
    return (double)(findKth(A, m, B, n, total/2) +findKth(A, m, B, n, total/2 +1 ) )/2.0; 
}

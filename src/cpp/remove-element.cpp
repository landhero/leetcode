/**
@ author Hansheng Zhang
*/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        for (int i=0; i<n; i++){
            while (n>0&&A[n-1]==elem){
                n--;
            }
            if (i>=n){
                break;
            }
            if (A[i]==elem){
                A[i] = A[n-1];
                n--;
            }
        }
        return n;
    }
};

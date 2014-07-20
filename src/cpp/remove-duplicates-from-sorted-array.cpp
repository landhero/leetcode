/**
* @author Hansheng Zhang
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n<=1)
            return n;
        int last = 1;
        for (int i=1; i<n; i++){
            if (A[i]!=A[i-1])
                A[last++] = A[i];
        }
        return last;
    }
};
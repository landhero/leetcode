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
            if (last<2 || A[last-1] != A[i] || A[last-2] != A[i])
                A[last++] = A[i];
        }
        return last;
    }
};
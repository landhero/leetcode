/**
* @author Hansheng Zhang
*/
class Solution {
public:
    void sortColors(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int i =0 ,j = n-1;
        while (i<n && A[i]==0)
            i++;
        while (j>=0 && A[j]==2)
            j--;
        int tmp;
        for (int k=i; k<=j; k++){
            if (A[k]==0){
                A[k]= A[i];
                A[i] = 0;
                while (i<n && A[i]==0)
                    i++;
                k = i-1;
                continue;
            }
            if (A[k]==2){
                A[k] = A[j];
                A[j] = 2;
                while (j>=0 && A[j]==2)
                    j--;
                k--;
                continue;
            }
        }
        return;
    }
};
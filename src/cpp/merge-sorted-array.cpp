/**
* @author Hansheng Zhang (http://zhanghs.com)
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i, j;
        if (m<=0){
            for(i=0; i<n; i++)
                A[i] = B[i];
            return;
        }
        int * tags = new int[m];
        j = 0;
        for (i=0; i<m; i++){
            if (i==0)
                tags[i] = 0;
            else tags[i] = tags[i-1];
            while(j<n && B[j]<A[i]){
                tags[i]++;
                j++;
            }
        }
        int k;
        k = m+n-1;
        j = n-1;
        for (i=m-1; i>=0; i--){
            while(i+tags[i]<k)
                A[k--] = B[j--];
            if (i+tags[i]==k)
                A[k--] = A[i];
        }
        for (i=0; i<tags[0]; i++)
            A[i] = B[i];
        delete []tags;
    }
};

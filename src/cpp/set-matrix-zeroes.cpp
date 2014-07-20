/**
* Delay the modification
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (matrix.size()<=0 || matrix[0].size()<=0)
            return;
        int i, j, m=matrix.size(),n=matrix[0].size();
        bool lastZero = false, curZero = false;
        for (i=0; i<m; i++){
            curZero = false;
            for (j=0; j<n; j++){
                if (matrix[i][j]==0){
                    for (int k=i-1; k>=0; k--)
                        matrix[k][j] = 0;
                    curZero = true;
                }
                else if (i>0 && matrix[i-1][j]==0)
                    matrix[i][j] = 0;
            }
            if (i>0 && lastZero){
                for (j=0; j<n; j++)
                    matrix[i-1][j] = 0;
            }
            lastZero = curZero;
        }
        if (lastZero){
            for (j=0; j<n; j++)
                matrix[m-1][j] =0;
        }
        return;
    }
};
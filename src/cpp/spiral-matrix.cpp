/**
* @author Hansheng Zhang 
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> rlt;
        int m =matrix.size();
        if (m<=0)
            return rlt;
        int n = matrix[0].size();
        if (n<=0)
            return rlt;
        int flag[4] = {0, m-1, 0, n-1};
        int direction = 0; //left 2 right;
        int i = 0;
        while (true){
            int j = 2 - 2 * (direction%2); //j=0 or j=2
            if (flag[j]>flag[j+1])
                break;
            int start = flag[j]*(1-direction/2) + flag[j+1]*(direction/2); // start of iteration
            int delta = 1 - direction/2 - direction/2;
            for (i=start; i<=flag[j+1] && i>=flag[j]; i+=delta){
                int rowIndex = i*(direction%2)+ flag[0]*(((direction+3)%4)/3) + flag[1]*(((direction+1)%4)/3);
                int colIndex = i*(1-direction%2)+flag[3]*(((direction+2)%4)/3) + flag[2]*(direction/3);
                rlt.push_back(matrix[rowIndex][colIndex]);
            }
            int index = 2*(direction%2) + ((direction+1)%4)/2;
            flag[index] = flag[index] - ((direction+1)%4)/2 + ((direction+3)%4)/2;
            direction = (direction+1)%4;
        }
        return rlt;
    }
};
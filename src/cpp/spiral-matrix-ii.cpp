/**
* @author Hansheng Zhang
*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > matrix;
        if (n<=0)
            return matrix;
        int flag[4] = {0, n-1, 0, n-1};
        int direction = 0; //left 2 right;
        int i, j;
        for (i=0; i<n; i++){
            vector<int> vi;
            for (j=0; j<n; j++)
                vi.push_back(1);
            matrix.push_back(vi);
        }
        int t = 1;
        while (true){
            j = 2 - 2 * (direction%2); //j=0 or j=2
            if (flag[j]>flag[j+1])
                break;
            int start = flag[j]*(1-direction/2) + flag[j+1]*(direction/2); // start of iteration
            int delta = 1 - direction/2 - direction/2;
            for (i=start; i<=flag[j+1] && i>=flag[j]; i+=delta){
                int rowIndex = i*(direction%2)+ flag[0]*(((direction+3)%4)/3) + flag[1]*(((direction+1)%4)/3);
                int colIndex = i*(1-direction%2)+flag[3]*(((direction+2)%4)/3) + flag[2]*(direction/3);
                matrix[rowIndex][colIndex]=t++;
            }
            int index = 2*(direction%2) + ((direction+1)%4)/2;
            flag[index] = flag[index] - ((direction+1)%4)/2 + ((direction+3)%4)/2;
            direction = (direction+1)%4;
        }
        return matrix;
    }
};
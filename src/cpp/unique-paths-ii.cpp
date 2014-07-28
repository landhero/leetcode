/**
* @author Hansheng Zhang
*/
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
			return 0;
		int  m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		int * f = new int[n];
		if (obstacleGrid[0][0]==1)
		    f[0] = 0;
		else f[0] = 1;
		for (int i = 1; i<n; i++){
			if (obstacleGrid[0][i]==1)
				f[i] = 0;
			else f[i] = f[i-1];
		}
		for (int i = 1; i < m; i++){
			if (obstacleGrid[i][0] == 1)
				f[0] = 0;
			for (int j = 1; j < n; j++){
				if (obstacleGrid[i][j] == 1)
					f[j] = 0;
				else 
					f[j] += f[j - 1];
			}
		}
		int rlt = f[n - 1];
		delete[]f;
		return rlt;
	}
};

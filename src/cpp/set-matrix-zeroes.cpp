/**
* Set Matrix Zeros
* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
* Solution: use the first row as flags
*/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix);
};

void Solution::setZeroes(vector<vector<int> > &matrix){
	if (matrix.size()<=0 || matrix[0].size()<=0)
		return;
	int m = matrix.size(), n=matrix[0].size();
	bool zero_first_row = false;
	for (int i=0; i<n; i++){	// Check the first row
		if (matrix[0][i]==0){
			zero_first_row = true;
			break;
		}
	}
	for (int i=1; i<m; i++){	// Check and set other rows
		bool has_zero = false;
		for (int j=0; j<n; j++){
			if (matrix[i][j]==0){
				matrix[0][j] = 0;
				has_zero = true;
			}
		}
		if (has_zero)
			for (int j=0; j<n; j++) matrix[i][j]=0;
	}
	for (int i=0; i<n; i++){ // Set columns
		if (matrix[0][i]!=0)
			continue;
		for (int j=1; j<m; j++)
			matrix[j][i]=0;
	}
	if (zero_first_row)		// Set first row
		for (int i=0; i<n; i++) matrix[0][i] = 0;
}

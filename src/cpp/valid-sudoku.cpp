/**
* @author Hansheng Zhang
*/
class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		bool a[9][9];
		bool b[9][9];
		bool ct[9][9];
		if (board.size() != 9 || board[0].size() != 9)
			return false;
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				a[i][j] = false;
				b[i][j] = false;
				ct[i][j] = false;
			}
		}
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				char c = board[i][j];
				if (c == '.')
					continue;
				else if (c < '1' || c>'9')
					return false;
				int index = c - '1';
				if (a[i][index])
					return false;
				a[i][index] = true;
				if (b[j][index])
					return false;
				b[j][index] = true;
				int cIndex = 3*(i/3) + j/3;
				if (ct[cIndex][index])
					return false;
				ct[cIndex][index] = true;
			}
		}
		return true;
	}
};

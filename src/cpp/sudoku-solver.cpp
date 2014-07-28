/**
* easy to use search
* @author Hansheng Zhang
*/
class Solution {
public:
    bool solveSudoku(vector<vector<char> > & board, vector<vector<vector<bool> > > & flag, int x, int y){
	bool wEnd = (x == 8 && y == 8) ? true: false;
	int nextX = y<8? x: x+1;
	int nextY = y<8? y+1: 0;
	if (board[x][y]!='.'){
	    if (wEnd)
		return true;
	    else return (solveSudoku(board, flag, nextX, nextY));
	}
	for (int i=0; i<9; i++){
	    int i1 = x;
	    int i2 = y;
	    int i3 = (x/3)*3 + y/3;
	    if (flag[0][i1][i] || flag[1][i2][i] || flag[2][i3][i])
		continue;
	    board[x][y] = '1'+ i;
	    flag[0][i1][i] = flag[1][i2][i] = flag[2][i3][i] = true;
	    if (wEnd)
		return true;
	    else if (solveSudoku(board, flag, nextX, nextY))
		return true;
	    flag[0][i1][i] = flag[1][i2][i] = flag[2][i3][i] = false;
	    board[x][y] = '.';
	}
	return false;
    }
    void solveSudoku(vector<vector<char> > &board) {
	vector<bool> vb(9,false);
	vector<vector<bool> > vvb (9, vb);
	vector<vector<vector<bool> > > flag(3, vvb);
	for (int i=0; i<9; i++)
	    for (int j=0; j<9; j++){
		int i1 = i;
		int i2 = j;
		int i3 = (i/3)*3 + j/3;
		if (board[i][j] != '.'){
		    int index = board[i][j] - '1';
		    flag[0][i1][index] = flag[1][i2][index] = flag[2][i3][index] = true;
		}
	    }
	solveSudoku(board, flag, 0, 0);
    }
};

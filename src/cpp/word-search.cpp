/**
* @author Hansheng Zhang
*/
class Solution {
public:
	int m, n;
	bool search(vector<vector<char> > &board, string & word, int x, int y, vector<vector<bool> >&flag, int off){
		if (off == word.size()) return true;
		int dx[4] = { -1, 0, 1, 0 };
		int dy[4] = { 0, -1, 0, 1 };
		for (int i = 0; i < 4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && xx < m && yy >= 0 && yy < n && board[xx][yy] == word[off] && !flag[xx][yy]){
				flag[xx][yy] = true;
				if (search(board, word, xx, yy, flag, off + 1))
					return true;
				flag[xx][yy] = false;
			}
		}
		return false;
	}
	bool exist(vector<vector<char> > &board, string word) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (board.size() == 0 || board[0].size() == 0)
			return false;
		m = board.size(), n = board[0].size();
		int len = word.length();
		if (len <= 0)
			return true;
		vector<vector<bool> >flag = vector<vector<bool> >(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (board[i][j] != word[0])
					continue;
				flag[i][j] = true;
				if (search(board, word, i, j, flag, 1)){
					return true;
				}
				flag[i][j] = false;
			}
		}
		return false;
	}
};

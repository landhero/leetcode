/*
key insight is find all O's connected to O's on the bound
@author: Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    void solve(vector<vector<char>>&);
};
// set  O to Q if it is connected to the bound
void setQs(int i, int j, int m, int n, vector<vector<char>> &board){
    int deltax[4]={1,0,-1,0}; //different directions
    int deltay[4]={0,1,0,-1};
    board[i][j] = 'Q';
    stack<int>xx;
    stack<int>yy;
    xx.push(i);
    yy.push(j);
    while (!xx.empty()){
        int x = xx.top();
        int y = yy.top();
        xx.pop();
        yy.pop();
        for (int k=0; k<4; k++){
            int tx = x + deltax[k];
            int ty = y + deltay[k];
            if (tx>=0&&tx<m&&ty>=0&&ty<n&&board[tx][ty]=='O'){
                board[tx][ty]='Q';
                xx.push(tx);
                yy.push(ty);
            }
        }
    }
}
void Solution::solve(vector<vector<char>> &board) {
    int m = board.size();
    if (m<=1)
        return;
    int n = board[0].size();
    if (n<=1)
        return;
    //call setQs from the bound
    for (int i=0; i<n; i++){
        if (board[0][i]=='O')
            setQs(0,i,m,n,board);
        if (board[m-1][i]=='O')
            setQs(m-1,i,m,n,board);
    }
    for (int i=1; i<m-1; i++){
        if (board[i][0]=='O')
            setQs(i,0,m,n,board);
        if (board[i][n-1]=='O')
            setQs(i,n-1,m,n,board);
    }
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (board[i][j] == 'Q')
                board[i][j] = 'O';
            else board[i][j] = 'X';
}
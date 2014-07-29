/**
* @author Hansheng Zhang
*/
class Solution {
public:
  void dfs(int n, int before, int left, string cur, vector<string> &rlt){
    int right = before - left;
    if (left<n){
      dfs(n, before+1, left+1, cur+"(", rlt);
    }
    if (right<left){
      if (before == 2*n-1)
        rlt.push_back(cur+")");
      else dfs(n,before+1, left, cur+")", rlt);
    }
  }
  vector<string> generateParenthesis(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<string> rlt;
    dfs(n, 0, 0, "", rlt);
    return rlt;
  }
};
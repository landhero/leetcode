/**
* @author Hansheng Zhang
*/
class Solution {
public:
  string tables[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  void dfs(vector<string> & result, int n, int i, string & digits, string cur){
    string str = tables[digits.at(i)-'2'];
    int len = str.length();
    for (int j=0; j<len; j++){
      string next = cur+str.at(j);
      if (i==n-1)
        result.push_back(next);
      else dfs(result,n,i+1,digits,next);
    }
  }
  vector<string> letterCombinations(string digits) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<string> rlt;
    int len = digits.length();
    if (len<=0){
      rlt.push_back("");
      return rlt;
    }
    dfs(rlt, len, 0, digits,"");
    return rlt;
  }
};

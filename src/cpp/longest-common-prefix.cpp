/**
* @author Hansheng Zhang
*/
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (strs.size()<=0)
      return "";
    vector<string>::iterator si = strs.begin();
    string ans = *si;
    for (si++; si!=strs.end() && ans.length()>0;si++){
      string cur = * si;
      int i;
      for (i=0; i<ans.length() && i<cur.length(); i++){
        if (cur.at(i) != ans.at(i))
          break;
      }
      ans = ans.substr(0,i);
    }
    return ans;
  }
};

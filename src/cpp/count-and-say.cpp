/**
* @author Hansheng Zhang
*/
class Solution {
public:
  string genNext(string cur){
    string rlt = "";
    char t[20];
    int length = cur.length();
    int i = 0;
    char c = cur.at(0);
    int len = 0;
    while(i<length){
      while (i<length && cur.at(i)==c){
        len++;
        i++;
      }
      sprintf(t, "%d%c", len, c);
      rlt += t;
      len =0;
      if (i<length){
        c = cur.at(i);
      }
    }
    return rlt;
  }
  string countAndSay(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    string rlt = "1";
    while (--n > 0){
      rlt = genNext(rlt);
    }
    return rlt;
  }
};

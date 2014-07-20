/**
* @author Hansheng Zhang (http://zhanghs.com)
*/

class Solution {
public:
  int numDecodings(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int len = s.length();
    if (len ==0 || (len>=1&&s.at(0)=='0'))
      return 0;
    else if (len==1)
      return 1;
    int lastTwo = 1; int lastOne = 1;
    int cur;
    for (int i=1; i<len; i++){
      cur = 0;
      if (s.at(i)!='0')
        cur = lastOne;
      if (s.at(i-1)=='1' || (s.at(i-1)=='2'&&s.at(i)<='6'))
        cur += lastTwo;
      lastTwo = lastOne;
      lastOne = cur;
    }
    return cur;
  }
};
/**
* Dynamic Programming. Greed not work
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function    
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();
    if (len1+len2 != len3)
      return false;
    if (len1==0)
      return s2==s3;
    if (len2==0)
      return s1==s3;
    bool ** flag = new bool *[len1+1];
    int i, j;
    for (i=0; i<=len1; i++){
      flag[i] = new bool[len2+1];
      for (j=0; j<=len2; j++)
        flag[i][j] = false;
    }
    flag[0][0] = true;
    for (i=0; i<=len1; i++){
      for (j=0; j<=len2; j++){
        if (i>0 && s1[i-1]==s3[i+j-1] && flag[i-1][j])
          flag[i][j] = true;
        if (j>0 && s2[j-1]==s3[i+j-1] && flag[i][j-1])
          flag[i][j] = true;
      }
    }
    bool rlt = flag[len1][len2];
    for (i=0; i<=len1; i++)
      delete[] flag[i];
    delete []flag;
    return rlt;
  }
};
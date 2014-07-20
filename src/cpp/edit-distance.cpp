/**
* dp
* @author Hansheng Zhang
*/
class Solution {
public:
  int minDistance(string word1, string word2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int len1 = word1.length();
    int len2 = word2.length();
    int i, j;
    if (len1==0 || len2==0)
      return len1>len2? len1:len2;
    int * last = new int[len2+1];
    int * cur = new int[len2+1];
    for (j=0; j<=len2; j++){
      last[j] = j;
      cur[j] = j;
    }
    for (i=1; i<=len1; i++){
      cur[0] = i;
      for (j=1; j<=len2; j++){
        int min = 1000000000;
        if (word1.at(i-1) == word2.at(j-1)){
          if (min >last[j-1])
            min = last[j-1];
        }
        if (min >last[j]+1)
          min = last[j]+1;
        if (min > cur[j-1]+1)
          min = cur[j-1] + 1;
        if (min > last[j-1]+1)
          min = last[j-1]+1;
        cur[j] = min;
      }
      for (j=0; j<=len2; j++)
        last[j] = cur[j];
    }
    int rlt = cur[len2];
    delete []last;
    delete []cur;
    return rlt;
  }
};
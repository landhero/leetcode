/**
* @author Hansheng Zhang (http://zhanghs.com)
*/

class Solution {
public:
  string addBinary(string a, string b) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int tlen, alen, blen;
    string c;
    alen = a.length();
    blen = b.length();
    if (alen<blen){
      c = a;
      a = b;
      b = c;
      tlen = alen;
      alen = blen;
      blen = tlen;
    }
    int i = alen - 1;
    int j = blen - 1;
    for (;i>=0; i--,j--){
      if (j>=0)
        a[i] += b[j]-'0';
      if (a[i]>'1'){
        a[i] -= 2;
        if (i>0)
          a[i-1]++;
        else a = "1"+a;
      }
    }
    return a;
  }
};
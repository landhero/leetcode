/**
* @author Hansheng Zhang
*/
class Solution {
public:
  char *strStr(char *haystack, char *needle) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int hayLen = strlen(haystack);
    int neeLen = strlen(needle);
    for (int i=0; i+neeLen<=hayLen; i++, haystack++){
      if (haystack == 0)
        break;
      int j = 0;
      for (j=0; j<neeLen && needle[j] == haystack[j]; j++);
      if (j==neeLen)
        return haystack;
    }
    return NULL;
  }
};

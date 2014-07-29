/**
* @author Hansheng Zhang
*/
class Solution {
public:
    int atoi(const char *str) {
        while (*str==' ')
			str++;
		int sign = 1;
		if (*str=='+')
			str++;
		else if (*str=='-'){
			str++;
			sign = -1;
		}
		unsigned rlt=0;
		unsigned maxL = INT_MAX;
		if (sign==-1)
			maxL += 1;
		while (*str<='9' && *str>='0'){
			unsigned int off = *str-'0';
			unsigned int t = maxL - off;
			if (t/10 < rlt){
				if (sign==1)
					return INT_MAX;
				return INT_MIN;
			}
			rlt = rlt * 10 + off;
			str++;
		}
		if (sign==1)
			return rlt;
		return (-1) * rlt;
    }
};

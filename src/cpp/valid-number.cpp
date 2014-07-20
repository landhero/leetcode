/**
* @author Hansheng Zhang
*/
class Solution {
public:
	bool isInt(const char * s, int start, int end){
		if (end < start)
			return false;
		if  (start<=end && (s[start] == '+' || s[start] == '-'))
			start++;
		if (end<start)
			return false;
		for (int i = start; i <= end; i++){
			if (s[i]<'0' || s[i]>'9')
				return false;
		}
		return true;
	}
	bool isDouble(const char * s, int start, int end){
		if (start <= end && (s[start] == '+' || s[start] == '-'))
			start++;
		for (int i = start; i <= end; i++){
			if (s[i] == '.'){
				if (i + 1 <= end && (s[i + 1] == '-' || s[i + 1] == '+'))
					return false;
				if (i == start)
					return isInt(s, i + 1, end);
				else if (i == end)
					return isInt(s, start, i-1);
				else return isInt(s, start, i - 1) && isInt(s, i + 1, end);
			}
		}
		return isInt(s, start, end);
	}
	bool isNumber(const char *s) {
		// Note: The Solution object is instantiated only once and is reused by each test case.
		int len = strlen(s);
		int start = 0, end = len - 1;
		while (start <= end && (s[start] == ' '))
			start++;
		while (end >= start && s[end] == ' ')
			end--;
		for (int i = start; i <= end; i++){
			if (s[i] == 'e' || s[i] == 'E'){
				return isDouble(s, start, i - 1) && isInt(s, i + 1, end);
			}
		}
		return isDouble(s, start , end);
	}
};
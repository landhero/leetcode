/**
* @author Hansheng Zhang
*/
class Solution {
public:
	//reference: http://www.cnblogs.com/remlostime/archive/2012/11/16/2774077.html
	string minWindow(string S, string T) {
		int flag[128];
		memset(flag, 0, sizeof(flag));
		int lenT = T.length();
		if (lenT <= 0)
			return "";
		int n=0;
		for (int i = 0; i < lenT; i++){
			int index = (int)(T.at(i));
			if (flag[index] == 0)
				n++;
			flag[index]++;
		}
		int alFlag[128];
		memset(alFlag, 0, sizeof(alFlag));
		int numAl = 0;
		const char * start = S.c_str();
		const int maxNum = 1000000000;
		int rltSize = maxNum;
		const char* startPos = NULL;
		const char * end = start;
		while (*end != '\0'){
			int index = (int)(*end);
			alFlag[index]++;
			if (alFlag[index] == flag[index])
				numAl++;
			if (numAl == n){
				while (start <= end){
					if (rltSize > end - start + 1){
						rltSize = end - start + 1;
						startPos = start;
					}
					int ind = (int)(*start);
					alFlag[ind]--;
					if (flag[ind] !=0 && alFlag[ind] == flag[ind]-1)
						numAl--;
					if (numAl < n){
						start++;
						break;
					}
					start++;
				}
			}
			end++;
		}
		if (startPos == NULL)
			return "";
		string rlt="";
		while (rltSize-- > 0)
			rlt += *(startPos++);
		return rlt;
	}
};

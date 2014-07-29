/**
* @author Hansheng Zhang
*/
class Solution {
public:
    string convert(string s, int nRows) {
	int len = s.length();
	if (nRows<=1 || len<=2)
	    return s;
	string * strs = new string[nRows];
	for (int i=0; i<len; i++){
	    int offset = i % (2*nRows-2);
	    if (offset<nRows)
		strs[offset] += s.at(i);
	    else strs[nRows-1 - (offset-nRows)-1]+=s.at(i);
	}
	string rlt="";
	for (int i=0; i<nRows; i++)
	    rlt += strs[i];
	return rlt;
    }
};

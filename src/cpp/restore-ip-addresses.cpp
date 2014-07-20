/**
* easy. don't make mistakes
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    bool isValid(string &s, int start, int end){
	int len = end-start+1;
	if (len<=0 || len>3)
	    return false;
	if (len>1 && s.at(start)=='0')
	    return false;
	int _val  = atoi(s.substr(start,len).c_str());
	if (_val>=0 && _val<=255)
	    return true;
	return false;
    }
    vector<string> restoreTwo(string & s, int start, int end){
	int len = end-start+1;
	vector<string> rlt;
	if (len<=0 || len>6)
	    return rlt;
	vector <string> rlts;
	for (int i=start;i<end; i++){
	    if (isValid(s,start, i)&& isValid(s,i+1,end))
		rlts.push_back(s.substr(start, i-start+1)+"."+s.substr(i+1, end-i));
	}
	return rlts;
    }
    vector<string> restoreIpAddresses(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
	int len = s.length();
	vector<string> rlts;
	for (int i=0; i<len-1; i++){
	    if (i+1<2 || len-i-1<2 || i+1>6 || len-i-1>6)
		continue;
	    vector<string> left = restoreTwo(s,0,i);
	    vector<string> right = restoreTwo(s,i+1,len-1);
	    int m = left.size();
	    int n = right.size();
	    if (m<=0 || n<=0)
		continue;
	    for (int p=0; p<m; p++)
		for (int q=0; q<n; q++){
		    rlts.push_back(left[p]+"."+right[q]);
		    //cout << "[" << left[p]+"."+right[q] << "]" << endl;
		}
	}
	return rlts;
    }    
};

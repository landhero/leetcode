/**
* Word Break
* Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
* Solution: dynamic programming
*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict);
};

bool Solution::wordBreak(string s, unordered_set<string> &dict){
	int n = s.length();
	if (n<=0) return true;
	vector<bool> flag(n+1, false);
	flag[0] = true;
	for (int i =0; i<n; i++){
		if ( !flag[i] ) continue;
		for (int j=i+1; j<=n; j++){
			if (dict.find(s.substr(i,j-i))!=dict.end())
				flag[j] = true;
		}
	}
	return flag[n];
}

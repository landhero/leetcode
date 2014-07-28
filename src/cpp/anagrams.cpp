/**
* convert string
* @author Hansheng Zhang
*/

class Solution {
public:
	vector<string> anagrams(vector<string> &strs);
};

string convertString(string &s){
	vector<int> flags(26, 0);
	for (int i = 0; i < s.length(); i++){
		flags[s[i] - 'a']++;
	}
	string rlt;
	for (int i = 0; i < 26; i++){
		if (flags[i] <= 0)
			continue;
		else if (flags[i] == 1)
			rlt += ('a' + i);
		else {
			rlt += ('a' + i);
			char buffer[100];
			sprintf(buffer, "%d", flags[i]);
			rlt += buffer;
		}
	}
	return rlt;
}

vector<string> Solution::anagrams(vector<string> & strs){
	vector<string> rlt;
	if (strs.size() <= 0)
		return rlt;
	unordered_map<string, vector<string> > flags;
	for (auto itr = strs.begin(); itr != strs.end(); itr++){
		string s = convertString(*itr);
		if (flags.find(s) != flags.end())
			flags[s].push_back(*itr);
		else flags[s] = vector<string>(1, *itr);
	}
	for (auto itr : flags){
		if (itr.second.size()>1)
			rlt.insert(rlt.end(), itr.second.begin(), itr.second.end());
	}
	return rlt;
}

/*
breadth first search
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    int ladderLength(string, string, unordered_set<string> &);
};
typedef unordered_map<string, int> MyHashMap;
int Solution::ladderLength(string start, string end, unordered_set<string> &dict) {
	if (start == end)
		return 1;
	if (start.length() != end.length())
		return 0;
	queue<string> qs;
	int len = start.length();
	qs.push(start);
	MyHashMap mp;
	mp[start] = 1;
	while (!qs.empty()){
		string cur = qs.front();
		qs.pop();
		for (int i = 0; i < len; i++){
			for (int j = 0; j < 26; j++){
				string tmp = cur;
				tmp[i] = 'a'+j;
				if (tmp == end)
					return mp[cur]+1;
				if (dict.find(tmp) == dict.end() || mp.find(tmp)!=mp.end())
					continue;
				qs.push(tmp);
				mp[tmp] = mp[cur] + 1;
			}
		}
	}
	return 0;
}

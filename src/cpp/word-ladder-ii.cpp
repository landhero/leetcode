/*
breadth first search. store previous strings for a given string with the minimal distance to the start
depth first search to find all paths
reverse the results of depth first search
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict);
};
typedef unordered_map<string, unsigned> MyHashMap;
typedef unordered_map<string, vector<string>> SVMap;
vector<vector<string>> Solution::findLadders(string start, string end, unordered_set<string> &dict) {
	unsigned rltLen = INT_MAX; // rltLen, used for pruning
	vector<vector<string>> rlt; // store the rlt
	if (start.length() != end.length())
		return rlt;
	if (start == end)
		rltLen = 1;
	int len = start.length();
	MyHashMap depMap; //store the distance
	SVMap prevMap; //store the previously visited strings
	prevMap[start] = vector<string>();
	depMap[start] = 1;
	queue<string> qs; //to do bfs
	qs.push(start);
	while (!qs.empty()){
		string cur = qs.front();
		qs.pop();
		unsigned curLen = depMap[cur];
		if (curLen >= rltLen) //the next gener
			continue;
		for (int i = 0; i < len; i++){
			for (int j = 0; j < 26; j++){
				string tmp = cur;
				tmp[i] = 'a' + j;
				if (tmp == cur) //the same string will not be visited
					continue;
				if (tmp == end){
					rltLen = depMap[cur]+1;
					prevMap[end].push_back(cur);
					continue;
				}
				if (dict.find(tmp) == dict.end()) //test whether tmp is in the dict
					continue;
				if (curLen+1 >= rltLen) //tmp:curLen+1,so visiting tmp will not generate a required path
					continue;
				MyHashMap::iterator mhi = depMap.find(tmp);
				if (mhi!=depMap.end() && mhi->second <= curLen) //tmp is not visited or have the same distance
					continue;
				if (prevMap.find(tmp) == prevMap.end())
					prevMap[tmp] = vector<string>(1, cur);
				else prevMap[tmp].push_back(cur);
				if (mhi != depMap.end())
					continue; //string have been visited
				qs.push(tmp);
				depMap[tmp] = curLen+1;
			}
		}
	} // end bfs
	if (rltLen == INT_MAX) // cannot find a path
		return rlt;
	stack<vector<string> > svs; //dfs
	svs.push(vector<string>(1, end));
	while (!svs.empty()){
		vector<string> vs = svs.top();
		svs.pop();
		string last = *(vs.end() - 1);
		if (last == start){
			rlt.push_back(vs);
			continue;
		}
		for (auto iter = prevMap[last].begin(); iter != prevMap[last].end(); iter++){
			vector<string> tmpVect = vs;
			tmpVect.push_back(*iter);
			svs.push(tmpVect);
		}
	}
	//reverse the result
	for (auto iter = rlt.begin(); iter != rlt.end(); iter++){
		int size = iter->size();
		int j = size / 2;
		for (int i = 0; i < j; i++){
			string tmp = (*iter)[i]; 
			(*iter)[i] = (*iter)[size - i - 1];
			(*iter)[size - i - 1] = tmp;
		}
	}
	return rlt;
}

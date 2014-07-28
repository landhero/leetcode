/**
* brute force
* @author Hansheng Zhang
*/
class Solution {
public:
	typedef unordered_map<string,int> HashMap;
	bool canMatch(const char* head, const char * end, HashMap & flags, int l){
		if (head == end+1)
			return true;
		string s="";
		for (int i=0; i<l; i++)
			s+= *(head+i);
		HashMap::iterator hi = flags.find(s);
		if (hi==flags.end() || hi->second<=0)
			return false;
		flags[s]--;
		bool rlt = canMatch(head+l,end,flags,l);
		flags[s]++;
		return rlt;
	}
    vector<int> findSubstring(string S, vector<string> &L) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		vector<int> rlt;
		int n = L.size();
		if (n<=0)
			return rlt;
		int l = L[0].length();
		if (l<=0)
			return rlt;
		HashMap flags;
		for (int i=0; i<n; i++){
			if (flags.find(L[i]) == flags.end())
				flags[L[i]]=1;
			else flags[L[i]]++;
		}
		const char * head = S.c_str();
		for (int i=0; i+l*n<=S.length(); i++){
			if (canMatch(head+i, head+i+l*n-1, flags, l))
				rlt.push_back(i);
		}
		return rlt;
    }
};

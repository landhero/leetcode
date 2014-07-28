/**
* @author Hansheng Zhang
*/
class Solution {
public:
    void generateResults(vector<vector<string> > &rlts, int n, int index, vector<int>&cur, vector<bool>& flags){
		for (int i=0; i<n; i++){
			int j = n + index + i;
			int k = n + 2*n-1 + index-i + n-1;
			if (flags[i] || flags[j] || flags[k])
				continue;
			flags[i] = flags[j] = flags[k] = true;
			cur[index] = i;
			if (index==n-1){
				vector<string> rlt;
				for (int p=0; p<n; p++){
					string s="";
					for (int q=0; q<n; q++){
						if (cur[p]==q)
							s+='Q';
						else s+='.';
					}
					rlt.push_back(s);
				}
				rlts.push_back(rlt);
			} else generateResults(rlts, n, index+1, cur, flags);
			flags[i] = flags[j] = flags[k] = false;
		}
    }
	
    vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > rlts;
		if (n<=0)
			return rlts;
		vector<int> cur (n, 0);
		vector<bool> flags(n + 2*n-1 + 2*n-1, false);
		generateResults(rlts,n,0,cur,flags);
		return rlts;
    }
};

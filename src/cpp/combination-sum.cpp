/**
* @author Hansheng Zhang
*/

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target);
};

void dfs(vector<int> & candidates, int target, unordered_map<int, vector<vector<int> > > &flags){
	if (flags.find(target) != flags.end())
		return;
	vector<vector<int> > rlt;
	for (auto candidate: candidates){
		if (candidate <= target){
			int next_target = target - candidate;
			if (flags.find(next_target) == flags.end())
				dfs(candidates, next_target, flags);
			vector<vector<int> > & last_results = flags[next_target];
			for (unsigned i = 0; i < last_results.size(); ++i){
				vector <int> vi = last_results[i];
				if (!vi.empty() && *(vi.end() - 1)>candidate)
					continue;
				vi.push_back(candidate);
				rlt.push_back(vi);
			}
		}
	}
	flags[target] = rlt;
}

vector<vector<int> > Solution::combinationSum(vector<int> &candidates, int target){
	vector<vector<int> > rlt;
	sort(candidates.begin(), candidates.end());
	vector<int> unique_candidates;
	for (unsigned i = 0; i < candidates.size(); ++i){
		if (i>0 && candidates[i] == candidates[i - 1])
			continue;
		unique_candidates.push_back(candidates[i]);
	}
	unordered_map<int, vector<vector<int> > > flags;
	flags[0] = vector<vector<int>>(1, vector<int>());
	dfs(unique_candidates, target, flags);
	return flags[target];
}

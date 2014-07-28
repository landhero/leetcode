/**
* @author Hansheng Zhang
*/
class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target);
};
vector<vector<int> > Solution::combinationSum2(vector<int> &num, int target){
	sort(num.begin(), num.end());
	vector<vector<vector<int>  > > flags(target+1, vector<vector<int> >());
	flags[0].push_back(vector<int>());
	unsigned n = num.size();
	for (int i = 0; i < n; i++){
		int cnt = 1;
		while ((i + 1) < n && num[i + 1] == num[i]){
			++cnt;
			++i;
		}
		int candidate = num[i];
		while (cnt!=0){
			for (int j = target; j >= 0; --j){
				if (j - candidate*cnt < 0)
					break;
				vector<vector<int> > & last_results = flags[j-candidate*cnt];
				for (auto itr = last_results.begin(); itr != last_results.end(); itr++){
					vector<int> tmp = *itr;
					if (!tmp.empty() && tmp.back() == candidate)
						break;
					for (int k = 0; k < cnt; k++)
						tmp.push_back(candidate);
					flags[j].push_back(tmp);
				}
			}
			--cnt;
		}
	}
	return flags[target];
}

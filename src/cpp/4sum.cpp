/**
* @author Hansheng Zhang
*/

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target);
};
vector<vector<int> > Solution::fourSum(vector<int> &num, int target){
	vector<vector<int> > rlt;
	sort(num.begin(), num.end());
	int n = num.size();
	for (int i = 0; i < n; ++i){
		if (num[i] * 4 > target)
			break;
		if (i>0 && num[i] == num[i - 1])
			continue;
		for (int j = i+1; j < n; j++){
			if (num[i] + num[j] * 3> target)
				break;
			if (j > i + 1 && num[j] == num[j - 1])
				continue;
			int k = j + 1;
			int l = n - 1;
			int cur_target = target - num[i] - num[j];
			while (k < l){
				if (k>j + 1 && num[k] == num[k - 1])
					k++;
				else if (l < n - 1 && num[l] == num[l + 1])
					l--;
				else if (num[k] + num[l]>cur_target)
					l--;
				else if (num[k] + num[l] < cur_target)
					k++;
				else {
					vector<int> entry(4, 0);
					entry[0] = num[i]; entry[1] = num[j]; 
					entry[2] = num[k]; entry[3] = num[l];
					rlt.push_back(entry);
					k++; l--;
				}
			}
		}
	}
	return rlt;
}

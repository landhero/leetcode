/**
* @author Hansheng Zhang
*/

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target);
};

int Solution::threeSumClosest(vector<int> &num, int target){
	sort(num.begin(), num.end());
	int cur_dis = INT_MAX, rlt = 0;
	int n = num.size();
	for (int i = 0; i < n; i++){
		if (i>0 && num[i] == num[i - 1])
			continue;
		int j = i + 1, k = n - 1;
		while (j < k){
			if (j>i + 1 && num[j] == num[j - 1])
				j++;
			else if (k < n - 1 && num[k] == num[k + 1])
				k--;
			else {
				int cur_sum = num[i] + num[j] + num[k];
				if (cur_sum == target)
					return cur_sum;
				int dis = abs(cur_sum - target);
				if (dis < cur_dis){
					cur_dis = dis;
					rlt = cur_sum;
				}
				if (cur_sum < target)
					j++;
				else k--;
			}
		}
	}
	return rlt;
}

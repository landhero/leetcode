/**
* @author Hansheng Zhang
*/
class Solution {
public:
	void nextPermutation(vector<int> &num) {
		// Note: The Solution object is instantiated only once and is reused by each test case.
		int n = num.size();
		if (n <= 1)
			return;
		int i;
		for (i = n - 2; i >= 0; i--){
			if (num[i]<num[i + 1])
				break;
		}
		if (i < 0){
			sort(num.begin(), num.end());
			return;
		}
		int min = num[i + 1];
		int minIndex = i + 1;
		for (int j = i + 1 + 1; j<n; j++){
			if (num[j]>num[i] && num[j]<min){
				min = num[j];
				minIndex = j;
			}
		}
		int tmp = num[i];
		num[i] = num[minIndex];
		num[minIndex] = tmp;
		sort(&num[i + 1], &num[n]);
	}
};
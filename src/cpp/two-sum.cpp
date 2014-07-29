/**
* @author Hansheng Zhang
*/
struct ValueIndex{
	int value;
	int index;
	ValueIndex(int v, int i) :value(v), index(i){}
};
bool compare(ValueIndex a, ValueIndex b){
	return a.value < b.value;
}

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target);
};

vector<int> Solution::twoSum(vector<int> &numbers, int target){
	vector<ValueIndex> arr;
	int n = numbers.size();
	for (int i = 0; i < n; i++)
		arr.push_back(ValueIndex(numbers[i], i));
	sort(arr.begin(), arr.end(), compare);
	int i = 0, j = arr.size() - 1;
	while (i < j) {
		int sum = arr[i].value + arr[j].value;
		if (sum == target){
			int a = arr[i].index + 1;
			int b = arr[j].index + 1;
			if (a>b) swap(a, b);
			return vector<int>({ a, b });
		}
		if (sum < target)
			i++;
		else j--;
	}
	return vector<int>(-1,-1);
}

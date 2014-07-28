/**
* Greedy
* @author Hansheng Zhang
*/
class Solution {
public:
	int jump(int A[], int n);
};

int Solution::jump(int A[], int n){
	int step = 0;
	int start = 0, end = 0;
	while (true){
		if (end >= n - 1)
			return step;
		int next_end = end;
		for (int i = start; i <= end; i++)
			next_end = max(next_end, i+A[i]);
		if (next_end <= end)
			return -1;
		start = end + 1;
		end = next_end;
		step++;
	}
	return -1;
}

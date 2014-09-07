/**
* Largest Rectangle in Histogram
* Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
* Solution: calculate the area with s.top() as its minimal height
* Reference: http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height);
};

int Solution::largestRectangleArea(vector<int> &height){
	int rlt = 0;
	int n = height.size();
	stack<int> s;
	int i = 0;
	while (i<n || !s.empty()){
		if (i<n &&(s.empty() || height[i]>=height[s.top()])  ){
			s.push(i++);
			continue;
		}
		int t = s.top();
		s.pop();
		int width = s.empty() ? i:i-s.top()-1;
		int area = height[t]*width;
		if (area > rlt)
			rlt = area;
	}
	return rlt;
}

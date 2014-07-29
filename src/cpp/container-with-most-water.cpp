/*
* @author Hansheng Zhang
*/
class Solution {
public:
	int maxArea(vector<int>&); 
};
int Solution::maxArea(vector<int> &  height){
	int l = 0, r = height.size() - 1;
	int area = 0;
	while (l<r){
		int t = (r - l)*min(height[l], height[r]);
		if (t>area)
			area = t;
		if (height[l]<height[r])
			l++;
		else r--;
	}
	return area;
}

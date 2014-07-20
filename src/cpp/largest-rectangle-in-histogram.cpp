/**
 * reference: http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
 * @author Hansheng Zhang (http://zhanghs.com)
 */
class Solution {
public:
    int largestRectangleArea(vector<int> &);
};

int Solution::largestRectangleArea(vector<int> & height){
    int rlt = 0;
    int i = 0, n=height.size();
    stack<int> s;
    while (i<n){
        if (s.empty() || height[i]>=height[s.top()]){
            s.push(i++);
            continue;
        }
        int t = s.top();
        s.pop();
        int width = s.empty() ? i: i-s.top()-1;
        int area = height[t] * width;
        if ( area > rlt )
            rlt = area;
    }
    while (!s.empty()){
        int t = s.top();
        s.pop();
        int width = s.empty() ? n : n-s.top()-1;
        int area = width * height[t];
        if (area > rlt)
            rlt = area;
    }
    return rlt;
}

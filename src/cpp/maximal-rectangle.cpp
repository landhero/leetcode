/**
* using solution in largest rectangle in histogram
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &);
    int largestRectangleArea(vector<int> &);
};

int Solution::maximalRectangle(vector<vector<char> > &matrix){
    if (matrix.size()<=0 || matrix[0].size()<=0 )
        return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> row(n, 0);
    int rlt = 0;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++)
            if  (matrix[i][j] == '1')
                row[j] = row[j] + 1;
            else row[j] = 0;
        int cur_rlt = largestRectangleArea(row);
        if (cur_rlt > rlt)
            rlt = cur_rlt;
    }
    return rlt;
}

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

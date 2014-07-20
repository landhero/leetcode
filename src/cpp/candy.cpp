/**
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    int candy(vector<int> &ratings);
};
int Solution::candy(vector<int> &ratings){
    int n = ratings.size();
    if (n<=0)
        return 0;
    vector<int> rlt(n,1);
    for (int i=1; i<n; i++)
        if (ratings[i] > ratings[i-1])
            rlt[i] = rlt[i-1]+1;
    for (int i=n-2; i>=0; i--)
        if (ratings[i]>ratings[i+1] && rlt[i+1]>=rlt[i])
            rlt[i] = rlt[i+1] + 1;
    int sum = 0;
    for (int i=0; i<n; i++)
        sum += rlt[i];
    return sum;
}
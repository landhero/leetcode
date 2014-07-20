/*
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    int maxProfit(vector<int> &prices);
};
int Solution::maxProfit(vector<int> & prices){
    int curMin = INT_MAX;
    int profit = 0;
    for (auto itr = prices.begin(); itr!=prices.end(); itr++){
        profit = max(profit,*itr-curMin);
        curMin = min(curMin, *itr);
    }
    return profit;
}

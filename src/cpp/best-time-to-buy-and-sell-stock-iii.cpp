/*
use dynamic programming to reduce the runtime from O(n^2) to O(n)
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    int maxProfit(vector<int> &);
};
int Solution::maxProfit(vector<int> & prices){
    int n = prices.size();
    if (n<=0)
        return 0;
    int profit = 0;
    int prevMin = INT_MAX;
    int * lp = new int[n]; //max profit [0..i]
    for (int i=0; i<n; i++){
        profit = max(profit,prices[i]-prevMin);
        prevMin = min(prices[i],prevMin);
        lp[i] = profit;
    }
    profit = 0;
    int * rp = new int[n]; //max profit[i..n-1]
    int prevMax = INT_MIN;
    for (int i=n-1; i>=0; i--){
        if (i!=n-1) // integer overflow !!
            profit = max(profit, prevMax - prices[i]);
        prevMax = max(prevMax, prices[i]);
        rp[i] = profit;
    }
    int rlt = lp[n-1];
    for (int i=1; i<n; i++)
        rlt = max(rlt, lp[i-1]+rp[i]);
    delete []lp;
    delete []rp;
    return rlt;
}

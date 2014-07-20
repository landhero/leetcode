/*
buy at the begin and sell at the end of each ascending subsequence
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    int maxProfit(vector<int> &);
};
int Solution::maxProfit(vector<int> & prices){
    int n = prices.size();
    int i=0;
    int profit = 0;
    while (i<n){
        int j=i;
        while (j+1<n && prices[j+1]>=prices[j])
            j++;
        profit += prices[j]-prices[i];
        i = j+1;
    }
    return profit;
}

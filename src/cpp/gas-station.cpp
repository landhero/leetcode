/**
*@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost);
};
int Solution::canCompleteCircuit(vector<int> &gas, vector<int> &cost){
    if (gas.size()<=0 || cost.size()<=0 || gas.size()!=cost.size())
        return -1;
    int index = -1;
    int n = gas.size();
    int total = 0; int sum = 0;
    for (int i =0; i<n; i++){
        total += gas[i]-cost[i];
        sum += gas[i]-cost[i];
        if (sum<0){
            index = i;
            sum = 0;
        }
    }
    if (total >=0)
        return index+1;
    return -1;
}
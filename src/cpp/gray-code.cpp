/**
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    vector<int> grayCode(int);
};

vector<int> Solution::grayCode(int n){
    if (n<=0)
        return vector<int>(1,0);
    int size = 1<<n;
    vector<int> rlt(size, 0);
    for (int i=1; i<=n; i++){
        int k = 1 << (i-1);
        for (int j=0; j<k; j++)
            rlt[k+j] = rlt[k-j-1]+k;
    }
    return rlt;
}
/**
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    // not binary digits !!!!! shit!
    vector<int> plusOne(vector<int> &digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> rlt(digits.size()+1,0);
        int n = digits.size();
        rlt[n]=1;
        int i;
        int carry = 0;
        for (i=n-1; i>=0; i--){
            rlt[i+1] += digits[i] + carry;
            carry = rlt[i+1] /10;
            rlt[i+1] %= 10;
        }
        if (carry>0)
            rlt[0] = carry;
        vector<int> realRlt;
        i = 0;
        while(rlt[i]<=0)
            i++;
        while(i<=n)
            realRlt.push_back(rlt[i++]);
        return realRlt;
    }
};
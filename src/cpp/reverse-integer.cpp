/**
* @author Hansheng Zhang
*/
class Solution {
public:
    int reversePositive(int x){
        int ans = 0;
        while(x!=0){
            ans = ans*10 + (x%10);
            x = x / 10;
        }
        return ans;
    }
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (x>=0)
            return reversePositive(x);
        return 0-reversePositive(0-x);
    }
};

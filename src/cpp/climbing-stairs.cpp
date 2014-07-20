/**
* @author Hansheng Zhang
*/
class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n<=0)
            return 0;
        if (n==1)
            return 1;
        int current, lastTwo = 1,lastOne=1;
        int i;
        for (i=2; i<=n; i++){
            current = lastTwo + lastOne;
            if (i==n)
                return current;
             lastTwo = lastOne;
             lastOne = current;
        }
        return 0;
    }
};
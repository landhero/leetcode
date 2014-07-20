/**
* overflow
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    int sqrt(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (x<=0)
            return 0;
        int right = x;
        int left = 1;
        int middle;
        while (left <= right){
            middle = (left+right)/2;
            if (x/middle==middle)
                return middle;
            else if (x/middle<middle)
                right = middle - 1;
            else left = middle +1;
        }
        if (x/middle<middle)
            return middle - 1;
        return middle;
    }
};

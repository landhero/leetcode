/**
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    int singleNumber(int[], int);
};
int Solution::singleNumber(int A[], int n){
    int ones = 0, twos = 0, nthrees = 0;
    for (int i=0; i<n; i++){
        nthrees = ~(twos & A[i]);
        twos = twos | (ones & A[i]);
        ones = ones ^ A[i];
        twos = twos & nthrees;
        ones = ones & nthrees;
    }
    return ones;
}

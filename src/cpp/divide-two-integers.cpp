/**
* @author Hansheng Zhang
*/
class Solution {
public:
	int divide(int dividend, int divisor);
};

int Solution::divide(int divident, int divisor){
	if (divisor == INT_MIN){
		if (divident == INT_MIN)
			return 1;
		return 0;
	}
	int sign = (divident < 0 ? -1 : 1) * (divisor < 0 ? -1 : 1);  // replace if else
	divisor = abs(divisor);
	int rlt = 0;
	if (divident>0)
		divident = ~divident + 1;
	while (divident + divisor <= 0){
		int i = 0;
		while ((divisor << (i + 1)) >= 0 && divident + (divisor << (i + 1)) <= 0){
			i++;
		}
		rlt += (1 << i);
		divident += (divisor << i);
	}
	return rlt * sign; // replace if else
}

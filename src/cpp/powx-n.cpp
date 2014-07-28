/**
* @author Hansheng Zhang
*/
class Solution {
public:
	double pow(double x, int n) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if (x<0){
			if (n % 2 == 0)
				return pow(0-x, n);
			return 0-pow(0-x, n);
		}
		if (x == 1)
			return 1;
		if (n == INT_MIN && x>1)
			return 0;
		if (n == INT_MAX && x < 1)
			return 0;
		if (n < 0){
			n = 0 - n;
			x = 1 / x;
			return pow(x, n);
		}
		if (n == 0)
			return 1;
		if (n == 1)
			return x;
		int t = n / 2;
		double a = pow(x, t);
		if (n % 2 == 0)
			return a*a;
 		return a*a*x;
	}
};

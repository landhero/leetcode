/**
* @author Hansheng Zhang
*/
class Solution {
public:
	bool isPalindrome(int x);
};
bool Solution::isPalindrome(int x){
	if (x < 0)
		return false;
	x = abs(x);
	int pow = 1;
	while (x / pow >= 10)
		pow = pow * 10;
	while (x > 0){
		int left = x / pow;
		int right = x % 10;
		if (left != right)
			return false;
		x = x % pow;
		x /= 10;
		pow = pow / 100;
	}
	return true;
}

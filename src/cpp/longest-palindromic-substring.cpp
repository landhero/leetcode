/**
* @author Hansheng Zhang
*/

class Solution {
public:
	string longestPalindrome(string s);
};
string Solution::longestPalindrome(string s){
	int len = s.length();
	string rlt = "";
	for (int i = 0; i < len; i++){
		for (int loc : vector<int>({0, 1}) ){
			int left = i, right = i + loc;
			while (left >= 0 && right < len && s[left] == s[right]){
				--left;
				++right;
			}
			++left; --right;
			if (left <= right && right - left + 1>rlt.length())
				rlt = s.substr(left, right - left + 1);
		}
	}
	return rlt;
}

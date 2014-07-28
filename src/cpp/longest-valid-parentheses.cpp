/**
* @author Hansheng Zhang
*/
class Solution {
public:
	int longestValidParentheses(string s);
};
int Solution::longestValidParentheses(string s){
	stack<int> lefts;
	int rlt = 0;
	int len = s.length();
	for (int i = 0; i < len; i++){
		if (s[i] == '(')
			lefts.push(i);
		else if (!lefts.empty() && s[lefts.top()] == '(')
			lefts.pop();
		else lefts.push(i);
	}
	if (lefts.empty())
		return len;
	int a = len, b = 0;
	while (!lefts.empty()){
		b = lefts.top();
		lefts.pop();
		rlt = max(rlt, a-b-1);
		a = b;
	}
	rlt = max(rlt, a);
	return rlt;
}

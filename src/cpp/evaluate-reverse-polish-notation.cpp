/**
* @author Hansheng Zhang (http://zhanghs.com)
*/

class Solution {
public:
    void parseNum(stack<int> &,  const string &);
    void parseOperator(stack<int> &, char);
    int evalRPN(vector<string> &);
};

int Solution::evalRPN(vector<string> & tokens){
    const int errorResult = INT_MIN;
    if (tokens.size()==0)
        return errorResult;
    stack<int> stack;
    for (vector<string>::iterator itr = tokens.begin(); itr!=tokens.end(); itr++){
        if ((*itr).length()<=0)
            return errorResult;
        if ((*itr).length()==1){
            char c = (*itr).at(0);
            if (c=='+' || c=='-' || c=='*' || c=='/')
                parseOperator(stack, c);
            else parseNum(stack, *itr);
        }
        else parseNum(stack, *itr);
    }
    if (stack.size()!=1)
        return errorResult;
    return stack.top();
}

void Solution::parseNum(stack<int>& _stack, const string & token){
	int number = atoi(token.c_str());
	_stack.push(number);
}

void Solution::parseOperator(stack<int> & _stack, char token){
	int num1 = _stack.top();
	_stack.pop();
	int num2 = _stack.top();
	_stack.pop();
	int rlt = 0;
	switch(token){
	case '+':
	    rlt= num2+num1;
	    break;
	case '-':
	    rlt = num2-num1;
	    break;
	case '*':
	    rlt= num2*num1;
	    break;
	case '/':
	    rlt = num2/num1;
	    break;
	}
	_stack.push(rlt);
}

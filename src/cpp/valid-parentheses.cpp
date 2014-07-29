/**
* @author Hansheng Zhang
*/
class Solution {
public:
    bool isValid(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        stack<char> sc;
        int len = s.length();
        for (int i=0; i<len; i++){
            char c = s.at(i);
            switch(c){
                case '(':
                case '{':
                case '[':
                    sc.push(c);
                    break;
                case '}':
                    if (sc.empty() ||sc.top()!='{')
                        return false;
                    else sc.pop();
                    break;
                case ']':
                    if (sc.empty() ||sc.top()!='[')
                        return false;
                    else sc.pop();
                    break;
                case ')':
                    if (sc.empty() ||sc.top()!='(')
                        return false;
                    else sc.pop();
                    break;
                default:
                    return false;
            }
        }
        if (!sc.empty())
            return false;
        return true;
    }
};
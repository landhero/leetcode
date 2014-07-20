/**
* easy
* @author Hansheng Zhang
*/
class Solution {
public:
    string simplifyPath(string path) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> names;
        int len = path.length();
        string token = "";
        for (int i=0; i<len; i++){
            char c = path.at(i);
            if (c!='/'){
                token += c;
                continue;
            }
            else if (token == "" || token=="."){
                token = "";
                continue;
            }
            if (token==".." && !names.empty())
                names.pop_back();
            else if (token!="..") names.push_back(token);
            token = "";
        }
        if (token!="" && token!="."){
            if (token==".." && !names.empty())
                names.pop_back();
            else if (token!="..") names.push_back(token);
        }
        if (names.empty())
            return "/";
        int size = names.size();
        string rlt;
        for (int i=0; i<size; i++)
            rlt+= "/"+names[i];
        return rlt;
    }
};
//try to solve the problem without stack

class Solution {
public:
    void uniformString(string &);
    void reverseString(string &, unsigned , unsigned);
    void reverseWords(string &);
};
void Solution::uniformString(string & s){
    unsigned len= s.length();
    if (len<=0)
        return;
    unsigned index=0;
    bool flag = true;
    for (unsigned i = 0; i<len; i++){
        if (s[i]!=' '){
            flag = false;
            s[index++] = s[i];
        }
        else if (flag==false){
            flag = true;
            s[index++] = ' ';
        }
    }
    if(s[index-1]==' ')
        --index;
    s = s.substr(0, index);
}

void Solution::reverseString(string &s, unsigned start, unsigned end){
    char c;
    while (start < end){
        c = s[start];
        s[start++] = s[end];
        s[end--] = c;
    }
}

void Solution::reverseWords(string &s){
    uniformString(s);
    unsigned len = s.length();
    if (len<=2)
        return;
    reverseString(s, 0, len-1);
    unsigned start = 0;
    while (start<len){
        unsigned end = start;
        while (end<len && s[end]!=' ')
            end++;
        if (end-start>=2)
            reverseString(s, start, end-1);
        start = end+1;
    }
}

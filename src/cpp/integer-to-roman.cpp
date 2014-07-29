/**
* @author Hansheng Zhang
*/
class Solution {
public:
  string intToRoman(int num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    string thousands[4]={"","M","MM","MMM"};
    string hundreds[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string tens[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string ones[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string rlt="";
    rlt += thousands[num/1000];
    num %= 1000;
    rlt += hundreds[num/100];
    num %= 100;
    rlt += tens[num/10];
    num%=10;
    rlt += ones[num];
    return rlt;
  }
};

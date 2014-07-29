/**
* @author Hansheng Zhang
*/
class Solution {
public:
    int romanToInt(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string romans[30] = {"I","II","III","IV","V","VI","VII","VIII","IX","X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M","MM","MMM"};
        int nums[30] = {1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100,200,300,400,500,600,700,800,900,1000,2000,3000};
        int i=0;
        int len = s.length();
        int rlt = 0;
        while (i<len){
            for (int j=29; j>=0; j--){
                string tmp = romans[j];
                if (s.substr(i,tmp.length()) == tmp){
                    i += tmp.length();
                    rlt += nums[j];
                    break;
                }
            }
        }
        return rlt;
    }
};

/**
* @author Hansheng Zhang
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		int len1 = num1.length();
		int len2 = num2.length();
		if (len1<=0 || len2<=0)
			return "";
		int * a = new int[len1];
		int * b = new int[len2];
		for (int i=0; i<len1; i++)
			a[len1-i-1] = num1.at(i)-'0';
		for (int i=0; i<len2; i++)
			b[len2-i-1] = num2.at(i)-'0';
		int * c = new int[len1+len2];
		for (int i=0; i<len1+len2; i++){
			c[i] = 0;
		}
		for (int i=0; i<len1; i++)
			for (int j=0; j<len2; j++)
				c[i+j] += a[i] *b[j];
		for (int i=0; i<len1+len2-1; i++){
			if (c[i]>=10){
				c[i+1] += c[i]/10;
				c[i] %= 10;
			}
		}
		string rlt = "";
		bool flag = false;
		for (int i=len1+len2-1; i>=0; i--){
			if (c[i]!=0)
				flag = true;
			if (flag)
				rlt += (char)('0'+c[i]);
		}
		delete []a;
		delete []b;
		delete []c;
		if (rlt=="")
			rlt = "0";
		return rlt;
    }
};

/**
* @author Hansheng Zhang
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        string rlt="";
	unsigned *facts = new unsigned[n+1];
	unsigned * arr = new unsigned[n];
	facts[0] = 1;
	for (int i=1; i<=n; i++){
	    facts[i] = facts[i-1] * i;
	    arr[i-1] = i;
	}
	k = k-1;
	for (int i=1; i<n; i++){
	    int offset  = k/facts[n-i];
	    int  tmp = arr[i-1+offset];
	    for (int j=i-1+offset; j>=i; j--){
		arr[j] = arr[j-1];
	    }
	    arr[i-1] = tmp;
	    k = k % facts[n-i];
	}
       	for (int i=0; i<n; i++)
	    rlt = rlt + (char)('0'+arr[i]);
	delete []arr;
	delete []facts;
	return rlt;
    }
};

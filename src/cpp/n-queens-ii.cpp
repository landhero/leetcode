/**
* @author Hansheng Zhang
* Bit-vector may be used. See discuss
*/

class Solution {
public:
    void generateResults(int & rlt, int n, int index, bool * flag1, bool * flag2, bool* flag3){
	for (int i=0; i<n; i++){
	    int j = index+i;
	    int k = index-i+n-1;
	    if (flag1[i] || flag2[j] || flag3[k]){
		continue;
	    }
	    flag1[i]=true;
	    flag2[j]=true;
	    flag3[k]=true;
	    if (index==n-1){
		rlt++;
	    }
	    else generateResults(rlt,n,index+1,flag1,flag2,flag3);
	    flag1[i]=false;
	    flag2[j]=false;
	    flag3[k]=false;
	}
    }

    int totalNQueens(int n) {
	// IMPORTANT: Please reset any member data you declared, as
	// the same Solution instance will be reused for each test case.
	if (n<=0)
	    return 0;
	int * cur = new int[n];
	bool * flag1 = new bool[n];
	bool * flag2 = new bool[2*n-1];
	bool * flag3 = new bool[2*n-1];
	for (int i=0; i<n; i++){
	    flag1[i]=false;
	}
	for (int i=0; i<2*n-1; i++){
	    flag2[i]=false;
	    flag3[i]=false;
	}
	int rlt = 0;
	generateResults(rlt,n,0,flag1,flag2,flag3);
	delete []flag1;
	delete []flag2;
	delete []flag3;
	return rlt;
    }
};

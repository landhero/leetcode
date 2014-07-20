/*
preprocessing & dynamic programming
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    int minCut(string);
};
int Solution::minCut(string s) {
    int n = s.length();
	if (n<=1)
	    return 0;
    vector<vector<bool>> palFlags(n, vector<bool>(n,false)); // preprocessing
    for (int i=0; i<n; i++){
        palFlags[i][i] = true;
        if (i<n-1 && s[i+1]==s[i])
            palFlags[i][i+1] = true;
    }
    for (int len=3; len<=n; len++)
        for (int i=0; i<=n-len; i++){
            int j = i+len-1;
            if (s[i]==s[j])
                palFlags[i][j] = palFlags[i+1][j-1];
        }
    vector<int> rlts(n+1, -1); //b
    for (int i=0; i<n; i++){
        int curMin = INT_MAX;
        for (int j=0; j<=i; j++){
            if (!palFlags[j][i])
                continue;
            if (curMin>rlts[j]+1)
                curMin = rlts[j]+1;
        }
        rlts[i+1] = curMin;
    }
    return rlts[n];
}

/**
* @author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end());
        int n = S.size();
        vector<vector<int>> rlt;
        if (n<=0)
            return rlt;
        rlt.push_back(vector<int>());
        int i, j;
        for (i=0; i<n; i){
            int m = rlt.size();
            int dn=0;
            while(dn+i<n && S[i+dn]==S[i])
                dn++;
            for (j=0; j<m; j++){
                for (int k=1; k<=dn; k++){
                    vector<int> tmp = rlt[j];
                    for (int l=1; l<=k; l++){
                        tmp.push_back(S[i]);
                    }
                    rlt.push_back(tmp);
                }
            }
            i += dn;
        }
        return rlt;
    }
};
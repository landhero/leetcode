/**
* @author Hansheng Zhang
*/
class Solution {
public:
    void solve(vector<vector<int>> &rlt, vector<int> cur, int k, int n){
        int last = 0;
        if (!cur.empty())
            last = *(cur.end()-1);
        for (int i= last+1; n-i>=k-1; i++){
            vector<int> tvc = cur;
            tvc.push_back(i);
            if (k==1)
                rlt.push_back(tvc);
            else solve(rlt, tvc, k-1, n);
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> rlt;
        vector<int> cur;
        solve(rlt, cur, k, n);
        return rlt;
    }
};
/**
* @author Hansheng Zhang
*/
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        sort(num.begin(),num.end());
        vector<vector<int>> rlt;
        rlt.push_back(num);
        int n = num.size();
        while (true){
            int i;
            for (i=n-2; i>=0; i--){
                if (num[i]<num[i+1])
                    break;
            }
            if (i<0)
                break;
            int min = num[i+1];
            int minIndex = i+1;
            for (int j =i+1+1; j<n; j++){
                if (num[j]>num[i] && num[j]<min){
                    min = num[j];
                    minIndex = j;
                }
            }
            int tmp = num[i];
            num[i] = num[minIndex];
            num[minIndex] = tmp;
            sort(&num[i+1], &num[n]);
            rlt.push_back(num);
        }
        return rlt;
    }
};

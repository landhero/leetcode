/**
* @author Hansheng Zhang
*/
class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > result;
    sort(num.begin(),num.end());
    vector<int> entry;
    entry.assign(3,-1000);
    vector<int>::iterator i ,j ,k;
    for (i=num.begin();i<num.end();i++){
      if (i>num.begin() && *i==*(i-1))
        continue;
      j = i+1;
      k = num.end()-1;
      while (j<k){
        int sum = *i+*j+*k;
        if (sum>0)
          k--;
        else if (sum<0)
          j++;
        else {
          if (*j!=entry[1]||*k!=entry[2]){
            entry[0]=*i;
            entry[1]=*j;
            entry[2] = *k;
            result.push_back(entry);
          }
          k--;
          j++;
        }
      }
    }
    return result;
  }
};
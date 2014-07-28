/**
 * @author Hansheng Zhang
 */
 bool cmp (Interval  a,Interval b){
    return a.start < b.start;
 }
class Solution {
public:
  int maxInt(const int a, const int b){
    return a>b?a:b;
  }
  vector<Interval> merge(vector<Interval> &intervals) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (intervals.size()<=0)
      return intervals;
    sort(intervals.begin(), intervals.end(), cmp);
    int size = intervals.size();
    int validIndex=0;
    for(int i = 1; i < size ; i++){
      if (intervals[i].start <= intervals[validIndex].end)
        intervals[validIndex].end = maxInt(intervals[validIndex].end, intervals[i].end);
      else{
        intervals[++validIndex] = intervals[i];
      }
    }
    for (int i=validIndex+1; i<size; i++){
      intervals.pop_back();
    }
    return intervals;
  }
};
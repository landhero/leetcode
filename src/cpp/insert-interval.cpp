/**
* @author Hansheng Zhang
*/
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> rlt;
        int n = intervals.size();
        int i;
        for (i=0; i<n; i++){
            if (intervals[i].end<newInterval.start)
                rlt.push_back(intervals[i]);
            else break;
        }
        if (i<n){
            if (intervals[i].start>newInterval.end)
                rlt.push_back(newInterval);
            else {
                Interval  & merged =  intervals[i];
                merged.start = min(merged.start, newInterval.start);
                merged.end = max(merged.end, newInterval.end);
                for (++i; i<n; ++i){
                    if(merged.end>=intervals[i].start)
                        merged.end = max (merged.end, intervals[i].end);
                    else break;
                }
                rlt.push_back(merged);
            }
            for (; i<n; ++i)
                rlt.push_back(intervals[i]);
        }
        else rlt.push_back(newInterval);
        return rlt;
    }
};
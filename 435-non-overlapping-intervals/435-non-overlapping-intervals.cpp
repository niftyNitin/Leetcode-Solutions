class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];
            
            if(curStart < prevEnd) {
                prevEnd = min(curEnd, prevEnd);
                count++;
            }
            else {
                prevStart = curStart;
                prevEnd = curEnd;
            }
        }
        return count;
    }
};
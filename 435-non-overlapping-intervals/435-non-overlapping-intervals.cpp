class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0])    return a[1] < b[1];
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            if(s >= end) {
                start = s;
                end = e;
            }
            else {
                end = min(end, e);
                count++;
            }
        }
        return count;
    }
};
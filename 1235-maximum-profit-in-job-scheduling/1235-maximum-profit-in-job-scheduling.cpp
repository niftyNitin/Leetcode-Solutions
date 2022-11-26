class Solution {
public:
    int solve(vector<vector<int>> &jobs, vector<int> &startTime, int i, vector<int> &dp) {
        int n = jobs.size();
        if(i >= n)  return 0;
        if(dp[i] != -1) return dp[i];
        int idx = lower_bound(startTime.begin(), startTime.end(), jobs[i][1]) - startTime.begin();
        int pick = jobs[i][2] + solve(jobs, startTime, idx, dp);
        int notPick = solve(jobs, startTime, i+1, dp);
        
        return dp[i] = max(pick, notPick);
    }
    
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for(int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(startTime.begin(), startTime.end());
        sort(jobs.begin(), jobs.end());
        
        vector<int> dp(n+1, -1);
        return solve(jobs, startTime, 0, dp);
    }
};
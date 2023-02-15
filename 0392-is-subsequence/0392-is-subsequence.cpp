class Solution {
public:
    int solve(string s, string t, int i, int j, vector<vector<int>> &dp) {
        if(i < 0 or j < 0)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        if(s[i] == t[j])    return dp[i][j] = 1 + solve(s, t, i-1, j-1, dp);
        return dp[i][j] = max(solve(s, t, i-1, j, dp), solve(s, t, i, j-1, dp));
    }
    
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int> (t.size(), -1));
        return solve(s, t, s.size()-1, t.size()-1, dp) == s.size();
    }
};
class Solution {
public:
    int dfs(int x, int y, vector<vector<int>> &dp) {
        if(x == 0 and y == 0)   return 1;
        if(x < 0 or y < 0)  return 0;
        if(dp[x][y] != -1)  return dp[x][y];
        return dp[x][y] = dfs(x-1, y, dp) + dfs(x, y-1, dp);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return dfs(m-1, n-1, dp);
    }
};
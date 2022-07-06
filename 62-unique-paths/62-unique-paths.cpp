class Solution {
public:    
    int findPaths(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i == m and j == n)  return 1;
        if(i > m or j > n or i <= 0 or j <= 0)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        int r = findPaths(i, j+1, m, n, dp);
        int b = findPaths(i+1, j, m, n, dp);
        return dp[i][j] = r+b;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return findPaths(1, 1, m, n, dp);
    }
};
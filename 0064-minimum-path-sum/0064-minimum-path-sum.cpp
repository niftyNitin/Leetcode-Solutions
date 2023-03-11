class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid) {
        if(i < 0 or j < 0)  return 0;
        if(i == 0 and j == 0) {
            return grid[i][j];
        }
        
        return max(solve(i-1, j, grid), solve(i, j-1, grid));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 and j == 0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                
                int a = INT_MAX, b = INT_MAX;
                if(i-1 >= 0)    a = dp[i-1][j];
                if(j-1 >= 0)    b = dp[i][j-1];
                
                dp[i][j] = min(a, b) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
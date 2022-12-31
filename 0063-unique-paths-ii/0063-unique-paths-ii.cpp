class Solution {
public:
    int dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(x < 0 or y < 0 or grid[x][y] == 1)   return 0;
        if(x == 0 and y == 0)   return 1;
        if(dp[x][y] != -1)  return dp[x][y];
        return dp[x][y] = dfs(x-1, y, grid, dp) + dfs(x, y-1, grid, dp);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return dfs(m-1, n-1, grid, dp);
    }
};
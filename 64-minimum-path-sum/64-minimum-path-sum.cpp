class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, int row, int col, vector<vector<int>> &dp) {
        if(i == row-1 and j == col-1)   return grid[i][j];
        if(i >= row or j >= col)    return 1e5;
        if(dp[i][j] != -1)  return dp[i][j];
        int path1 = helper(grid, i+1, j, row, col, dp);
        int path2 = helper(grid, i, j+1, row, col, dp);
        return dp[i][j] = grid[i][j] + min(path1, path2);        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int> (col, -1));
        return helper(grid, 0, 0, row, col, dp);
    }
};
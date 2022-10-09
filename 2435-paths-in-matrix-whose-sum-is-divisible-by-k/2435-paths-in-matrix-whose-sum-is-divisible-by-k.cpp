class Solution {
public:
    int mod = 1e9+7;
    int solve(vector<vector<int>> &grid, int i, int j, int k, int sum, vector<vector<vector<int>>> &dp) {
        int m = grid.size();
        int n = grid[0].size();
        if(i >= m or j >= n)        return 0;
        sum += grid[i][j];
        if(i == m-1 and j == n-1 and sum % k == 0)   return 1;
        if(dp[i][j][sum%k] != -1)   return dp[i][j][sum%k];
        
        int down = solve(grid, i+1, j, k, sum, dp);
        int right = solve(grid, i, j+1, k, sum, dp);
        
        return dp[i][j][sum%k] = ((down%mod)+(right%mod)) % mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>> (grid[0].size(), vector<int> (51, -1)));
        return solve(grid, 0, 0, k, 0, dp);
    }
};
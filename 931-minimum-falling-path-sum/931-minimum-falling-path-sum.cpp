class Solution {
public:
    int helper(vector<vector<int>> &matrix, int row, int col, int size, vector<vector<int>> &dp) {
        if(row >= size or col >= size or row < 0 or col < 0)    return 1e5;
        if(row == size-1)   return matrix[row][col];
        if(dp[row][col] != -1)  return dp[row][col];
        int path1 = helper(matrix, row+1, col, size, dp);
        int path2 = helper(matrix, row+1, col-1, size, dp);
        int path3 = helper(matrix, row+1, col+1, size, dp);
        return dp[row][col] = matrix[row][col] + min(path1, min(path2, path3));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int size = matrix.size();
        vector<vector<int>> dp(size, vector<int> (size, -1));
        int min_sum = INT_MAX;
        for(int col = 0; col < size; col++) {
            min_sum = min(min_sum, helper(matrix, 0, col, size, dp));
        }
        return min_sum;
    }
};
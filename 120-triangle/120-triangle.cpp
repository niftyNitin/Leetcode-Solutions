class Solution {
public:
    int helper(vector<vector<int>>& triangle, int i, int j, int row, vector<vector<int>> &dp) {
        if(i == row-1 and j < triangle[i].size())   return triangle[i][j];
        if(j >= triangle[i].size()) return 1e7;
        if(dp[i][j] != -1)  return dp[i][j];
        int path1 = helper(triangle, i+1, j, row, dp);
        int path2 = helper(triangle, i+1, j+1, row, dp);
        return dp[i][j] = triangle[i][j] + min(path1, path2);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        for(auto &i : dp)  
            for(auto &j : i)  j = -1;

        cout << endl;
        int row = triangle.size();
        return helper(triangle, 0, 0, row, dp);
    }
};
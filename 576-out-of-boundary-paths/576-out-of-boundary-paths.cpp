class Solution {
public:
    int mod = 1e9+7;
    int dp[51][51][51];
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return helper(m, n, maxMove, startRow, startColumn, 0);
    }
    
    int helper(int m, int n, int maxMove, int startRow, int startColumn, int move) {
        if((startRow < 0 or startRow >= m or startColumn < 0 or startColumn >= n) and move <= maxMove)
            return 1;
        
        if(move > maxMove)  return 0;
        
        if(dp[startRow][startColumn][move] != -1)  return dp[startRow][startColumn][move];
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        long long res = 0;
        for(int i = 0; i < 4; i++) {
            res = (res + helper(m, n, maxMove, startRow + dx[i], startColumn + dy[i], move+1)) % mod;
        }
        
        return dp[startRow][startColumn][move] = res;
    }
};
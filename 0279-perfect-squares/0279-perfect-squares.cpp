class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if(n == 0)  return 0;
        if(n == 1)  return 1;
        if(n < 0)   return 1e6;
        if(dp[n] != -1) return dp[n];
        
        int sqroot = sqrt(n);
        int ans = INT_MAX;
        for(int i = 1; i <= sqroot; i++) {
            int x = 1 + solve(n-i*i, dp);
            ans = min(ans, x);
        }
        
        return dp[n] = ans;
    }
    
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};
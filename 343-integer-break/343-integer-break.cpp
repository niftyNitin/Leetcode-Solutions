class Solution {
public:
    int dp[59];
    Solution() {
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        dp[5] = 6;
        dp[6] = 9;
    }
    
    int integerBreak(int n) {
        int maxx = n;
        if(dp[n] != -1) return dp[n];
        for(int i = 1; i <= n-1; i++) {
            int prod = i * integerBreak(n-i);
            maxx = max(maxx, prod);
        }
        return dp[n] = maxx;
    }
};
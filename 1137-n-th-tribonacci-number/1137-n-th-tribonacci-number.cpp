class Solution {
public:
    int findTribonacci(int n, vector<int> &dp) {
        if(dp[n] != -1) return dp[n];
        return dp[n] = findTribonacci(n-1, dp) + findTribonacci(n-2, dp) + findTribonacci(n-3, dp);
    }
    int tribonacci(int n) {
        vector<int> dp(38, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        return findTribonacci(n, dp);
    }
};
class Solution {
public:
    int solve(vector<int>& coins, int amount, int idx, vector<vector<int>> &dp) {
        if(amount == 0)
            return 0;
        if(amount < 0 or idx >= coins.size())
            return 1e5;
        
        if(dp[idx][amount] != -1)
            return dp[idx][amount];
        
        long long a = 1 + solve(coins, amount-coins[idx], idx, dp);
        long long b = solve(coins, amount, idx+1, dp);
        
        return dp[idx][amount] = min(a,b);        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(12, vector<int> (1e4+1, -1));
        int ans = solve(coins, amount, 0, dp);
        return (ans == 1e5) ? -1 : ans;
    }
};
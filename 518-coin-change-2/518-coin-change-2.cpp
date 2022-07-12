class Solution {
public:
    int dp[302][5002];
    int helper(int amount, vector<int>& coins, int i) {
        if(amount == 0) {
            return 1;
        }
        
        if(amount < 0 or i >= coins.size())
            return 0;
        
        if(dp[i][amount] != -1) return dp[i][amount];
        
        int a = helper(amount-coins[i], coins, i);
        int b = helper(amount, coins, i+1);
        
        return dp[i][amount] = a+b;
    }
    
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return helper(amount, coins, 0);
    }
};
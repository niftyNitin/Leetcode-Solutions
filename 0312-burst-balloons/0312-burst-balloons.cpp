class Solution {
public:
    int solve(vector<int> &nums, int l, int r, vector<vector<int>> &dp) {
        if(l > r)   return 0;
        int ans = 0;
        if(dp[l][r] != -1)  return dp[l][r];
        
        for(int i = l; i <= r; i++) {
            int val = nums[i];
            if(l-1 >= 0) val *= nums[l-1];
            if(r+1 <= nums.size()-1)    val*=nums[r+1];
            
            ans = max(ans, val+solve(nums, l, i-1, dp)+solve(nums, i+1, r, dp));
        }
        return dp[l][r] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(nums, 0, n-1, dp);
    }
};
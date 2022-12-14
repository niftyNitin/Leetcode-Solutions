class Solution {
public:
    vector<int> dp;
    int solve(vector<int> &nums, int i) {
        if(i >= nums.size())    return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        ans = max(ans, nums[i] + solve(nums, i+2));
        ans = max(ans, solve(nums, i+1));
        
        return dp[i] = ans;
    }
    
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+1, -1);
        return solve(nums, 0);
    }
};
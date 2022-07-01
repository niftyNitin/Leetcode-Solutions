class Solution {
public:
    int dp[101];
    int robber(vector<int> &nums, int idx) {
        if(idx < 0)  return 0;
        if(dp[idx] != -1)  return dp[idx];
       
        int a = nums[idx] + robber(nums, idx-2);
        int b = nums[idx] + robber(nums, idx-3);
        return dp[idx] = max(a, b);
    }
    
    int rob(vector<int>& nums) {
        for(int i = 0; i < 101; i++)    dp[i] = -1;
        int a = robber(nums, nums.size()-1);
        int b = robber(nums, nums.size()-2);
        return max(a, b);
    }
};
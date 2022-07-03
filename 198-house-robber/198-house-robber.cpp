class Solution {
public:
    int dp[101];
    int robber(vector<int> &nums, int idx) {
        if(idx < 0)  return 0;
        if(dp[idx] != -1)  return dp[idx];
       
        int a = nums[idx] + robber(nums, idx-2);
        int b = robber(nums, idx-1);
        return dp[idx] = max(a, b);
    }
    
    int rob(vector<int>& nums) {
        for(int i = 0; i < 101; i++)    dp[i] = -1;
        return robber(nums, nums.size()-1);
    }
};

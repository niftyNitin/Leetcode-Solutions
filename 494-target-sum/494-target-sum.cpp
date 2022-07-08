class Solution {
public:
    int dp[22][1001][2];
    int helper(vector<int> &nums, int target, int i, int sum) {
        
        if(i == nums.size() and sum == target)
            return 1;
        
        if(i >= nums.size())
            return 0;
    
        
        if(sum >=0  && dp[i][abs(sum)][0] != -1)    return dp[i][abs(sum)][0];
        
        if(sum < 0 && dp[i][abs(sum)][1] != -1)    return dp[i][abs(sum)][1]; 
        
        int a =  helper(nums, target, i+1, sum+nums[i]);
        int b = helper(nums, target, i+1, sum-nums[i]);
        
        if(sum >= 0)
            return dp[i][abs(sum)][0] =  a + b;
        return dp[i][abs(sum)][1] = a + b;     
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return helper(nums, target, 0, 0);
    }
};
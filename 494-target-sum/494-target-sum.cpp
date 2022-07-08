class Solution {
public:
    int count = 0;
    
    int helper(vector<int> &nums, int target, int i, int sum) {
        
        if(i == nums.size() and sum == target) {
           
            return 1;
            
        
        }
        
        if(i >= nums.size())    return 0;
        
        
       // if(dp[i][sum] != -1)    return dp[i][sum];
        
        int a = 0,b=0;
       a += helper(nums, target, i+1, sum+nums[i]);
       b += helper(nums, target, i+1, sum-nums[i]);
        
        return  a + b;
    }
    
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+2, vector<int>(20001, -1));
        return helper(nums, target, 0, 0);
        
    }
};
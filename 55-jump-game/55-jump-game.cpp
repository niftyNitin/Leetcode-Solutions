class Solution {
public:
    int dp[10001];
    bool jump_helper(vector<int> &nums, int idx) {
        if(idx >= nums.size())  return false;
        if(idx == nums.size()-1)    return true;
        if(dp[idx] != -1)   return dp[idx];
        for(int i = idx+1; i <= idx+nums[idx]; i++) {
            bool res = jump_helper(nums, i);
            if(res) return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return jump_helper(nums, 0);
    }
};
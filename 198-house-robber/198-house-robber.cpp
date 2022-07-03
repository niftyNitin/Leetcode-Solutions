class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(101, -1);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int pick = nums[i];
            if(i > 1)   pick += dp[i-2];
            int nonpick = dp[i-1];
            dp[i] = max(pick, nonpick);
        }
        return dp[nums.size()-1];
    }
};

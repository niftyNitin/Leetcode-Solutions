class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = 0;
        for(int i = n-2; i >= 0; i--) {
            int mini = 1e5;
            for(int j = 1; j <= nums[i]; j++) {
                if(i+j < n and dp[i+j]!= -1) {
                    mini = min(mini, dp[i+j]);
                }
            }
            dp[i] = mini+1;
        }
        return dp[0];
    }
};
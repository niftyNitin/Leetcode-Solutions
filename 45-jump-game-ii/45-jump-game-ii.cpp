class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for(int i = n-2; i >= 0; i--) {
            int mini = 1e5;
            for(int j = 1; j <= nums[i]; j++) {
                if(i+j < n) {
                    mini = min(mini, dp[i+j]);
                }
            }
            dp[i] = mini+1;
        }
        return dp[0];
    }
};
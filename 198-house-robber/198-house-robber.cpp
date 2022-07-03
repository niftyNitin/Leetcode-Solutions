class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, prev2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            int pick = prev2 + nums[i];
            int nonpick = prev;
            prev2 = prev;
            prev = max(pick, nonpick);
        }
        return prev;
    }
};

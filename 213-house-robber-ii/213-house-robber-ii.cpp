class Solution {
public:
    int robber(vector<int>& nums, int idx) {
        int prev = nums[idx], prev2 = 0;
        for(int i = idx+1; i < nums.size(); i++) {
            int pick = prev2 + nums[i];
            int nonpick = prev;
            prev2 = prev;
            prev = max(pick, nonpick);
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() <= 3)    return *max_element(nums.begin(), nums.end());
        int a = robber(nums, 1);
        nums.pop_back();
        int b = robber(nums, 0);
        return max(a, b);
    }
};
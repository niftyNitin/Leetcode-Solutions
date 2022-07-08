class Solution {
public:
    int count = 0;
    void helper(vector<int> &nums, int target, int i, int sum) {
        if(i >= nums.size() and sum == target) {
            count++;
            return;
        }
        if(i >= nums.size())    return;
        
        helper(nums, target, i+1, sum+nums[i]);
        helper(nums, target, i+1, sum-nums[i]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        helper(nums, target, 0, 0);
        return count;
    }
};
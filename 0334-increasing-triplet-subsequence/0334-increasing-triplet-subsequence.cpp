class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX, mid = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] < left) left = nums[i];
            if(nums[i] > left and nums[i] < mid)    mid = nums[i];
            if(nums[i] > mid)   return true;
        }
        return false;
    }
};
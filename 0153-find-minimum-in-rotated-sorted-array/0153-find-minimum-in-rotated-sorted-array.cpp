class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0] <= nums.back())   return nums[0];
        int l = 0, r = nums.size();
        int ans;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(nums[m] > nums.back()) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return nums[ans+1];
    }
};
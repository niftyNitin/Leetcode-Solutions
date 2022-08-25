class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target > nums.back())   return nums.size();
        int low = 0, high = nums.size()-1;
        int res;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else {
                res = mid;
                high = mid - 1;
            }
        }
        
        return res;
    }
};
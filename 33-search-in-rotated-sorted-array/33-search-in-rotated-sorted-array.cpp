class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.back() > nums[0])   return 0;
        int l = 0, r = nums.size()-1;
        int res;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] >= nums[0]) l = mid+1;
            else {
                res = mid;
                r = mid - 1;
            }
        }
        return res;
    }
    
    int binSearch(vector<int> &nums, int low, int high, int target) {
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else    high = mid - 1;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int minIdx = findMin(nums);
        if(nums[minIdx] == target)  return minIdx;
        if(minIdx == 0) return binSearch(nums, 0, nums.size()-1, target);
        else if(target < nums[0])   return binSearch(nums, minIdx, nums.size()-1, target);
        return binSearch(nums, 0, minIdx-1, target);
    }
};
class Solution {
public:
    
    int findPos(vector<int> &nums, int target, bool first){
        int low = 0, high = nums.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                ans = mid;
                first ? high = mid-1 : low = mid + 1;
            }
            else{
                nums[mid] < target ? low = mid + 1 : high = mid - 1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findPos(nums, target, true);
        if(first == -1)
            return {-1, -1};
        int last = findPos(nums, target, false);
        return {first, last};
    }
};
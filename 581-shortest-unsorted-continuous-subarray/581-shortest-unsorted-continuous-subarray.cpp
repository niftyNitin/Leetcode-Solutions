class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left_index = 0, right_index = -1;
        int min_num = INT_MAX, max_num = INT_MIN;
        
        for(int i = nums.size()-1; i >= 0; i--) {
            if(nums[i] > min_num)   left_index = i;
            
            min_num = min(min_num, nums[i]);
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < max_num)   right_index = i;
            
            max_num = max(max_num, nums[i]);
        }
        
        return right_index - left_index + 1;
    }
};
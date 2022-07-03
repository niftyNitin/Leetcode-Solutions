class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        int start = 0, end = nums.size()-1;
        while(start < end)  swap(nums[start], nums[end]), start++, end--;
        
        start = 0, end = k-1;
        while(start < end)  swap(nums[start], nums[end]), start++, end--;
    
        start = k, end = nums.size()-1;
        while(start < end)  swap(nums[start], nums[end]), start++, end--;
    }
};
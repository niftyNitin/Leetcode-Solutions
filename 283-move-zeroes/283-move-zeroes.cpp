class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1)    return;
        int n = nums.size();
        
        int zeroes = 0;
        for(auto i : nums)
            if(i == 0)  zeroes++;
        
        int ind = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                nums[ind] = nums[i];
                ind++;
            }
        }
        
        for(int i = ind; i < n; i++)
            nums[i] = 0;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int &i : nums) {
            if(nums[abs(i)-1] < 0) return abs(i);
            if(nums[abs(i)-1] > 0)    nums[abs(i)-1] *= -1;
        }
        
        return 0;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for(int i = 1; i <= nums.size(); i++)
            x ^= i;
        
        for(int i = 0; i < nums.size(); i++)
            x ^= (nums[i]);
        
        return x;
    }
};
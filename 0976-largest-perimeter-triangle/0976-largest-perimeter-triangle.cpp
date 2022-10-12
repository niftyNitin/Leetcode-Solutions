class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int i = 0, j = 1;
        for(int k = 2; k < nums.size(); k = j+1) {
            // checking two sides of triangle greater than third side
            if(nums[k] + nums[j] > nums[i]) {
                return nums[i] + nums[j] + nums[k];
            }
            
            i++;
            j++;
        }
        return 0;
    }
};
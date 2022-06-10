class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, two = nums.size()-1;
        int i = 0;
        while(i <= two) {
            if(nums[i] == 0) {
                swap(nums[i], nums[zero]);
                zero++;
            }
            if(nums[i] == 2) {
                swap(nums[i], nums[two]);
                two--;
            }
            else
                i++;
        }
    }
};

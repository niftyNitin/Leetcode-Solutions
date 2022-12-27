class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element = nums[0];
        for(int i : nums) {
            if(count == 0)  element = i;
            count += (i == element) ? 1 : -1;
        }
        return element;
    }
};
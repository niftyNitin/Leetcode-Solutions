class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3)     return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for(int i = 2; i < n; i++) {
            int l = 0, r = i-1;
            while(l < r) {
                int sum_two_sides = nums[l] + nums[r];
                if(sum_two_sides > nums[i]) {
                    count += (r-l);
                    r--;
                }
                else l++;
            }
        }
        return count;
    }
};
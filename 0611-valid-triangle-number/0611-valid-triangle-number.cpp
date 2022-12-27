class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)    continue;
            for(int j = i+1; j < nums.size(); j++) {
                int id = lower_bound(nums.begin(), nums.end(), nums[i]+nums[j]) - nums.begin();
                id--;
                ans += (id-j);
            }
        }
        
        return ans;
    }
};
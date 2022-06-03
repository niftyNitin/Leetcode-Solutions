class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();        
        vector<vector<int>> res;
        if(n < 3)    return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= n-3; i++) {
            if(i == 0 or nums[i] != nums[i-1]) {
                int l = i+1, r = n-1;
                while(l < r) {
                    int target = nums[i] + nums[l] + nums[r];
                    if(target > 0) --r;
                    else if(target < 0) ++l;
                    else {
                        vector<int> v = {nums[i], nums[l], nums[r]};
                        res.push_back(v);
                        ++l;
                        while(nums[l] == nums[l-1] and l < r)   ++l;
                    }
                }
            }            
        }
        return res;
    }
};
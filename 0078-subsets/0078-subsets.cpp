class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = 1 << nums.size();
        for(int mask = 0; mask < n; mask++) {
            vector<int> subset;
            for(int i = 0; i < nums.size(); i++) {
                if(mask & (1<<i))   subset.push_back(nums[i]);
            }
            res.push_back(subset);
        }
        return res;
    }
};
class Solution {
public:
    void findSubs(vector<int> &nums, vector<int> ds, vector<vector<int>> &ans, int i) {
        if(i == nums.size()) {
            ans.push_back(ds);
            return;
        }
        
        // take
        ds.push_back(nums[i]);
        findSubs(nums, ds, ans, i+1);
        // skipping duplicates
        while(i+1 < nums.size() and nums[i] == nums[i+1])   i++;
        // not take
        ds.pop_back();
        findSubs(nums, ds, ans, i+1);
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findSubs(nums, ds, ans, 0);
        return ans;
    }
};
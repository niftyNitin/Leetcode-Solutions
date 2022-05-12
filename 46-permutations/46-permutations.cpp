class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        vector<int> freq(n, 0);
        solve(nums, v, freq);
        return ans;
    }
    
    void solve(vector<int> &nums, vector<int> &v, vector<int> freq) {
        if(v.size() == nums.size()) {
            ans.push_back(v);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(!freq[i]) {
                v.push_back(nums[i]);
                freq[i] = 1;
                solve(nums, v, freq);
                freq[i] = 0;
                v.pop_back();
            }
        }
    }
};
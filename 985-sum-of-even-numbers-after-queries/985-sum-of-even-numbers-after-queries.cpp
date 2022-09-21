class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int esum = 0;
        for(int i : nums) {
            if(i % 2 == 0)  esum += i;
        }
        
        vector<int> ans;
        for(auto q : queries) {
            int val = q[0];
            int idx = q[1];
            if(nums[idx] % 2 == 0)  esum -= nums[idx];
            nums[idx] += val;
            if(nums[idx] % 2 == 0)  esum += nums[idx];
            ans.push_back(esum);
        }
        return ans;
    }
};
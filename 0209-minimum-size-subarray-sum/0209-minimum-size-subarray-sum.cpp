class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> pre;
        pre.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            pre.push_back(pre[i-1] + nums[i]);
        }
        
        if(pre.back() < target) return 0;
        
        int ans = INT_MAX;
        for(int i = 0; i < pre.size(); i++) {
            if(pre[i] < target)     continue;
            int diff = pre[i] - target;
            int id = lower_bound(pre.begin(), pre.end(), diff) - pre.begin();
            if(id == pre.size())    continue;
            if(pre[id] == diff)     ans = min(ans, i-id);
            else {
                id--;
                ans = min(ans, i-id);
            }
        }
        
        return ans;
    }
};
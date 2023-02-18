class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int minElement = *min_element(nums.begin(), nums.end());
        int maxElement = *max_element(nums.begin(), nums.end());
        
        int gap = ceil((maxElement-minElement) * 1.0 / (nums.size()-1));
        if(gap < 1)   gap = 1;
        vector<pair<int,int>> buckets(nums.size(), {INT_MAX, INT_MIN});
        for(int i = 0; i < nums.size(); i++) {
            int pos = (nums[i] - minElement) / gap;
            buckets[pos].first = min(buckets[pos].first, nums[i]);
            buckets[pos].second = max(buckets[pos].second, nums[i]);
        }
        
        int ans = 0, prevMax = buckets[0].second;        
        for(int i = 1; i < nums.size(); i++) {
            if(buckets[i].first == INT_MAX) continue;
            ans = max(ans, buckets[i].first-prevMax);
            prevMax = buckets[i].second;
        }
        return ans;      
    }
};
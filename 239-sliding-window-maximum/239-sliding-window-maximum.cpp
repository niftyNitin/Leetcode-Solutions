class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        
        int b = 0, e = 0;
        while(e-b+1 < k)    pq.push({nums[e], e}), e++;
        
        for(int i = e; i < nums.size(); i++) {
            pq.push({nums[e], e});
            while(pq.top().second < b)  pq.pop();
            res.push_back(pq.top().first);
            e++;
            b++;
        }
        return res;
    }
};
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> times;
        int n = plantTime.size();
        for(int i = 0; i < n; i++) {
            times.push_back({growTime[i], plantTime[i]});
        }
        
        sort(times.rbegin(), times.rend());
        
        int ans = 0, curr_sum = 0;
        for(auto i : times) {
            curr_sum += i.second;
            ans = max(ans, curr_sum+i.first);
        }
        
        return ans;
    }
};

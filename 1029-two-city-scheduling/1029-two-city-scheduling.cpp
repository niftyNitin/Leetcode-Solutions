class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int>> diff;
        int n = costs.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int d = costs[i][1] - costs[i][0];
            diff.push_back({d, i});
        }
        
        sort(diff.begin(), diff.end());
        for(int i = 0; i < n/2; i++) {
            ans += costs[diff[i].second][1];
        }
        
        for(int i = n/2; i < n; i++) {
            ans += costs[diff[i].second][0];
        }
        
        return ans;
    }
};
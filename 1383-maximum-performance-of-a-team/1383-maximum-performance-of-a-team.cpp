class Solution {
public:
    int mod = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({efficiency[i], speed[i]});
        }
        
        sort(v.rbegin(), v.rend());
        long long ans = INT_MIN, sp = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++) {
            sp += v[i].second;
            pq.push(v[i].second);
            if(pq.size() > k) {
                sp -= pq.top();
                pq.pop();
            }
            ans = max(ans, sp*v[i].first);
        }
        
        return ans % mod;
    }
};
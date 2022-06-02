class Solution {
public:
    static bool comp(pair<int,int> &a, pair<int,int> &b) {
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto i : nums)  mp[i]++;
        
        vector<pair<int,int>> v;
        for(auto i : mp) {
            v.push_back({i.first, i.second});
        }
        
        sort(v.begin(), v.end(), comp);
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(v[i].first);
        }
        
        return res;
    }
};
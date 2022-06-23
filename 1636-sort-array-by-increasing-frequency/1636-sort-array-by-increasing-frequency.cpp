class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        if(a.first < b.first)   return true;
        if(a.first == b.first)
            return a.second > b.second;
        return false;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> frequency;
        for(auto element : nums) {
            frequency[element]++;
        }
        
        vector<pair<int,int>> v;
        for(auto i : frequency) {
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end(), cmp);
        
        vector<int> res;
        for(auto i : v) {
            int x = i.first;
            while(x--) {
                res.push_back(i.second);
            }
        }
        return res;
    }
};
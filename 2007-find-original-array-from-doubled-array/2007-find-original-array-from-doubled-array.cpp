class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<float,int> mp;
        sort(changed.begin(), changed.end());
        vector<int> ans;
        for(int i : changed) {
            if(i%2 == 1) {
                mp[i]++;
                continue;
            }
            if(mp[i/2] > 0) {
                mp[i/2]--;
                ans.push_back(i/2);
            }
            else {
                mp[i]++;
            }
        }
        for(auto i : mp) {
            if(i.second != 0)   return {};
        }
        return ans;
    }
};
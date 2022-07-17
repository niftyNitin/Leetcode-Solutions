class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int n = nums[0].size();
        unordered_map<int, vector<pair<string,int>>> mp;
        for(int i = 0; i < queries.size(); i++) {
            vector<pair<string, int>> v;
            int trim = queries[i][1];
            int k = queries[i][0];
            if(mp.find(trim) == mp.end()) {
                for(int j = 0; j < nums.size(); j++) {
                    string trimmed = nums[j].substr(n-trim);
                    v.push_back({trimmed, j});
                }
                sort(v.begin(), v.end());
                mp[trim] = v;
            }
            else {
                v = mp[trim];
            }
            res.push_back(v[k-1].second);
        }
        return res;
    }
};
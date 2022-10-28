class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> mp;
        
        for(int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        
        for(auto i : mp) {
            vector<string> temp;
            for(int j = 0; j < i.second.size(); j++)
                temp.push_back(strs[i.second[j]]);
            ans.push_back(temp);
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char,int> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }
        
        int i = 0, j = 0;
        int last = -1;
        while(j < s.size()) {
            last = max(last, mp[s[j]]);
            if(j < last) {
                j++;
            }
            else {
                ans.push_back(j-i+1);
                j++;
                i = j;
            }
        }
        return ans;
    }
};
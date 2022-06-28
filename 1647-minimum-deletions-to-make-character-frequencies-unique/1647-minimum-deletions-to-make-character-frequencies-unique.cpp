class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26);
        for(auto c : s) {
            v[c-'a']++;
        }
        sort(v.begin(), v.end(), greater<int>());
        unordered_map<int, int> mp;
        for(auto i : v) {
            if(i)   mp[i]++;
        }
        
        int res = 0;
        for(auto i : v) {
            if(mp[i] > 1) {
                int temp = i;
                while(temp--) {
                    if(mp[temp] == 0){
                        mp[i]--;
                        if(temp)    mp[temp]++;
                        res += (i-temp);
                        break;
                    }
                }
            }
        }
        return res;
    }
};
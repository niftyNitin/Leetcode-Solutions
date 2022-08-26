class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())   return false;
        vector<int> mp(26, 0);
        vector<int> mp2(26, 0);
        for(char c : s1) {
            mp[c-'a']++;
        }

        int i = 0, j = 0;
        while(j < s1.size()) {
            mp2[s2[j]-'a']++;
            j++;
        }

        if(mp2 == mp)   return true;
        while(j < s2.size()) {
            mp2[s2[i]-'a']--;
            mp2[s2[j]-'a']++;
            if(mp2 == mp)   return true;
            i++;
            j++;
        }
        
        return false;
    }
};
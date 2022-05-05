class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int ans = 0;
        int currlength = 0;
        for(int i = 0; i < s.length(); i++) {
            currlength = min(i + 1 - m[s[i]], currlength + 1);
            ans = max(ans, currlength);
            m[s[i]] = i + 1;            
        }
        
        return ans;
    }
};
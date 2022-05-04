class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            string s = strs[i];
            int n = min(s.length(), pre.length());
            string t = "";
            for(int j = 0; j < n; j++) {
                if(pre[j] == s[j])
                    t += pre[j];
                else
                    break;
            }
            pre = t;
        }
        
        return pre;
    }
};
class Solution {
    vector<string> ans;
    bool check(string s) {
        if(s.size() > 3 or s.empty() or (s.size() > 1 and s[0] == '0'))
            return false;
        if(stoi(s) > 255)   return false;
        return true;
    }
    
    void solve(string s, int i, int dots, string ds) {
        if(dots == 3) {
            if(check(s.substr(i)))
                ans.push_back(ds+s.substr(i));
            return;
        }
        
        for(int j = i; j < s.size(); j++) {
            if(check(s.substr(i, j-i+1))) {
                ds.push_back(s[j]);
                ds.push_back('.');
                solve(s, j+1, dots+1, ds);
                ds.pop_back();
            }
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 27)   return {};
        solve(s, 0, 0, "");
        return ans;
    }
};
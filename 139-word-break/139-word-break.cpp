class Solution {
public:
    int dp[301];
    bool helper(string &s, int start, unordered_set<string> &dict) {
        if(start == s.size())   return 1;
        
        if(dp[start] != -1)     return dp[start];
        bool flag = false;
        for(int i = start+1; i <= s.size(); i++) {
            string sub = s.substr(start, i-start);
            if(dict.count(sub) == 1) {
                flag = flag | helper(s, i, dict);
            }
        }
        
        return dp[start] = flag;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        vector<string> ds;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return helper(s, 0, dict);
    }
};
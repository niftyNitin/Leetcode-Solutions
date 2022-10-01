class Solution {
public:
    int solve(string s, int i, vector<int> &dp) {
        if(i == s.size())   return 1;
        if(i > s.size())    return 0;
        
        if(s[i] == '0')     return 0;
        
        if(dp[i] != -1)     return dp[i];
        int x = 0, y = 0;
        string sub1 = s.substr(i, 2);
        string sub2 = s.substr(i, 1);
        if(stoi(sub1) <= 26)    x = solve(s, i+2, dp);
        if(stoi(sub2) <= 26)    y = solve(s, i+1, dp);
        
        return dp[i] = x + y;
    }
    
    int numDecodings(string s) {
        vector<int> dp(101, -1);
        return solve(s, 0, dp);
    }
};
class Solution {
public:
    unordered_map<string, int> mp;
    vector<int> dp;
    bool solve(string s, int idx){
        if(idx == s.length()) return true;
        if(s.length() == 0) return true;
        if(mp.count(s)) return true;
        
        if(dp[idx] != -1)   return dp[idx];
        string first = "";
        for(int i=idx; i<s.length(); i++){
            first += s[i];
            if(mp.count(first) and solve(s, i+1)){
                return dp[idx] = true;
            } 
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(auto word: wordDict)
            mp[word]++;
        dp.resize(s.length() + 1, -1);
        return solve(s, 0);
    }
};
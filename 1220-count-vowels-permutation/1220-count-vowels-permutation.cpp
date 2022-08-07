class Solution {
public:
    int mod = 1e9+7;
    int ans = 0;
    
    int solve(int len, int n, char last, unordered_map<char, vector<char>> &mp, vector<vector<int>> &dp) {
        if(len == n)    return 1;
        auto next = mp[last];
        
        int x = last-'a';
        if(dp[len][x] != -1) return dp[len][x];
        int ans = 0;
        
        for(char i : next) {
            ans += solve(len+1, n, i, mp, dp);
            ans = ans % mod;
        }
        return dp[len][x] = ans;
    }
    
    int countVowelPermutation(int n) {
        string start = "aeiou";
        unordered_map<char, vector<char>> mp;
        vector<vector<int>> dp(n, vector<int>(26, -1));
        mp['a'] = {'e'};
        mp['e'] = {'a', 'i'};
        mp['i'] = {'a', 'e', 'o', 'u'};
        mp['o'] = {'i', 'u'};
        mp['u'] = {'a'};
        int ans = 0;
        for(char c : start) {
            ans = ((ans%mod) + solve(1, n, c, mp, dp)) % mod;
        }
        return ans%mod;
    }
};
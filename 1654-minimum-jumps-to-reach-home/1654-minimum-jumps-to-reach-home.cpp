class Solution {
    unordered_set<int> fb;
    int dp[7001][2];
    int solve(int pos, int &a, int &b, int &x, int back) {
        cout << pos << ' ' << back << endl;
        if(pos == x)                 return 0;
        if(pos < 0 or pos > 6000 or fb.count(pos))    return 1e9;
        if(dp[pos][back] != -1)      return dp[pos][back];
        
        dp[pos][back] = 1 + solve(pos+a, a, b, x, 0);
        if(!back)   dp[pos][back] = min(dp[pos][back], 1 + solve(pos-b, a, b, x, 1));
        
        return dp[pos][back];        
    }
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(int &i : forbidden)    fb.insert(i);
        memset(dp, -1, sizeof(dp));
        int res = solve(0, a, b, x, 0);
        return (res >= 1e9) ? -1 : res;
    }
};
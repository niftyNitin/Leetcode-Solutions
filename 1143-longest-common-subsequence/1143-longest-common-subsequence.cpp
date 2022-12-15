class Solution {
public:
    int dp[1002][1002];
    int helper(string &text1, string &text2, int i, int j) {
        if(i < 0 or j < 0)
            return 0;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        if(text1[i] == text2[j])
            return dp[i][j] = 1 + helper(text1, text2, i-1, j-1);
                
        int a = helper(text1, text2, i, j-1);
        int b = helper(text1, text2, i-1, j);
        return dp[i][j] = max(a,b);
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return helper(text1, text2, text1.size()-1, text2.size()-1);
    }
};
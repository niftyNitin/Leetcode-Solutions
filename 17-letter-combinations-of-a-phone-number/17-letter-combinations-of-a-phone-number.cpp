class Solution {
public:
    vector<string> ans;
    string s[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int n;
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if(n == 0)  return {};
        solve(0, digits, "");  
        return ans;
    }
    
    void solve(int i, string digits, string res) {
        if(i == n) {
            ans.push_back(res);
            return;
        }
        
        for(int j = 0; j < s[digits[i]-'0'].size(); j++) {
            solve(i+1, digits, res + s[digits[i]-'0'][j]);
        }
    }
};
class Solution {
    vector<string> ans;
    void solve(int i, string &digits, string &s, vector<string> &com) {
        if(i >= digits.size()) {
            if(s != "") ans.push_back(s);
            return;
        }
        
        for(char c : com[digits[i] - '0']) {
            s.push_back(c);
            solve(i+1, digits, s, com);
            s.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> com{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s = "";
        solve(0, digits, s, com);
        return ans;
    }
};
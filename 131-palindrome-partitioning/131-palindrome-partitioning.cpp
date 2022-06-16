class Solution {
public:
    bool validPalindrome(string s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end])  return false;
            start++;
            end--;
        }
        return true;        
    }
    
    void palpart(string s, vector<vector<string>> &res, vector<string> &path, int index) {
        if(index == s.size()) {
            res.push_back(path);
        }
        
        for(int i = index; i < s.size(); i++) {
            if(validPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i-index+1));
                palpart(s, res, path, i+1);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ds;
        palpart(s, res, ds, 0);
        return res;
    }
};
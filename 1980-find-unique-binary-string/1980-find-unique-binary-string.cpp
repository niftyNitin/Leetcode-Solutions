class Solution {
public:
    string res = "";
    void solve(unordered_set<string> &st, string &s, int &n) {
        if(s.size() == n) {
            if(st.find(s)==st.end())    res = s;
            return;
        }
        
        s.push_back('1');
        solve(st, s, n);
        s.pop_back();
        s.push_back('0');
        solve(st, s, n);
        s.pop_back();
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());
        string s = "";
        int n = nums.size();
        solve(st, s, n);
        return res;
    }
};
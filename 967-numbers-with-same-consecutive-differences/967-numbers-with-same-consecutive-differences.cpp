class Solution {
public:
    void solve(int n, int k, vector<int> &ans, string s) {
        if(s.size() == n) {
            ans.push_back(stoi(s));
            return;
        }
        if(s.size() > n)    return;
        int x = s.back() - '0';
        if(x + k <= 9) {
            string c = "";
            c += x + k + '0';
            solve(n, k, ans, s+c);            
        }
        if(x - k >= 0 and k != 0) {
            string c = "";
            c += x - k + '0';
            solve(n, k, ans, s+c);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i = 1; i <= 9; i++) {
            string s = "";
            s += i + '0';
            solve(n, k, ans, s);
        }
        return ans;
    }
};
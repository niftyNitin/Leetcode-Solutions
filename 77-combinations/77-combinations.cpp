class Solution {
public:
    void solve(int n, int k, vector<int> &ds, vector<vector<int>> &ans, string &mask) {
        if(ds.size() == k) {
            ans.push_back(ds);
            return;
        }
        
        int x = 1;
        if(!ds.empty()) x = ds.back();
        for(int i = x; i <= n; i++) {
            if(mask[i-1] == '1')    continue;
            ds.push_back(i);
            mask[i-1] = '1';
            solve(n, k, ds, ans, mask);
            ds.pop_back();
            mask[i-1] = '0';
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        string mask = "";
        for(int i = 0; i < n; i++)
            mask += '0';
        solve(n, k, ds, ans, mask);
        return ans;
    }
};
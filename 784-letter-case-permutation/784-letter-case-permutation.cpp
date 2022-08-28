class Solution {
public:
    vector<string> ans;
    
    void solve(string &s, string &ds, int idx, int n){
        if(ds.length() == n){
            ans.push_back(ds);
            return;
        }
        
        if(isdigit(s[idx])){
            ds.push_back(s[idx]);
            solve(s,ds,idx+1,n);
            ds.pop_back();
        }
        else{
            char c = s[idx];
            if(islower(c)) {
                ds.push_back(toupper(c));
                solve(s,ds,idx+1,n);
                ds.pop_back();
            }
            else {
                ds.push_back(tolower(c));
                solve(s,ds,idx+1,n);
                ds.pop_back();
            }
            ds.push_back(c);
            solve(s,ds,idx+1,n);
            ds.pop_back();
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        string ds = "";
        solve(s,ds,0,s.length());
        return ans;
    }
};
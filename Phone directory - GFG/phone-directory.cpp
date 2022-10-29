//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        map<string, set<string>> mp;
        for(int i = 0; i < n; i++) {
            string ss = contact[i];
            string pre = "";
            for(char c : ss) {
                pre += c;
                mp[pre].insert(ss);
            }
        }
        
        vector<vector<string>> ans;
        string prefix = "";
        for(char c : s) {
            prefix += c;
            auto res = mp[prefix];
            if(res.size() == 0) ans.push_back({"0"});
            else ans.push_back(vector<string>(res.begin(), res.end()));
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void words(int start, int end, string s, unordered_set<string> &dict, vector<string> &res, vector<string> temp) {
        if(start >= s.size())   {
        //     return;
        // if(temp.size() == n) {
            string ss = "";
            for(string x : temp)    ss += x + " ";
            ss.pop_back();
            res.push_back(ss);
            return;
        }
        
        string word = "";
        for(int i = end; i < s.size(); i++) {
            word = s.substr(start, i-start+1);
            // cout << word << endl;
            if(dict.find(word) != dict.end()) {
                // cout << word << endl;
                temp.push_back(word);
                words(i+1, i+1, s, dict, res, temp);
                temp.pop_back();
            }
        }
    }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string> res;
        unordered_set<string> st;
        
        vector<string> temp = {};
        for(string word : dict) {
            st.insert(word);
        }
        
        words(0, 0, s, st, res, temp);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
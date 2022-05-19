// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string s1, string s2) {
        // code here
        unordered_map<char, int> mp;
        int c = 0;
        for(auto i : s1) {
            mp[i] = c;
            c++;
        }
        
        int ans = 0;
        int ind = 0;
        for(auto i : s2) {
            int x = mp[i];
            ans += abs(x-ind);
            ind = x;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends
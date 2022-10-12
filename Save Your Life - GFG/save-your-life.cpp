//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          unordered_map<char,int> mp;
          for(int i = 0; i < n; i++) {
              mp[x[i]] = b[i];
          }
          
          string res = "";
          int max_total = INT_MIN, max_here = 0;
          int i = 0, j = 0;
          for(int j = 0; j < w.size(); j++) {
            char c = w[j];
            
            if(mp.count(c))
              max_here += mp[c];
            else
              max_here += (int)c;
            
            if(max_here > max_total) {
                max_total = max_here;
                res = w.substr(i, j-i+1);
            }
            if(max_here < 0) {
                max_here = 0;
                i = j+1;
            }
          }
          
          return res;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends
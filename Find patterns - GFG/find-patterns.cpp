//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string s, string w){
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            int j = 0;
            for(int k = i; k < s.size(); k++) {
                if(j < w.size() and s[k] == w[j]) j++, s[k] = '_';
            }
            
            if(j == w.size())   ans++;   
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e8;
    int solve(int n, int dp[]) {
        if(n == 0)  return 1;
        if(n < 0)   return 0;
        if(dp[n] != -1) return dp[n];
        int a = solve(n-1, dp);
        int b = solve(n-2, dp);
        
        return dp[n] = (a+b) % mod;
    }
  
    int fillingBucket(int n) {
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        return solve(n, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
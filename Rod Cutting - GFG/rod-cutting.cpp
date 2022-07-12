// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int dp[1001][1001];
    int helper(int price[], int n, int i) {
        if(i > n or n <= 0)  return 0;
        
        if(dp[i][n] != -1)  return dp[i][n];
        int a = price[i-1] + helper(price, n-i, i);
        int b = helper(price, n, i+1);
        return dp[i][n] = max(a, b);
    }
  
    int cutRod(int price[], int n) {
        //code here
        memset(dp, -1, sizeof(dp));
        return helper(price, n, 1);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
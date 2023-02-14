//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int solve(vector<vector<int>> &colors, int i, int n, int prev, vector<vector<int>> &dp) {
        if(i >= n)  return 0;
        if(dp[i][prev] != -1)   return dp[i][prev];
        
        int mini = INT_MAX;
        for(int x = 0; x < 3; x++) {
            if(x != prev) {
                int sum = colors[i][x] + solve(colors, i+1, n, x, dp);
                mini = min(mini, sum);
            }
        }
        
        return dp[i][prev] = mini;
    }

    int minCost(vector<vector<int>> &colors, int n) {
        vector<vector<int>> dp(n+1, vector<int> (4, -1));
        return solve(colors, 0, n, 3, dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends
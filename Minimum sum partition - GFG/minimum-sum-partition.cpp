//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    int solve(int i, int sum1, int sum2, int arr[], int n, vector<vector<int>> &dp) {
        if(i >= n)  return abs(sum1-sum2);
        if(dp[i][abs(sum1-sum2)] != -1) return dp[i][abs(sum1-sum2)];
        int a = solve(i+1, sum1+arr[i], sum2, arr, n, dp);
        int b = solve(i+1, sum1, sum2+arr[i], arr, n, dp);
        
        return dp[i][abs(sum1-sum2)] = min(a,b);
    }
  
	int minDifference(int arr[], int n)  { 
	    int total = accumulate(arr, arr+n, 0);
	    vector<vector<int>> dp(n+1, vector<int> (total+1, -1));
	    return solve(0, 0, 0, arr, n, dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
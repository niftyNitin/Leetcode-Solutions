//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        unordered_map<long long, int> mp;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
            if(sum == k)    ans = i+1;
            else if(mp.count(sum-k)) {
                ans = max(ans, i-mp[sum-k]);
            }
            if(mp.count(sum) == 0)  mp[sum] = i;
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
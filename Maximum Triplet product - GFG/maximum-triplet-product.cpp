//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	long long ans = 0;
    	long long maxp = INT_MIN, maxp2 = INT_MIN, maxp3 = INT_MIN;
    	long long maxn = 0, maxn2 = 0;
    	
    	for(int i = 0; i < n; i++) {
    	    long long x = arr[i];
	        if(x > maxp) {
    	        maxp3 = maxp2;
    	        maxp2 = maxp;
    	        maxp = x;
    	    }
    	    else if(x > maxp2) {
    	        maxp3 = maxp2;
    	        maxp2 = x;
    	    }
    	    else if(x > maxp3) {
    	        maxp3 = x;
    	    }
	        
	        if(x < maxn) {
	            maxn2 = maxn;
	            maxn = x;
	        }
	        else if(x < maxn2) {
	            maxn2 = x;
	        }
    	}
        
        // cout << maxp << " " << maxp2 << " " << maxp3 << " " << maxn << " " << maxn2 << endl;
	    long long prod1 = maxp * maxp2 * maxp3;
	    long long prod2 = (maxn == 0 or maxn2 == 0) ? INT_MIN : (maxp * maxn * maxn2);
	    
	    return max(prod1, prod2 );
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends
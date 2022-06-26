// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        int dist = mp.size();
        unordered_map<int,int> mp2;  
        int ans = 0;
        int j = 0;
        for(int i = 0; i < n; i++) {
            mp2[arr[i]]++;
            while(mp2.size() == dist) {
                mp2[arr[j]]--;
                if(mp2[arr[j]] < 1)  mp2.erase(arr[j]);
                j++;
                ans += (n-i);
            }
        }
        
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends
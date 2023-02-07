//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
            int i=0,j=0;

           int pro = 1;

           int ans =0;

           int maxi=n;

           while(j<n)

           {

               pro=pro*arr[j];

               if(pro<0)

               {

                   maxi=min(maxi,j);

                   ans=max(ans,j-maxi);

                  pro=-1;

               }

               else if(pro==0)

               {

                   maxi=n;

                   i=j+1;

                   pro=1;

               }

               else if(pro>0){

                   ans=max(ans,j-i+1);

                   pro=1;

               }

               j++;

           }

           return ans;

        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends
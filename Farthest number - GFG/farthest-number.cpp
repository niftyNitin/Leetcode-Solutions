// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int n, vector<int>& a){
    vector<int> b(n, INT_MAX), ans(n) ;
    int min_e = INT_MAX ;
    for(int i=n-1 ; i>=0 ; i--){
        auto itr = lower_bound(b.begin()+i+1, b.end(), a[i]) ;
        if(itr == b.begin()+i+1)
            ans[i] = -1 ;
        else{
            itr = prev(itr) ;
            ans[i] = itr - b.begin() ;
        }
        min_e = min(min_e,a[i]) ;
        b[i] = min_e ;
    }
    return ans ;
}
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends
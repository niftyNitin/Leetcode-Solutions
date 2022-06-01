// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int i = 0;
    vector<int> shiftPile(int N, int n){
        // code here
        vector<int> v(2);
        toh(N, n, 1, 3, 2, v);
        return v;
    }
    
    void toh(int N, int n, int start, int final, int aux, vector<int> &v) {
        if(N == 0)  return;
        toh(N-1, n, start, aux, final, v);
        ++i;
        if(i == n){
            v = {start, final};
            return;
        }
        toh(N-1, n, aux, final, start, v);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends
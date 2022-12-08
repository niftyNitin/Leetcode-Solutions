//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<bool> prime;
    
    void sieve() {
        prime.resize(1e6, true);
        int n = 1e6;
        for(int p = 2; p*p <= n; p++) {
            if(prime[p]) {
                for(int i = p*p; i <= n; i+=p)
                    prime[i] = false;
            }   
        }
    }
    
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        sieve();
        vector<int> ans;
        for(int i = 0; i < q; i++){
            int n = 0;
            int sq = sqrt(query[i]);
            for(int p = 2; p <= sq; p++){
                if(prime[p]) n++;   
            }
            ans.push_back(n);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
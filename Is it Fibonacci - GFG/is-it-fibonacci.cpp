//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int n, int k, vector<long long> v) {
        if(n <= k)   return v[n-1];
        vector<long long> a = v;
        long long sum = accumulate(v.begin(), v.end(), 0LL);
        a.push_back(sum);
        int j = 0;
        for(int i = 1; i < n-k; i++) {
            sum *= 2;
            sum -= a[j++];
            a.push_back(sum);
        }
        
        return a.back();
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> v(K);

        for (int i = 0; i < K; i++) cin >> v[i];

        Solution ob;
        cout << ob.solve(N, K, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends
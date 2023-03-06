//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        for(int i = 31; i >= 2; i--) {
            int m1 = 1 << i;
            int m2 = 1 << (i-1);
            int m3 = 1 << (i-2);
            
            if((m1 & n) and (m2 & n) and (m3 & n)) {
                n = n ^ m3;
            }
        }
        return n;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends
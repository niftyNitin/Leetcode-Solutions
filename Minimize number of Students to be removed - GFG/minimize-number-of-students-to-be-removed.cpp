//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int h[], int n) {
        vector<int> v;
        v.push_back(h[0]);
        for(int i = 1; i < n; i++) {
            if(h[i] > v.back())
                v.push_back(h[i]);
            else {
                int idx = lower_bound(v.begin(), v.end(), h[i]) - v.begin();
                v[idx] = h[i];
            }
        }
        return n-v.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
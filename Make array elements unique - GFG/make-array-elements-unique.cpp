//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        for(int i : arr) mp[i]++;
        long long ans = 0;
        for(int i : arr) {
            if(st.count(i) == 0) {
                st.insert(i);
                continue;
            }
            int c = i;
            while(mp[i] != 0)   i++;
            ans += (i-c);
            mp[i]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends
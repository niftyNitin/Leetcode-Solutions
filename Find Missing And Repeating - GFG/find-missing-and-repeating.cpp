//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> nums, int n) {
        vector<int> v;
        for(int i = 0; i < n; i++) {
            nums[abs(nums[i])-1] *= -1;
        }
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) v.push_back(i+1);
        }
        
        bool found = false;
        for(int i = 0; i < n; i++) {
            if(abs(nums[i]) == v[0]) {
                found = true;
                break;
            }
        }
        
        if(!found)  swap(v[0], v[1]);
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
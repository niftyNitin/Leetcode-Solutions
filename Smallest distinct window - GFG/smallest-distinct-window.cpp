// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string s)
    {
        // Your code goes here
        unordered_map<char,int> req;
        for(auto c:s) req[c]=1;
        
        int head = -1, tail = 0;
        int ans=INT_MAX;
        int target=req.size();
        int count=0;
        req.clear();
        
        while(tail < s.size()) {
            while(head+1 < s.size() and count < target) {
                req[s[++head]]++;
                if(req[s[head]] == 1)   count++;
            }
            if(count == target)
                ans = min(ans, head-tail+1);
                
            if(head >= tail) {
                req[s[tail]]--;
                if(req[s[tail]] == 0)   count--;
                tail++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends
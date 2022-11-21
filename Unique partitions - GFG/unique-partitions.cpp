//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void solve(int n, int x, vector<int> &v, vector<vector<int>> &ans) {
	    if(n == 0) {
	        ans.push_back(v);
	        return;
	    }
	    if(n < 0)   return;
	    
	    for(int i = x; i > 0; i--) {
	        v.push_back(i);
	        solve(n-i, i, v, ans);
	        v.pop_back();
	    }
	}
	
    vector<vector<int>> UniquePartitions(int n) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(n, n, v, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int a[], int n) {
        if(n < 4) return {-1, -1, -1, -1};
        unordered_map<int, pair<int, int>> mp;
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int sum = a[i] + a[j];
                pair<int, int> idx = mp[sum];
                
                if(i != j and idx.first == 0 and idx.second == 0)
                    mp[sum] = {i, j};
                else if(i != j and (idx.first != 0 or idx.second != 0)){
                    if(i != idx.first and i != idx.second and j != idx.first and j != idx.second){
                        if(ans.empty())
                            ans.insert(ans.end(), {idx.first, idx.second, i, j});
                        
                        vector<int> temp = {idx.first, idx.second, i, j};
                        for(int i=0; i<4; i++){
                            if(ans[i] < temp[i]) break;
                            else if(ans[i] > temp[i]){
                                ans = temp;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(ans.empty()) return {-1, -1, -1, -1};
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends
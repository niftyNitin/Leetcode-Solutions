// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void printSubsetSum(vector<int> arr, long long sum, int ind, vector<int> &ans) {
        if(ind == arr.size()) {
            ans.push_back(sum);
            return;
        }
        
        // take
        printSubsetSum(arr, sum+arr[ind], ind+1, ans);
        // not take
        printSubsetSum(arr, sum, ind+1, ans);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        printSubsetSum(arr, 0, 0, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
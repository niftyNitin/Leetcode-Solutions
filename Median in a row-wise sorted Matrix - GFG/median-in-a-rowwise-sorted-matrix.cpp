//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int low = 1, high = 2000;
        // int res;
        while(low <= high) {
            int mid = low + (high-low) / 2;
            int sum = 0;
            for(int i = 0; i < r; i++) {
                sum += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            
            if(sum <= (r*c-1)/2) {
                low = mid+1;
                // res = low;
            }
            else {
                high = mid-1;
            }
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends
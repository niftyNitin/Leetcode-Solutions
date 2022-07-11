// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void findPaths(int n, int m, int i, int j, vector<vector<int>> &grid, vector<vector<int>> &res, vector<int> ds) {
        if(i == n-1 and j == m-1) {
            ds.push_back(grid[i][j]);
            res.push_back(ds);
            return;
        }
        
        if(i >= n or j >= m)  return;
        ds.push_back(grid[i][j]);
        findPaths(n, m, i+1, j, grid, res, ds);
        findPaths(n, m, i, j+1, grid, res, ds);
        // ds.pop_back();
    }

    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<vector<int>> res;
        vector<int> ds;
        findPaths(n, m, 0, 0, grid, res, ds);
        return res;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends
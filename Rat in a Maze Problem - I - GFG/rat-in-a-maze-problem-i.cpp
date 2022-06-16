// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void process(int row, int col, string current, vector<string>& ans, 
    vector<vector<int>> &m, int n)
    {
        if(row == n-1 && col == n-1)
        {
            ans.push_back(current);
            return;
        }
        
        vector<int> rowChange{1,-1,0,0};
        vector<int> colChange{0,0,1,-1};
        string dir = "DURL";
        
        for(int index=0; index<4; index++)
        {
            int newRow = row + rowChange[index];
            int newCol = col + colChange[index];

            if(newRow>=0 and newCol>=0 and newRow<n and newCol<n and m[newRow][newCol]==1)
            {
                m[row][col] = 0;
                current.push_back(dir[index]);
                process(newRow, newCol, current, ans, m, n);
                current.pop_back();
                m[row][col] = 1;
            }
        }
        
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        
        if(m[0][0] == 1)    process(0, 0, "", ans, m, n); 
        
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
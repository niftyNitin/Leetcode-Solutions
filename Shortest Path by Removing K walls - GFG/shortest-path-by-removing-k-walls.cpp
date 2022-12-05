//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        queue<vector<int>> q;
        q.push({0,0,k});
        
        int dist = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        vector<vector<vector<bool>>>vis(n+1, vector<vector<bool>>(m+1, vector<bool>(k+1, false)));
        vis[0][0][k] = 1;
        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                auto cell = q.front();
                q.pop();
                int x = cell[0];
                int y = cell[1];
                int ck = cell[2];
                
                if(x == n-1 and y == m-1)   return dist;
                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx < 0 or ny < 0 or nx >= n or ny >= m)  continue;
                    
                    if(mat[nx][ny] == 0 and !vis[nx][ny][ck])   {
                        vis[nx][ny][ck] = true;
                        q.push({nx, ny, ck});
                    }
                    if(mat[nx][ny] == 1 and ck > 0 and !vis[nx][ny][ck-1]) {
                        vis[nx][ny][ck-1] = true;
                        q.push({nx, ny, ck-1});
                    }
                }
            }
            dist++;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
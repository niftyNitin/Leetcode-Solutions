class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
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
                    
                    if(grid[nx][ny] == 0 and !vis[nx][ny][ck])   {
                        vis[nx][ny][ck] = true;
                        q.push({nx, ny, ck});
                    }
                    if(grid[nx][ny] == 1 and ck > 0 and !vis[nx][ny][ck-1]) {
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
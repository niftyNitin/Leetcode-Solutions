class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int> (n, 0));
        queue<vector<int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                vis[i][j] = grid[i][j];
                if(grid[i][j] == 1) q.push({i, j});
            }
        }
        
        int steps = -1;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        while(!q.empty()) {
            int x = q.size();
            while(x--) {
                auto f = q.front();
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int i = f[0] + dx[k];
                    int j = f[1] + dy[k];
                    
                    if(i < 0 or j < 0 or i >= n or j >= n or vis[i][j]) continue;
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
            steps++;
        }
        
        return  steps == 0 ? -1 : steps; 
    }
};
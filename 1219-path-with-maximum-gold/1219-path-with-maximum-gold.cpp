class Solution {
public:
    int dfs(vector<vector<int>> &grid, int x, int y) {
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int m = grid.size();
        int n = grid[0].size();
        int maxGold = 0;
        int temp = grid[x][y];
        grid[x][y] = 0;
        for(int t = 0; t < 4; t++) {
            int nx = x + dx[t];
            int ny = y + dy[t];
            if(nx < 0 or ny < 0 or nx >=m or ny >= n or grid[nx][ny] == 0)   continue;
            maxGold = max(maxGold, temp + dfs(grid, nx, ny));
        }
        maxGold = max(maxGold, temp);
        grid[x][y] = temp;
        return maxGold;
    }
    
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;
                maxGold = max(maxGold, dfs(grid, i, j));
            }   
        }
        return maxGold;
    }
};
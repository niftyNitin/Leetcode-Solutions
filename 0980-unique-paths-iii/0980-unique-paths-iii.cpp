class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(int i, int j, int empty, vector<vector<int>> &grid, int &pathsCount) {
        if(grid[i][j] == 2) {
            if(empty == 0)  pathsCount++;
            return;
        }
        
        grid[i][j] = -1;
        for(int t = 0; t < 4; t++) {
            int x = i + dx[t];
            int y = j + dy[t];
            if(x < 0 or y < 0 or x >= grid.size() or y >= grid[0].size() or grid[x][y] == -1)
                continue;
            dfs(x, y, empty-1, grid, pathsCount);
        }
        grid[i][j] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int pathsCount = 0;
        int startX, startY, empty = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
                if(grid[i][j] == 0)
                    empty++;
            }
        }
        
        dfs(startX, startY, empty+1, grid, pathsCount);
        return pathsCount;
    }
};
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> cache(grid.size(), vector<int>(grid[0].size(), -1));
        
        return uniquePaths(grid, cache, rows, cols, 0, 0);
        
    }
    
    int uniquePaths(vector<vector<int>>& grid, vector<vector<int>>& cache, int rows, int cols, int i, int j) {
        if(i < 0 or j < 0 or i >= rows or j >= cols or grid[i][j] == 1)
            return 0;
        
        if(cache[i][j] != -1)
            return cache[i][j];

        if(i == rows-1 and j == cols-1)
            return 1;
        
        return cache[i][j] = uniquePaths(grid, cache, rows, cols, i, j+1) + uniquePaths(grid, cache, rows, cols, i+1, j);        
    }
};
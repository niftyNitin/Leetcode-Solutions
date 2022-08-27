class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int i, int j) {
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int m = heights.size();
        int n = heights[0].size();
        
        visited[i][j] = true;
        for(int t = 0; t < 4; t++) {
            int nx = i + dx[t];
            int ny = j + dy[t];
            if(nx >= 0 and nx < m and ny >= 0 and ny < n and !visited[nx][ny] and heights[nx][ny] >= heights[i][j])
                dfs(heights, visited, nx, ny);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        vector<vector<int>> res;
        
        for(int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n-1);
        }
        
        for(int i = 0; i < n; i++) {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, m-1, i);
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] and atlantic[i][j])
                    res.push_back({i, j});
            }
        }
        
        return res;
    }
};
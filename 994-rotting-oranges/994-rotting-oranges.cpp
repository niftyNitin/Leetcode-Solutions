class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int total = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) total++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int count = 0, min = 0;
        while(!q.empty()) {
            int k = q.size();
            count += k;
            while(k--) {
                auto [x,y] = q.front();
                q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(nx < 0 or ny < 0 or nx >= n or ny >= m or grid[nx][ny] != 1)
                        continue;
                    q.push({nx,ny});
                    grid[nx][ny] = 2;
                }
            }
            if(!q.empty())  min++;
        }
        
        if(count == total)  return min;
        return -1;
    }
};
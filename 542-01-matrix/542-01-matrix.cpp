class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0)
                    q.push({i,j});
                else
                    mat[i][j] = -1;
            }
        }

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 or ny < 0 or nx >= m or ny >= n or mat[nx][ny] != -1) continue;
                mat[nx][ny] = 1 + mat[x][y];
                q.push({nx,ny});
            }
        }
        
        return mat;
    }
};
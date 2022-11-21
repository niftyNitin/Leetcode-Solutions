class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int ans = 0;
        
        queue<vector<int>> q;
        q.push(entrance);
        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                vector<int> co = q.front();
                q.pop();
                int x = co[0];
                int y = co[1];
                if((co != entrance) and (x == 0 or y == 0 or x == m-1 or y == n-1))
                    return ans;
                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx < 0 or nx >= m or ny < 0 or ny >= n or maze[nx][ny] == '+')
                        continue;
                    maze[nx][ny] = '+';
                    q.push({nx, ny});
                }
            }
            ans++;
        }
        
        return -1;
    }
};
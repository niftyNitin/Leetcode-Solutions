class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> reds(n), blues(n);
        vector<vector<int>> vis(n, vector<int> (2, 0));
        vector<int> ans(n, -1);
        queue<vector<int>> q;
        
        for(auto i : redEdges) {
            reds[i[0]].push_back(i[1]);
        }
        
        for(auto i : blueEdges) {
            blues[i[0]].push_back(i[1]);
        }
        
        
        q.push({0, 0});
        q.push({0, 1});
        int steps = 0;
        
        while(!q.empty()) {
            int x = q.size();
            while(x--) {
                auto node = q.front();
                q.pop();
                
                if(ans[node[0]] == -1)  ans[node[0]] = steps;
                vis[node[0]][node[1]] = 1;
                if(node[1] == 0) {
                    for(auto x : blues[node[0]]) {
                        if(vis[x][1])   continue;
                        q.push({x, 1});
                    }
                } else {
                    for(auto x : reds[node[0]]) {
                        if(vis[x][0])   continue;
                        q.push({x, 0});
                    }
                }
            }
            steps++;
        }
        
        return ans;
    }
};
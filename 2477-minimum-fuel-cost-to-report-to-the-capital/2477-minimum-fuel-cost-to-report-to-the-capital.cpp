class Solution {
    long long ans = 0;
public:
    int dfs(int node, int parent, vector<vector<int>> &g, int &seats) {
        int count = 1;
        for(auto x : g[node]) {
            if(x == parent)     continue;
            count += dfs(x, node, g, seats);
        }
        if(node)    ans += ceil((count * 1.0) / seats);
        return count;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> g(roads.size()+1);
        vector<int> vis(roads.size()+1, 0);
        for(auto i : roads) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        dfs(0, -1, g, seats);
        return ans;
    }
};
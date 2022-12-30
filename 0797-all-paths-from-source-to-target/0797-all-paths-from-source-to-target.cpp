class Solution {
public:
    void dfs(int node, vector<vector<int>> &graph, vector<vector<int>> &allPaths, vector<int> path) {
        path.push_back(node);
        if(node == graph.size()-1) {
            allPaths.push_back(path);
            return;
        }
        
        for(int n : graph[node]) {
            dfs(n, graph, allPaths, path);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> allPaths;
        vector<int> path;
        dfs(0, graph, allPaths, path);
        return allPaths;
    }
};
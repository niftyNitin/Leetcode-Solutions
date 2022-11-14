class Solution {
public:
    int dfs(int idx, vector<bool> &vis, vector<vector<int>> &stones, int n) {
        vis[idx] = true;
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i] and i != idx and (stones[idx][0] == stones[i][0] or stones[idx][1] == stones[i][1])) {
                res += dfs(i, vis, stones, n) + 1;
            }
        }
        
        return res;        
    }
    
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool>vis(n);
        int result = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                result += dfs(i, vis, stones, n);
            }
        }
        
        return result;
    }
};
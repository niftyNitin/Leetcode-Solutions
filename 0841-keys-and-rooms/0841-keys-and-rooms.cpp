class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(int r : rooms[curr]) {
                if(!vis[r]) {
                    vis[r] = 1;
                    q.push(r);
                }
            }
        }
        
        for(int i : vis) {
            if(i == 0)  return false;
        }
        return true;
    }
};
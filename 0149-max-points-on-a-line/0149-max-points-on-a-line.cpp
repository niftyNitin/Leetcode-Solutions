class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        for(int i = 0; i < points.size(); i++) {
            int x1 = points[i][0], y1 = points[i][1];
            unordered_map<double, int> count;
            for(int j = i+1; j < points.size(); j++) {
                int x2 = points[j][0], y2 = points[j][1];
                if(x1 == x2) {
                    count[INT_MAX]++;
                }
                else {
                    double slope = 1.0 * (y2-y1) / (x2-x1);
                    count[slope]++;
                }
            }
            
            for(auto i : count)
                ans = max(ans, i.second+1);
        }
        
        return ans;
    }
};
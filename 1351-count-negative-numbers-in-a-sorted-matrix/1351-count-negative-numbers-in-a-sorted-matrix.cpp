class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        vector<int> v;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            v = grid[i];
            int low = 0, high = n-1;
            while(low < high) {
                int mid = low + (high - low) / 2;
                if(v[mid] < 0)  high = mid;
                else    low = mid + 1;
            }
            
            if(v[low] < 0)  ans += (n - low);
        }
        
        return ans;
    }
};
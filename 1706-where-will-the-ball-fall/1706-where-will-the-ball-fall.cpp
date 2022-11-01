class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> ans;
        for(int j = 0; j < n; j++) {
            int row = 0;
            int col = j;
            while(row != m) {
                int k = grid[row][col];
                if(col+k < 0 or col+k >= n) {
                    ans.push_back(-1);
                    break;
                }
                
                if(k == 1 and grid[row][col+1] == 1) {
                    row++;
                    col++;
                }
                else if(k == -1 and grid[row][col-1] == -1) {
                    row++;
                    col--;
                }
                else {
                    ans.push_back(-1);
                    break;
                }
                if(row == m) {
                    ans.push_back(col);
                    break;
                }
                
            }
        }
        return ans;
    }
};
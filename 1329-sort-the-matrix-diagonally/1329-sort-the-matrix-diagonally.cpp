class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = n-1; i >= 0; i--) {
            int r = i, c = 0;
            vector<int> temp;
            while(r < n and c < m) {
                temp.push_back(mat[r][c]);
                r++;
                c++;
            }
            sort(temp.begin(), temp.end());
            r = i, c = 0;
            int idx = 0;
            while(r < n and c < m) {
                mat[r++][c++] = temp[idx++];
            }
        }
        
        for(int i = 1; i < m; i++) {
            int r = 0, c = i;
            vector<int> temp;
            while(r < n and c < m) {
                temp.push_back(mat[r][c]);
                r++;
                c++;
            }
            sort(temp.begin(), temp.end());
            r = 0, c = i;
            int idx = 0;
            while(r < n and c < m) {
                mat[r++][c++] = temp[idx++];
            }
        }
        return mat;
    }
};
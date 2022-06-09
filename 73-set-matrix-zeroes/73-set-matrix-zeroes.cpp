class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstrow = false, firstcol = false;
        
        // check first row contains zero
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) {
                firstrow = true;
                break;
            }
                
        }
        
        // check first col contains zero
        for(int i = 0; i < n; i++) {
            if(matrix[0][i] == 0) {
                firstcol = true;
                break;
            }
        }
        
        // flag first row and col if that row or col contains 0 (will check except first row and col)
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // if the row or col is flagged then change the element to zero
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 or matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        // if first row contains zero change entire row to zero
        if(firstrow) {
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
        
        // if first col contains zero change entire col to zero
        if(firstcol) {
            for(int i = 0; i < n; i++)
                matrix[0][i] = 0;
        }
    }
};
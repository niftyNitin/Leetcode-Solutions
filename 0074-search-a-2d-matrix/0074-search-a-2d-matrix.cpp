class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // if target is less than all values in matrix        
        if(target < matrix[0][0])   return false;
        int m = matrix.size();
        int n = matrix[0].size();
        
        // putting first value of all rows in a vector for binary search
        vector<int> rows;
        for(int i = 0; i < m; i++)
            rows.push_back(matrix[i][0]);
        
        // gets row whose first index may contain the target
        // or the row above it may have the element
        int id = lower_bound(rows.begin(), rows.end(), target) - rows.begin();
        if(id == m) id--;
        else if(matrix[id][0] == target)    return true;
        else    id--;
        
        // get the id no row from matrix and do another binary search
        vector<int> searchrow = matrix[id];
        int idx = lower_bound(searchrow.begin(), searchrow.end(), target) - searchrow.begin();
        if(idx == n) return false;
        if(searchrow[idx] != target) return false;
        return true;
    }
};
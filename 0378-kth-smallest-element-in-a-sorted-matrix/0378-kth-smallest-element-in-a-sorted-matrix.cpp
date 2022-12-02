class Solution {
public:
    int findCount(vector<vector<int>> &matrix, int target) {
        int n = matrix.size();
        int i = 0, j = n-1, count = 0;
        while(i < n and j >= 0) {
            if(matrix[i][j] > target)   j--;
            else {
                count += j+1;
                i++;
            }
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int count = findCount(matrix, mid);
            if(count < k)  low = mid + 1;
            else    high = mid - 1;
        }
        return low;
    }
};
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n));
        int top = 0;
        int right = n-1;
        int left = 0;
        int bottom = n-1;
        int val = 0;
        while(top <= bottom and left <= right){
            for(int i = left; i <= right; i++)
                ans[top][i] = ++val;
            
            for(int i = top+1; i <= bottom; i++)
                ans[i][right] = ++val;
            
            for(int i = right-1; i >= left; i--)
                ans[bottom][i] = ++val;

            for(int i = bottom-1; i > top; i--)
                ans[i][left] = ++val;
            
            ++left;
            ++top;
            --bottom;
            --right;
        }
        
        return ans;       
        
    }
};
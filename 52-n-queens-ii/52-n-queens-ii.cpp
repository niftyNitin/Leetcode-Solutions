class Solution {
public:
    bool isSafe(int row, int col, vector<string> board, int n) {
        int rowcp = row;
        int colcp = col;
        
        while(row >= 0 and col >= 0) {
            if(board[row][col] == 'Q')  return false;
            row--;
            col--;
        }
        
        row = rowcp;
        col = colcp;
        while(col >= 0) {
            if(board[row][col] == 'Q')  return false;
            col--;
        }
        
        row = rowcp;
        col = colcp;
        while(row < n and col >= 0) {
            if(board[row][col] == 'Q')  return false;
            row++;
            col--;
        }
        return true;
    }
    
    void solve(int col, int &ans, vector<string> &board, int n) {
        if(col == n) {
            ans++;
            return;
        }
        
        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col+1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n, string(n, '.'));
        solve(0, ans, board, n);
        return ans;
    }
};
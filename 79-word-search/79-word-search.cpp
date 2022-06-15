class Solution {
public:
    bool checkword(vector<vector<char>> &board, string word, int i, int row, int col) {
        // if board postion character doesn't match with the string index return false
        if(board[row][col] != word[i])  return 0;
        
        // if we have traversed to the end of the string -> all the charactes till now have matched
        if(i == word.size()-1)  return 1;
        
        // update the seen points on board to avoid repetition
        board[row][col] = '.';
        
        // standing at any position in the middle of the board there are four possibilities of movment left, right, top, bottom
        // top
        if(row-1 >= 0 and board[row-1][col] != '.' and checkword(board, word, i+1, row-1, col))   return 1;
        // left
        if(col-1 >= 0 and board[row][col-1] != '.' and checkword(board, word, i+1, row, col-1))   return 1;
        // bottom
        if(row+1 < board.size() and board[row+1][col] != '.' and checkword(board, word, i+1, row+1, col))   return 1;
        // right
        if(col+1 < board[0].size() and board[row][col+1] != '.' and checkword(board, word, i+1, row, col+1))   return 1;
        
        // backtracking
        board[row][col] = word[i];
        // if all the above cases are not true it is definitely false
        return 0;        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        // storing the row and col size of board
        int row = board.size();
        int col = board[0].size();
        // taking each point on the board as a starting point of the word to check for possibility
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(checkword(board, word, 0, i, j))   return 1;
            }
        }
        return 0;
    }
};
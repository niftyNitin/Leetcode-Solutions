class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row wise check
        for(auto r : board) {
            unordered_set<char> st;
            for(char c : r) {
                if(c == '.')    continue;
                if(st.count(c) == 1)    return false;
                st.insert(c);
            }
        }
        
        // column wise checking
        for(int i = 0; i < 9; i++) {
            unordered_set<char> st;
            for(int j = 0; j < 9; j++) {
                char ch = board[j][i];
                if(ch == '.')    continue;
                if(st.count(ch) == 1)   return false;
                st.insert(ch);                
            }
        }
        
        // checking in each smaller grid
        int x[] = {0, 3, 6};
        int y[] = {0, 3, 6};
        
        for(int i : x) {
            for(int j : y) {
                unordered_set<char> st;
                for(int p = 0; p < 3; p++) {
                    for(int q = 0; q < 3; q++) {
                        char ch = board[i+p][j+q];
                        if(ch == '.')   continue;
                        if(st.count(ch) == 1) return false;
                        st.insert(ch);
                    }
                }
            }
        }
        
        return true;
    }
};
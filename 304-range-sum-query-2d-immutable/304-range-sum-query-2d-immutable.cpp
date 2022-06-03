class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        for(auto i : matrix) {
            vector<int> temp;
            vector<int> v = i;
            temp.push_back(v[0]);
            for(int j = 1; j < v.size(); j++) {
                temp.push_back(temp.back() + v[j]);
            }
            pre.push_back(temp);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++) {
            int x;
            if(col1)
                x = pre[i][col2] - pre[i][col1-1];
            else
                x = pre[i][col2];
            sum += x;
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
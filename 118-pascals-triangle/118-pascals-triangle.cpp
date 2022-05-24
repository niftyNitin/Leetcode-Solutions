class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i = 2; i <= numRows; i++) {
            vector<int> v = ans.back();
            vector<int> temp;
            temp.push_back(v[0]);
            for(int j = 1; j < v.size(); j++) {
                temp.push_back(v[j] + v[j-1]);
            }
            temp.push_back(v.back());
            ans.push_back(temp);
        }
        
        return ans;
    }
};
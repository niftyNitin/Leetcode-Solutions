class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        for(int i = 1; i <= rowIndex; i++) {
            vector<int> temp;
            temp.push_back(*ans.begin());
            for(int j = 1; j < ans.size(); j++) {
                temp.push_back(ans[j]+ans[j-1]);
            }
            temp.push_back(*ans.rbegin());
            ans = temp;
        }
        
        return ans;
    }
};
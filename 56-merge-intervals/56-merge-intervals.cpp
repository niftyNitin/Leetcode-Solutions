class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end());
        vector<vector<int>> ans;
        ans.push_back(inter[0]);
        for(int i = 1; i < inter.size(); i++) {
            int pstart = ans.back()[0];
            int pend = ans.back()[1];
            int cstart = inter[i][0];
            int cend = inter[i][1];
            
            if(cstart <= pend) {
                ans.pop_back();
                ans.push_back({pstart, max(cend,pend)});
            }
            else if(cstart > pend) {
                ans.push_back(inter[i]);
            }
        }
        return ans;
    }
};
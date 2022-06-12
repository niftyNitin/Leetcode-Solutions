class Solution {
public:
    void findSum(vector<vector<int>> &res, vector<int> &candidates, vector<int> ds, int target, int ind, int sum) {
        if(sum == target) {
            res.push_back(ds);
            return;
        }
        
        if(ind == candidates.size())    return;
        if(sum > target)    return;
        
        ds.push_back(candidates[ind]);
        findSum(res, candidates, ds, target, ind, sum+candidates[ind]);
        ds.pop_back();
        findSum(res, candidates, ds, target, ind+1, sum);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        findSum(res, candidates, ds, target, 0, 0);
        return res;
    }
};
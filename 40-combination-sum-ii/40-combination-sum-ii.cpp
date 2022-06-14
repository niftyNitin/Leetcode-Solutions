class Solution {
public:
    void findCombinations(vector<int> &candidates, long long target, int ind, vector<int> ds, vector<vector<int>> &res) {
        // combination found which sums to target-> push it to result set.
        if(target == 0) {
            res.push_back(ds);
            return;
        }
        // we have reached the end of candidates array, return
        if(ind == candidates.size())    return;
        
        // combination sum is greater than target, simply return
        if(target < 0)  return;
        
        // take
        ds.push_back(candidates[ind]);
        findCombinations(candidates, target-candidates[ind], ind+1, ds, res);
        ds.pop_back();
        // skipping same elements
        while(ind+1 < candidates.size() and candidates[ind] == candidates[ind+1]) ind++;
        // not take
        findCombinations(candidates, target, ind+1, ds, res);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort the initial array to get combinations in sorted format
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ds;
        // calling the recursive function to find combinations
        findCombinations(candidates, target, 0, ds, res);
        return res;
    }
};
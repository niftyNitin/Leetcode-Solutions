class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())    return 0;
        int best = INT_MIN;
        int maxprod = 1, minprod = 1;
        for(int n : nums) {
            if(n < 0)   swap(maxprod, minprod);
            maxprod = max(maxprod*n, n);
            minprod = min(minprod*n, n);
            best = max(best, maxprod);
        }
        return best;
    }
};
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves = 0;
        int n = nums.size();
        int median;
        if(n&1) median = nums[n/2];
        else    median = (nums[n/2] + nums[n/2-1]) / 2;
        for(auto i : nums)
            moves += abs(i - median);
        
        return moves;
    }
};
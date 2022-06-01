class Solution {
public:
    int minMoves(vector<int>& nums) {
        int c = 0;
        int k = 1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = n-1; i >= 1; i--) {
            int diff = nums[i] - nums[i-1];
            c += (diff*k);
            k++;
        }
        return c;
    }
};
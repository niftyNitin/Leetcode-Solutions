class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i : nums) {
            ones = ones ^ i;
            ones = ones & ~twos;
            
            twos = twos ^ i;
            twos = twos & ~ones;
        }
        return ones;
    }
};
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for(int i = 1; i < nums.size()-1; i++){
            if(2*nums[i] == nums[i-1] + nums[i+1])  cnt++, ans += cnt;
            else cnt = 0;
        }
        
        return ans;
    }
};
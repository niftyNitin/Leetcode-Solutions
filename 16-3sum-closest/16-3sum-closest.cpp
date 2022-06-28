class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = INT_MAX;
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n-2; i++) {
            int start = i+1, end = n-1;
            while(start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if(abs(sum-target) < closest)
                    closest = abs(sum-target), res = sum;
                
                if(sum <= target)    start++;
                else    end--;
            }
        }
        return res;
    }
};





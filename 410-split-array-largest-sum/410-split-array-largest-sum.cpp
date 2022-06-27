class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while(low < high) {
            int mid = (low + high) / 2;
            int count = 0;
            int sum = 0;
            for(int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                if(sum > mid)   count++, sum = nums[i];
            }
            count++;
            if(count > m)
                low = mid+1;
            else high = mid;
        }
        
        return high;
    }
};
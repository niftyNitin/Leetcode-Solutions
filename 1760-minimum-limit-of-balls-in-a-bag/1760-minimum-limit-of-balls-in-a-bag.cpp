class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while(low < high) {
            int mid = low + (high - low) / 2;
            
            // find number of operations required with max bag size = mid
            int operations = 0;
            for(int i : nums) {
                if(i > mid)
                    operations += ceil((double)i / mid) - 1;
            }
            
            if(operations > maxOperations) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        
        return high;
    }
};
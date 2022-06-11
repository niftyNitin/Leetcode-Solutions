class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // finding total sum of array
        int sum = accumulate(nums.begin(), nums.end(), sum);
        
        // Edge case - if the value of x is more than the sum of the array we cannot reduce x to zero.
        if(sum < x) return -1;
        
        sum -= x;
        // Edge case - if the middle subarray sum is zero then we need to remove elements from entire array.
        if(sum == 0) return nums.size();
        int curr = nums[0];
        int ans = -1; // the number of elements taken in middle array
        // pointers to start and end index of the middle array
        int start = 0, end = 0;
        while(end < nums.size()) {
            // case 1 : when current sum is less than req sum -> move to the next pointer
            if(curr < sum) {
                end++;
                if(end == nums.size())  break;
                curr += nums[end];
            }
            
            // case 2 : when current sum is greater -> remove elements from the start, shift the start pointer.
            else if(curr > sum) {
                curr -= nums[start];
                start++;
            }
            
            // case 3: when current sum is equal to x. update the ans to maximum length of middle array
            // update the start pointer to explore better options
            else {
                int val = end - start + 1;
                ans = max(ans, val);
                curr -= nums[start];
                start++;
            }
            
        }
        
        // if ans is still -1 we haven't found any middle subarray
        // else we return the number of elements from left and right of array
        return (ans == -1) ? -1 : nums.size()-ans;
    }
};
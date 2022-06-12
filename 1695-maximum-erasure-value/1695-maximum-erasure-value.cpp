class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // map to store the last index the character was found
        unordered_map<int, int> last_found;
        
        // a variable to store length of nums array
        int n = nums.size();
        // a variable to keep storing the prefix sum as we traverse along the array
        int sum = 0;
        // a variable to store the maximum score.
        int maxi = 0;
        
        // traverse the array-> keep adding to sum until a repeated character comes up.
        // update the sum by removing the prefix sum from last instance of current character.
        // store the maximum sum in maxi variable.
        int start = 0;
        for(int i = 0; i < n; i++) {
            if(!last_found.count(nums[i]))
                sum += nums[i];
            else {
                // remove the prefix sum till the last instance of character
                maxi = max(maxi, sum);
                int x = last_found[nums[i]];
                if(x >= start) {
                    while(start <= x) {
                        sum -= nums[start];
                        start++;
                    } 
                }
                sum += nums[i];
            }
            last_found[nums[i]] = i;
        }
        
        maxi = max(maxi, sum);
        return maxi;
    }
};


    
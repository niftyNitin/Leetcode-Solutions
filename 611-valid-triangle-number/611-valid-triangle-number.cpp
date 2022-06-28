class Solution {
public:
   int findIdx(int lo, int hi, int target, vector<int> &nums){
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            
            if(nums[mid] >= target){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        return hi;
    }
    
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        // 3 sides of triangle are valid if a + b > c
        // We can select a & b using 2 for loops
        // To check the third side, we first sort the given array
        // Since c > a && c > b, we definitely know that c will lie beyond b's index
        // So, we search for c such that it is the largest value less than (a + b) and return its index
        // From the b's index upto this index will be the choices we can have for our side
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int idx = findIdx(j + 1, n - 1, nums[i] + nums[j], nums);
                
                int k = idx - j;
                ans += k;
            }
        }
        
        return ans;
    }
};
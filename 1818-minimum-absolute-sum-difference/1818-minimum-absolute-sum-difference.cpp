class Solution {
public:
    int bs(vector<int> &arr, int k) {
        int low = 0, high = arr.size()-1, mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(arr[mid] == k)   return arr[mid];
            else if(arr[mid] < k) low = mid + 1;
            else    high = mid - 1;
        }
        
        int closest = arr[mid];
        if(mid - 1 >= 0 and abs(arr[mid-1] - k) < abs(closest - k))             closest = arr[mid-1];
        if(mid + 1 < arr.size() and abs(arr[mid+1] - k) < abs(closest - k))     closest = arr[mid+1];
        
        return closest;
    }
    
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        // make a copy of nums1 and sort it to pick elements from this 
        // replace using binary search
        vector<int> arr = nums1;
        sort(arr.begin(), arr.end());
        int n = nums1.size();
        long long minAbsSum = 0, absSum = 0;
        int mod = 1e9 + 7;
        
        // calculate the absolute sum difference without replacement 
        for(int i = 0; i < n; i++) {
            absSum += abs(nums1[i] - nums2[i]);
        }
        minAbsSum = absSum;
        
        for(int i = 0; i < n; i++) {
            // replace with closest element and find new absolute sum
            long long currAbsSum = absSum - abs(nums1[i] - nums2[i]) + abs(bs(arr, nums2[i]) - nums2[i]);
            
            // store minimum absolute sum
            minAbsSum = min(minAbsSum, currAbsSum);
        }
        
        return minAbsSum % mod;
    }
};
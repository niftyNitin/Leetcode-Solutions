class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0, high = arr.size()-1;
        int n = arr.size();
        // while(low <= high) {
        //     int mid = low + (high-low) / 2;
        //     if(arr[mid] > x)    high = mid-1;
        //     else    low = mid;
        // }
        int r = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r-1;
        vector<int> res;
        while(l >= 0 or r < n) {
            if(res.size() == k) break;
            int diff1 = INT_MAX, diff2 = INT_MAX;
            if(l >= 0)   diff1 = abs(arr[l] - x);
            if(r < n)   diff2 = abs(arr[r] - x);
            if(diff1 <= diff2)   res.push_back(arr[l]), l--;
            else    res.push_back(arr[r]), r++;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int arr[100002] = {0};
        for(int i : nums)   arr[i]++;
        long long ans = 0;
        for(int i = 0; i < 1e5; i++) {
            if(arr[i] == 0) continue;
            int diff = arr[i] - 1;
            arr[i+1] += diff;
            ans += diff;
        }
        
        if(arr[100000] > 1) {
            ans += arr[100000] * (arr[100000] - 1) / 2;
        } 
        return ans;
    }
};
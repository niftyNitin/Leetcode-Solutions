class Solution {
public:
    void merge(vector<int> &nums, int l, int m, int r) {
        vector<int> v;
        int i = l, j = m+1;
        while(i <= m and j <= r) {
            if(nums[i] < nums[j])   v.push_back(nums[i++]);
            else    v.push_back(nums[j++]);
        }
        
        while(i <= m)   v.push_back(nums[i++]);
        while(j <= r)   v.push_back(nums[j++]);
        
        for(int i = l; i <= r; i++) nums[i] = v[i-l];
    }
    
    void sort(vector<int> &nums, int l, int r) {
        if(l < r) {
            int mid = l + (r-l) / 2;
            sort(nums, l, mid);
            sort(nums, mid+1, r);
            merge(nums, l, mid, r);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size()-1);
        return nums;
    }
};
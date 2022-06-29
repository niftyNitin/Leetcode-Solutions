class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int start = 0, end = nums.size()-1;
        while(start < end and end-start+1 != k) {
            int diff1 = abs(nums[start] - x);
            int diff2 = abs(nums[end] - x);
            
            if(diff1 <= diff2)  end--;
            else    start++;            
        }
        vector<int> res;
        for(int i = start; i <= end; i++) res.push_back(nums[i]);
        return res;
    }
};
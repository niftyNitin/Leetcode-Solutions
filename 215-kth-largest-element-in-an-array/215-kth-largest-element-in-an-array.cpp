class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> klargest;
        for(auto i : nums) {
            klargest.push(i);
        }
        
        int x;
        while(k--) {
            x = klargest.top();
            klargest.pop();
        }
        return x;
    }
};
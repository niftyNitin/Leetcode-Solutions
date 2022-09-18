class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size()-1;
        int maxLeft = height[left], maxRight = height[right];
        while(left < right) {
            if(maxLeft < maxRight) {
                left++;
                maxLeft = max(maxLeft, height[left]);
                int water = maxLeft - height[left];
                if(water > 0)   ans += water;
            }
            else {
                right--;
                maxRight = max(maxRight, height[right]);
                int water = maxRight - height[right];
                if(water > 0)   ans += water;
            }
        }
        
        return ans;
    }
};
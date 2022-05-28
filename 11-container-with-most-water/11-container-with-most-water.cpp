class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxa = 0;
        int l = 0, r = height.size()-1;
        while(l < r) {
            int ar = min(height[r], height[l]) * (r - l);
            if(ar > maxa)   maxa = ar;
            if(height[r] > height[l])   l++;
            else    r--;
        }
        
        return maxa;
    }
};
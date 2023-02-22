class Solution {
public:
    bool load(int cap, vector<int> &weights, int &days) {
        int d = 1;
        int c = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] > cap)    return false;
            c += weights[i];
            
            if(c > cap)    c = weights[i], d++;
            if(d > days)    return false;
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1, high = 25*1e6, ans;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(load(mid, weights, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
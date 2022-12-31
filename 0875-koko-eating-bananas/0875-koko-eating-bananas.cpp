class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = 1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            long long hours = 0;
            for(int i : piles) {
                hours += ceil((double)i/mid);
            }
            
            if(hours > h) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};
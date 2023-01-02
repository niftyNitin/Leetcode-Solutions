class Solution {
public:
    int countBouquet(int day, vector<int> &bloomDay, int k) {
        int bouquet = 0;
        int n = bloomDay.size();
        vector<bool> bloomed(n, 0);
        for(int i = 0; i < n; i++) {
            if(bloomDay[i] <= day)  bloomed[i] = 1;
        }

        int cumu = 0;
        for(int i = 0; i < n; i++) {
            if(bloomed[i]) cumu++;
            else {
                bouquet += floor((double)cumu/k);
                cumu = 0;
            }
        }
        bouquet += floor((double)cumu/k);
        return bouquet;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end()), ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int bouquetsPossible = countBouquet(mid, bloomDay, k);
            
            if(bouquetsPossible >= m) {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid + 1;
        }
        
        return ans;
    }
};
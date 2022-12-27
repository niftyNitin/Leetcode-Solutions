class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int count = 0;
        vector<int> rem;
        for(int i = 0; i < capacity.size(); i++) {
            int diff = capacity[i] - rocks[i];
            if(diff == 0)   count++;
            else    rem.push_back(diff);
        }
        
        sort(rem.begin(), rem.end());
        
        for(int i : rem) {
            if(i <= additionalRocks) {
                additionalRocks -= i;
                count++;
            }
        }
        
        return count;
    }
};
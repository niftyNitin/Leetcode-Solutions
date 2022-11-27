class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> penal(n+1);
        
        for(int i = 0; i < n; i++) {
            if(customers[i] == 'N') penal[i+1] = penal[i] + 1;
            else    penal[i+1] = penal[i];
        }
        
        int ycount = 0;
        for(int i = n-1; i >= 0; i--) {
            if(customers[i] == 'Y') ycount++;
            penal[i] += ycount;
        }
        return min_element(penal.begin(), penal.end())-penal.begin();
    }
};
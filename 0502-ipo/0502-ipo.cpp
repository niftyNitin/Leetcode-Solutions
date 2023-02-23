class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        for(int i = 0; i < profits.size(); i++) {
            v.push_back({capital[i], profits[i]});
        }
        
        sort(v.begin(), v.end());
        
        priority_queue<pair<int,int>> pq;
        int i = 0;
        while(k--) {
            while(i < v.size() and v[i].first <= w) {
                pq.push({v[i].second, v[i].first});
                i++;
            }
            
            if(pq.empty())  return w;
            auto x = pq.top();
            pq.pop();
            w += x.first;
        }
        
        return w;
    }
};
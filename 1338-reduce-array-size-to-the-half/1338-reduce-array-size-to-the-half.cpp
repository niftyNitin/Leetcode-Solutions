class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        int c = 0;
        int ans = 0;
        priority_queue<int> pq;
        
        for(int i : arr)
            mp[i]++;
        
        for(auto i : mp) {
            pq.push(i.second);
        }
        
        while(!pq.empty()) {
            c += pq.top();
            pq.pop();
            ans++;
            if(c >= n/2) break;
        }
        
        return ans;
    }
};
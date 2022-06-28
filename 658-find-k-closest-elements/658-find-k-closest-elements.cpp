class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        for(auto element : arr) {
            int diff = abs(element - x);
            min_heap.push({diff, element});
        }
        vector<int> res;
        while(k--) {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
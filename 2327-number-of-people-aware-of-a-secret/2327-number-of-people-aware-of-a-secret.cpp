class Solution {
public:
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9+7;
        if(n < delay)   return 1;
        list<pair<long long,int>> q;
        q.push_back({1,1});
        for(int i = 2; i <= n; i++) {
            if(!q.empty() and q.front().second + forget == i)   q.pop_front();
            long long can_share = 0;
            for(auto x : q) {
                if(x.second + delay <= i)    can_share += x.first;
            }
            can_share = can_share%mod;
            if(can_share) {
                q.push_back({can_share, i});
            }
        }
        long long count = 0;
        for(auto x : q) {
            count += x.first;
            count = count%mod;
        }
        return (int) count;
    }
};
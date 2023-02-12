class Solution {
public:
    vector<vector<int>> substringXorQueries(string ss, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;
        
        for(int i = 1; i <= 32; i++) {
            int l = 0, r = 0;
            while(r < ss.size()) {
                if(r-l+1 == i)  {
                    string bin = ss.substr(l, i);
                    long long dec = 0;
                    long long power = 1;
                    
                    for(int i = bin.size()-1; i >= 0; i--) {
                        int c = bin[i] - '0';
                        dec += (c * power);
                        power = power << 1;
                    }                  
                    
                    if(!mp.count(dec)) mp[dec] = {l, r};
                    r++; l++;
                }
                else    r++;
            }
        }
        
        for(auto q : queries) {
            int n = q[0] ^ q[1];
            if(mp.count(n))   ans.push_back(mp[n]);
            else    ans.push_back({-1, -1});
        }
        
        return ans;
    }
};
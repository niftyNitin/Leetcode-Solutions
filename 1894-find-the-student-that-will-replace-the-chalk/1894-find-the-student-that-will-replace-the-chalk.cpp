class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long long> pre(n);
        pre[0] = chalk[0];
        for(int i = 1; i < chalk.size(); i++) {
            pre[i] = pre[i-1] + chalk[i];
        }
        
        k = k % pre[n-1];
        
        int id = upper_bound(pre.begin(), pre.end(), k) - pre.begin();
        return id;
    }
};
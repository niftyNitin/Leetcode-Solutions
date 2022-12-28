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
        
        int low = 0, high = pre.size()-1, ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(pre[mid] > k) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
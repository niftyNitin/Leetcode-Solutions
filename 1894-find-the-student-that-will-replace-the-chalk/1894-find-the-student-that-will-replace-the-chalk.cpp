class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        vector<long long> pre(chalk.size());
        pre[0] = chalk[0];
        for(int i = 1; i < chalk.size(); i++) {
            pre[i] = pre[i-1] + chalk[i];
        }
        k = k % pre.back();
        int low = 0, high = chalk.size()-1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(pre[mid] > k)  high = mid;
            else    low = mid+1;
        }
        return high;
    }
};
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // vector<long long> pre;
        // pre.push_back(chalk[0]);
        long long sum = 0;
        for(int i = 0; i < chalk.size(); i++) {
            // pre.push_back(pre[i-1] + chalk[i]);
            sum += chalk[i];
        }
        
        // int total = pre.back();
        k = k % sum;
        
        for(int i = 0; i < chalk.size(); i++) {
            if(k < chalk[i])    return i;
            k -= chalk[i];
        }
        return 0;
    }
};
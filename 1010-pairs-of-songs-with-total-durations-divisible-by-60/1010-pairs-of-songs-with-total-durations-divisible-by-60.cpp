class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> f(60);
        int res = 0;
        for(int i : time) {
            res += f[(60-(i%60))%60];
            f[i%60]++;
        }
        return res;
    }
};
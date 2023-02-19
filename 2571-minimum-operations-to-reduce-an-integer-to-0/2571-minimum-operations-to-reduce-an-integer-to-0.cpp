class Solution {
public:
    int minOperations(int n) {
        if(n == 0)  return 0;
        int ans = 0;
        for(int i = 0; i < 30; i++) {
            int mask = 1 << i;
            int temp = n + mask;
            if(__builtin_popcount(temp) < __builtin_popcount(n)) {
                ans++;
                n = temp;
            }
        }
        return ans + __builtin_popcount(n);
    }
};
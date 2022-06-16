class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        for(int i = 2; i <= n; i++) {
            a = b+a;
            swap(b, a);
        }
        return b;
    }
};
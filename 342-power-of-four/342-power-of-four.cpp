class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0)  return false;
        if(n == INT_MIN)    return false;
        int dig = floor(log2(abs(n)) + 1);
        int ones = __builtin_popcount(n);
        
        int zero = dig-ones;
        if(ones == 1 and zero%2 == 0)   return true;
        return false;
    }
};
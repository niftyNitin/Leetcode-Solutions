class Solution {
public:
    double myPow(double x, int nn) {
        double res = 1;
        long long n = nn;
        if(n == 0)  return 1;
        if(n > 0)
            while(n) {
                if(n&1)
                    res = res*x;

                x *= x;
                n >>= 1;           
            }
        else {
            n = abs(n);
            while(n) {
                if(n&1)
                    res = res/x;

                x *= x;
                n >>= 1;           
            }
        }
        return res;
    }
};
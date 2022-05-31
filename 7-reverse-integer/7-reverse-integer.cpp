class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while(x) {
            if(ans*10 <= INT_MAX and ans*10 >= INT_MIN)
                ans *= 10;
            else    return 0;
            
            ans += (x % 10);
            x /= 10;
        }
        return ans;
    }
};
class Solution {
public:
    int mod = 1e9+7;
    long long mpow(long long base, long long exp) {
        long long res = 1;
        while(exp > 0) {
            if(exp & 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        
        return res % mod;
    }
    
    
    int countGoodNumbers(long long n) {
        long long oddPlaces = n/2;
        long long evenPlaces = (n%2 == 0) ? n/2 : n/2+1;
        
        long long oddWays = mpow(4, oddPlaces);
        long long evenWays = mpow(5, evenPlaces);
        
        long long ans = ((oddWays%mod) * (evenWays%mod)) % mod;
        return ans;
    }
    
    /*
        odd places can be filled with 2 3 5 7 (4) ways
        even places can be filled with 0 2 4 6 8 (5) ways
        
        if n is even there are n/2 even places and n/2 odd places
        if n is odd there are n/2+1 even and n/2 odd places.
    */
};
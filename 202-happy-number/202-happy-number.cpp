class Solution {
public:
    bool isHappy(int n) {
        if(n == 1)  return true;
        unordered_set<int> st;
        while(n > 3) {
            long temp = 0;
            while(n) {
                int x = n % 10;
                temp += (x*x);
                n /= 10;
            }
            if(st.find(temp) != st.end())   return false;
            st.insert(temp);
            n = temp;
            if(temp == 1)   return true;
            if(temp < 4)   return false;
            
        }
        return false;
    }
};
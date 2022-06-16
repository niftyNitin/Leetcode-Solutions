class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        int fact = 1;
        for(int i=1; i < n; i++) {
            fact *= i;
            num.push_back(i);
        }
        num.push_back(n);
        k--;
        string res = "";
        while(true) {
            res.push_back(num[k/fact]+'0');
            num.erase(num.begin() + k/fact);
            if(num.size() == 0)   break;
            k = k % fact;
            fact /= num.size();
        }
        return res;
    }
};
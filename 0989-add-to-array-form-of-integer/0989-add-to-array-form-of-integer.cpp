class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        int carry = 0;
        for(int i = 0; i < num.size(); i++) {
            int sum = num[i] + carry + k%10;
            num[i] = sum % 10;
            carry = sum / 10;
            k /= 10;
        }
        
        while(k) {
            int sum = k%10 + carry;
            num.push_back(sum % 10);
            carry = sum / 10;
            k /= 10;
        }
        
        if(carry)   num.push_back(carry);
        reverse(num.begin(), num.end());
        return num;        
    }
};
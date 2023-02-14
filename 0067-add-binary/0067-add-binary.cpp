class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string ans = "";
        int i = 0, j = 0, carry = 0;
        while(i < a.size() or i < b.size()) {
            int x = (i < a.size()) ? (a[i] - '0') : 0; 
            int y = (i < b.size()) ? (b[i] - '0') : 0;
            int sum = x + y + carry;
            ans.push_back(sum%2 + '0');
            carry = sum / 2;
            i++;
        }
        
        if(carry)   ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
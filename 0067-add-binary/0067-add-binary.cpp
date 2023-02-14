class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string ans = "";
        int i = 0, j = 0, carry = 0;
        while(i < a.size() and i < b.size()) {
            int x = a[i] - '0', y = b[i] - '0';
            int sum = x + y + carry;
            ans.push_back(sum%2 + '0');
            carry = sum / 2;
            i++;
        }
        
        while(i < a.size()) {
            int x = a[i] - '0';
            int sum = x + carry;
            ans.push_back(sum%2 + '0');
            carry = sum / 2;
            i++;
        }
        
        while(i < b.size()) {
            int y = b[i] - '0';
            int sum = y + carry;
            cout << sum << endl;
            ans.push_back(sum%2 + '0');
            carry = sum / 2;
            i++;
        }
        if(carry)   ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
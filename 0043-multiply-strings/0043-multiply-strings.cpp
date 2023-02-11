class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;
        int a = num1.length() - 1, b = num2.length() - 1;
        while(a >= 0 or b >= 0 or carry == 1){
            carry += (a >= 0) ? num1[a] - '0' : 0;
            carry += (b >= 0) ? num2[b] - '0' : 0;
            
            ans = (char) (carry % 10  + '0') + ans;
            carry /= 10;
            a--, b--;
        }
        return ans;
    }
    
    string multiply(string num1, string num2) {
        if(num1[0] == '0' or num2[0] == '0') return "0";
        if(num1 == "1") return num2;
        if(num2 == "2") return num1;
        
        int a = num1.size()-1, b = num2.size()-1;
        string ans = "";
        int k = 0;
        
        for(int i = a; i >= 0; i--) {
            string s = "";
            int carry = 0;
            for(int j = b; j >= 0; j--) {
                int x = (num1[i] - '0') * (num2[j] - '0');
                carry += x;
                s = to_string(carry % 10) + s;
                carry /= 10;
            }
            if(carry)   s = to_string(carry % 10) + s;
            
            for(int zero = 0; zero < k; zero++) {
                s += '0';
            }
            
            ans = addStrings(ans, s);
            k++;
        }
        return ans;
    }
};
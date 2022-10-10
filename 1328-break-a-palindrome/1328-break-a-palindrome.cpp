class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        
        if(n == 1)  return "";
        
        string copy = palindrome;
        bool flag = true;
        int i = 0;
        int acount = 0;
        while(i < n) {
            if(palindrome[i] != 'a' and flag) {
                palindrome[i] = 'a';
                flag = false;
            }
            else if(palindrome[i] == 'a')  acount++;
            i++;
        }
        
        if(acount == n-1) {
            copy.back() = 'b';
            return copy;
        }
        
        if(flag) palindrome.back() = 'b';
        return palindrome;
    }
};
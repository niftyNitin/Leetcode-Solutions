class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "";
        for(int i = 0; i <= pattern.size(); i++) {
            while(pattern[i] == 'I') {
                ans += (i+1 + '0');
                i++;
            }
            
            int count = 0;
            while(pattern[i] == 'D') {
                count++;
                i++;
            }
            
            int x = i+1;
            count++;
            while(count--) {
                ans += (x + '0');
                x--;
            }
        }
        
        return ans;
    }
};
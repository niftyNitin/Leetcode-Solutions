class Solution {
public:
    string say(string s) {
        string res = "";
        int count = 1;
        
        for(int i = 1; i < s.size(); i++) {
            char c = s[i];
            if(s[i] == s[i-1])   count++;
            else {
                res += to_string(count);
                res += s[i-1];
                count = 1;
            }
        }
        res += to_string(count);
        res += s.back();
        return res;
    }
    
    string countAndSay(int n) {
        string s = "1";
        string res = "1";
        while(--n) {
            res = say(s);
            s = res;
        }
        
        return res;            
    }
};
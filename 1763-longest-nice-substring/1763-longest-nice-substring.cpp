class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size() < 2)    return "";
        unordered_set<char> st(s.begin(), s.end());
        string split = "";
        string res = "";
        for(int i = 0; i < s.size(); i++) {
            if(islower(s[i]) and st.count(toupper(s[i]))) {
                split += s[i];
            }
            else if(isupper(s[i]) and st.count(tolower(s[i]))) {
                split += s[i];
            }
            else {
                string temp = longestNiceSubstring(split);
                if(temp.size() > res.size())   res = temp;
                split = "";
            }
        }
        
        if(split == s)  return s;
        string temp = longestNiceSubstring(split);
        if(temp.size() > res.size())   res = temp;
        return res;
    }
};
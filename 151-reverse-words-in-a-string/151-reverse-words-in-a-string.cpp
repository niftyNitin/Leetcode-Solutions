class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        ss << s;
        string temp;
        string res = "";
        while(ss >> temp) {
            res = temp + " " + res;
        }
        res.pop_back();
        return res;
    }
};
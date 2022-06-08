class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string temp, res = "";
        while(ss >> temp) {
            res = temp + " " + res;
        }
        res.pop_back();
        return res;
    }
};
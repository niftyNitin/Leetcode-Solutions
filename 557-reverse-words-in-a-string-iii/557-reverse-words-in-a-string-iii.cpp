class Solution {
public:
    string reverseWords(string& s) {
        string res = "";
        string word;
        stringstream ss(s);
        while(ss >> word) {
            reverse(word.begin(), word.end());
            res += word + " ";
        }
        res.pop_back();
        return res;
    }
};
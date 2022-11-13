class Solution {
public:
    string reverseWords(string s) {
        string word = "", ans = "";
        vector<string> v;
        for(char c : s) {
            if(c != ' ')    word += c;
            else {
                v.push_back(word);
                word =  "";
            }
        }
        v.push_back(word);
        reverse(v.begin(), v.end());
        for(auto s : v) {
            if(s != "")
                ans += s + " ";
        }
        
        ans.pop_back();
        return ans;
    }
};
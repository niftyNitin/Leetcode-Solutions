class Solution {
    static bool cmp(string &a, string &b) {
        if(a.size() == b.size())    return a < b;
        return a.size() < b.size();
    }
public:
    string findLongestWord(string s, vector<string>& dict) {
        sort(dict.begin(), dict.end(), cmp);
        int len = 0;
        string longest;
        for(auto &d : dict) {
            if(d.size() == len) continue;
            int i = 0, j = 0;
            while(i < d.size() and j < s.size()) {
                if(d[i] == s[j])    i++, j++;
                else    j++;
            }
            
            if(i == d.size()) {
                len = d.size();
                longest = d;
            }
        }
        return longest;
    }
};
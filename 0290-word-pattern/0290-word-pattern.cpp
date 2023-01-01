class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        unordered_map<string, char> stc;
        unordered_map<char, string> cts;
        int id = 0;
        while(ss >> word) {
            if(stc.count(word) and stc[word] != pattern[id])   return false;
            if(cts.count(pattern[id]) and cts[pattern[id]] != word)   return false;
            cts[pattern[id]] = word;
            stc[word] = pattern[id];
            id++;
        }
        if(id != pattern.size())    return false;
        return true;        
    }
};
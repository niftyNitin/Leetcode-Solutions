class Solution {
public:
    bool checkSubstring(string s, unordered_map<string, int>wordmp, int tokensize) {
        int len = s.size();
        for(int i = 0; i <= len-tokensize; i+=tokensize) {
            string temp = s.substr(i, tokensize);
            if(wordmp[temp] == 0)  return false;
            else    wordmp[temp]--;
        }
        return true;
    }
    
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int tokensize = words[0].size();
        int total = tokensize * words.size();
        if(s.size() < total)    return {};
        unordered_map<string, int> wordmp;
        for(string ss : words) 
            wordmp[ss]++;
        
        vector<int> res;
        for(int i = 0; i <= s.size()-total; i++) {
            string temp = s.substr(i, total);
            if(checkSubstring(temp, wordmp, tokensize))    res.push_back(i);
        }
        
        return res;
    }
};
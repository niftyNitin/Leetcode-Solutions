class Solution {
public:
    unordered_set<string> st;
    
    bool helper(string word, string s) {
        int k = 0;
        for(int i = 0; i < s.size(); i++) {
            if(word[k] == s[i]) k++;
            
            if(k == word.size())    return true;
        }
        
        return false;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        unordered_map<string,int> mp;
        for(string word : words)
            mp[word]++;
        
        for(auto it : mp) {
            if(helper(it.first, s))
                ans += it.second;
        }
        
        return ans;
    }
};
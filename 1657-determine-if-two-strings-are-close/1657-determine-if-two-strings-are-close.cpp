class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())    return false;
        vector<int> charfq1(26,0), charfq2(26,0);
        unordered_set<char> chars1, chars2;
        for(char c : word1) {
            charfq1[c-'a']++;
            chars1.insert(c);
        }
        
        for(char c : word2) {
            charfq2[c-'a']++;
            chars2.insert(c);
        }
        
        sort(charfq1.begin(), charfq1.end());
        sort(charfq2.begin(), charfq2.end());
        
        return (charfq1 == charfq2) and (chars1 == chars2);
        
    }
};
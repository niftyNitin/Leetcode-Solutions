class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allCaps = true, allSmall = true, firstCaps = true;
        if(isupper(word[0])) {
            allSmall = false;
        }
        else {
            allCaps = false;
            firstCaps = false;
        }
        
        for(int i = 1; i < word.size(); i++) {
            char ch = word[i];
            if(isupper(ch)) {
                firstCaps = false;
                allSmall = false;
            }
            else
                allCaps = false;
        }
        
        if(allCaps or allSmall or firstCaps)
            return true;
        return false;
    }
};
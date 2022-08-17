class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> st;
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(string word : words) {
            string temp = "";
            for(char c : word) {
                temp += code[c-'a'];
            }
            st.insert(temp);
        }
        
        return st.size();
    }
};
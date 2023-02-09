class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> fr;
        char last = '0';
        int count = 0;
        for(char c : s) {
            if(c == last) {
                count++;
            } else {
                fr.push_back(count);
                count = 1;
                last = c;
            }
        }
        
        fr.push_back(count);
        
        int ans = 0;
        for(int i = 0; i < fr.size()-1; i++) {
            ans += min(fr[i], fr[i+1]);
        }
        
        return ans;
    }
};
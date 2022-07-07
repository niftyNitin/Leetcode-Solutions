class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> left, right;
        int res = 0;

        // checking for first split where left contains first char and the remaining string in second
        left[s[0]]++;
        for(int i = 1; i < s.size(); i++) 
            right[s[i]]++;
        res = (left.size() == right.size());
        
        // checking for remaining splits
        for(int i = 1; i <= s.size()-2; i++) {
            char curr = s[i];
            left[curr]++;
            right[curr]--;
            if(right[curr] == 0)    right.erase(curr);
            res += (left.size() == right.size());
        }
        return res;
    }
};
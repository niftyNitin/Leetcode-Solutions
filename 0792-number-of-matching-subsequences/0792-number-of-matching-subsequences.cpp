class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> alpha(26);
        for(int i = 0; i < s.size(); i++) {
            alpha[s[i]-'a'].emplace_back(i);
        }

        int ans = 0;
        for(auto word : words) {
            int last = -1;
            bool found = true;
            for(char c : word) {
                auto it = upper_bound (alpha[c - 'a'].begin (), alpha[c - 'a'].end (), last);
				if (it == alpha[c - 'a'].end ()) {
                    found = false;
                    break;
                }
                else {
                    last = *it;
                }
            }
            if(found)    ans++;
        }

        return ans;
    }
};
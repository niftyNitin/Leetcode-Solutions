class Solution {
public:
    bool isPal(string s)
    {
        int l = s.length();
        int i = 0, j = l - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
    
    int longestPalindrome(vector<string>& s) {
        int ends = 0;
        unordered_map<string, int> mp;
        for (auto i : s)
            mp[i]++;

        for (auto i : s)
        {
            if(mp[i] > 0) {
                mp[i]--;
                string ss = i;
                reverse(ss.begin(), ss.end());
                if (mp[ss] > 0)
                {
                    ends += ss.size();
                    mp[ss]--;
                    continue;
                }
                mp[i]++;
            }
        }
        ends = ends << 1;
        // cout << ends << endl;
        int maxx = 0;
        for (auto i : mp)
        {
            if (i.second > 0 and isPal(i.first))
            {
                int n = i.first.size();
                maxx = max(maxx, n);
            }
        }
        // cout << maxx << endl;
        int total = maxx + ends;
        return total;
    }
};
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> dic;
        
        // storing order of elements in a map
        for(int i = 0; i < 26; i++) {
            dic[order[i]] = i;
        }
        
        int n = words.size();
        for(int i = 0; i < n-1; i++) {
            //  taking two adjacent words at a time and comparing them lexicographically
            string a = words[i];
            string b = words[i+1];
            int nn = max(a.size(), b.size());
            for(int j = 0; j < nn; j++) {
                if(j < a.size() and j >= b.size())  return false;
                if(dic[a[j]] > dic[b[j]])   return false;
                if(dic[a[j]] < dic[b[j]])   break;
            }
        }
        
        return true;
    }
};
class Solution {
public:
    static bool cmp(string a, string b) {
        string c, d;
        string bc, bd;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == ' ') {
                bc = a.substr(0, i);
                c = a.substr(i+1);
                break;
            }
        }
        
        for(int i = 0; i < b.size(); i++) {
            if(b[i] == ' ') {
                bd = b.substr(0, i);
                d = b.substr(i+1);
                break;
            }
        }
        // cout << "debug : " << c << " " << d << endl;
        if(c < d)   return true;
        else if(c == d) return bc < bd;
        else    return false;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans;
        vector<string> digs;
        vector<string> lets;
        
        for(auto s : logs) {
            if(isdigit(s.back()))
                digs.push_back(s);
            else
                lets.push_back(s);            
        }
        
        sort(lets.begin(), lets.end(), cmp);
        for(auto s : lets)  ans.push_back(s);
        for(auto s : digs)  ans.push_back(s);
        return ans;
    }
};
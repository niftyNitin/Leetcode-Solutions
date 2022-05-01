class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string st1 = "", st2 = "";
        for(auto i : s){
            if(i == '#' and !st1.empty())
                st1.pop_back();
            if(i != '#')
                st1.push_back(i);
        }
        
        for(auto i : t){
            if(i == '#' and !st2.empty())
                st2.pop_back();
            if(i != '#')
                st2.push_back(i);
        }
        
        return st1 == st2;
    }
};
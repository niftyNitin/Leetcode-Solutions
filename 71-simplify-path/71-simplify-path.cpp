class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        stack<string> st;
        
        string temp = "";
        for(auto i : path) {
            if(i == '/') {
                if(!st.empty() and temp == "..")   st.pop();
                else if(temp != "" and temp != "." and temp != "..")  st.push(temp);
                temp = "";
            }
            else temp += i;
        }
        
        
        if(!st.empty() and temp == "..")   st.pop();
        else if(temp != "" and temp != "." and temp != "..")  st.push(temp);
        
        while(!st.empty()) {
            res = st.top() + "/" + res;
            st.pop();
        }
        
        if(res != "")   res.pop_back();
        return "/" + res;
    }
};
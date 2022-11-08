class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char c : s) {
            if(st.empty())  st.push(c);
            else {
                if(!st.empty() and abs(st.top()-c) == 32) {
                    st.pop();
                }
                else
                    st.push(c);                
            }            
        }
        
        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
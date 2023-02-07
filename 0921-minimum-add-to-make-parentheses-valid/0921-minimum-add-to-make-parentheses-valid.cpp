class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(!st.empty() and st.top() == '(' and c == ')') {
                st.pop();
                continue;
            }
            st.push(c);
        }
        
        int ans = 0;
        while(!st.empty())  {
            ans++;
            st.pop();
        }
        
        return ans;
    }
};
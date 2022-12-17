class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(string s : tokens) {
            if(s == "+" or s == "-" or s == "*" or s == "/") {
                long long a = stol(st.top());
                st.pop();
                long long b = stol(st.top());
                st.pop();
                if(s == "+") st.push(to_string(a+b));
                else if(s == "-") st.push(to_string(b-a));
                else if(s == "*") st.push(to_string(a*b));
                else if(s == "/") st.push(to_string(b/a));
            }
            else {
                st.push(s);
            }
        }
        
        return stol(st.top());
    }
};
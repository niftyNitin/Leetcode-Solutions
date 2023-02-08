class Solution {
public:
    int countCollisions(string directions) {
        int collisions = 0;
        stack<char> st;
        for(char &c : directions) {
            if(c == 'R') {
                st.push(c);
            } 
            else if(c == 'S') {
                while(!st.empty() and st.top() == 'R') {
                    st.pop();
                    collisions += 1;
                }
                st.push('S');
            } 
            else if(c == 'L') {
                if(!st.empty() and st.top() == 'S') {
                    st.pop();
                    st.push('S');
                    collisions += 1;
                } 
                else if(!st.empty() and st.top() == 'R') {
                    st.pop();
                    collisions += 2;
                    while(!st.empty() and st.top() == 'R') {
                        st.pop();
                        collisions += 1;
                    }
                    st.push('S');
                } else {
                    st.push('L');
                }
            }
        }
        
        return collisions;
    }
};
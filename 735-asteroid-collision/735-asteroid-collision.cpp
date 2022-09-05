class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int> st;
        for(int i = 0; i < as.size(); i++) {
            if(st.empty() or as[i] > 0)
                st.push(as[i]);
            else {
                while(!st.empty() and st.top() > 0 and st.top() < abs(as[i])) {
                    st.pop();
                }
                
                if(!st.empty() and st.top() == -as[i])
                    st.pop();
                else {
                    if(st.empty() or st.top() < 0)
                        st.push(as[i]);
                }
            }
        }
        
        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
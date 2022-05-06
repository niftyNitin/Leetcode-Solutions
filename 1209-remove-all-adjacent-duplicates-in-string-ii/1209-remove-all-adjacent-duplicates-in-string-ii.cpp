class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        if(n < k)  return s;
        
        stack<pair<char,int>> st;
        for(int i = 0; i < n; i++) {
            if(st.empty() or st.top().first != s[i])    st.push({s[i], 1});
            else {
                auto top = st.top();
                st.pop();
                st.push({top.first, top.second+1});
            }
            
            if(st.top().second == k)    st.pop();
        }
        
        string ans = "";
        while(!st.empty()) {
            auto top = st.top();
            while(top.second--)
                ans += top.first;
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
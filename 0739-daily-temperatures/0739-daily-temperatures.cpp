class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        stack<pair<int,int>> st;
        for(int i = temperatures.size()-1; i >= 0; i--) {
            int temp = temperatures[i];
            while(!st.empty() and st.top().first <= temp) st.pop();
            if(st.empty())
                ans.push_back(0);
            else
                ans.push_back(st.top().second - i);
            
            st.push({temp, i});
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
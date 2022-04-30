class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<pair<int,int>> s;
        // NSR
        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() and s.top().first >= heights[i])
                s.pop();
            
            if(s.empty())   right[i] = n;
            else    right[i] = s.top().second;
            
            s.push({heights[i], i});
        }
        
        // NSL
        stack<pair<int,int>> st;        
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() and st.top().first >= heights[i])
                st.pop();
            
            if(st.empty())   left[i] = -1;
            else    left[i] = st.top().second;
            
            st.push({heights[i], i});
        }
        
//         cout << "LEFT" << endl;
//         for(auto i : left)
//             cout << i << " ";
//         cout << endl;
        
//         cout << "RIGHT" << endl;
//         for(auto i : right)
//             cout << i << " ";
//         cout << endl;
        
        for(int i = 0; i < n; i++) {
            ans = max(ans, ((right[i] - left[i] - 1) * heights[i]));       
        }
        return ans;
    }
};
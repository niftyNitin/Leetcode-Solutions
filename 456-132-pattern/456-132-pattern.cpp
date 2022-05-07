class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3) return false;
        
        stack<pair<int, int>> st;
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(!st.empty())
                mini = min(mini, st.top().first);
            
            while(!st.empty() and st.top().first <= nums[i])
                st.pop();
            
            if(!st.empty() and st.top().second < nums[i])   return true;
            
            st.push({nums[i], mini});
        }
        return false;
    }
};
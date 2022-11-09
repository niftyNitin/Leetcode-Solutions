class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int fr = 1;
        while(!st.empty() and st.top().first <= price) {
            fr += st.top().second;
            st.pop();
        }
        st.push({price, fr});
        return fr;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
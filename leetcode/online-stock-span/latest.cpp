class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {}
    int index = 0;
    int next(int price) {
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        index++;
        int res;
        if (st.empty()) {
            res = index;
        } else
            res = index - st.top().second;
        st.push({price, index});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
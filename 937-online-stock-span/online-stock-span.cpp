class StockSpanner {
public:
    stack<pair<int, int>> st; // {price, span}

    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // Accumulate spans
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

class Solution {
public:
    int longestWPI(vector<int>& h) {
        int n = size(h);
        for (int& i : h) {
            if (i > 8) i = 1;
            else i = -1;
        }
        vector<int> prefix(n + 1, 0);
        for(int i = 1; i < n + 1; i++){
            prefix[i] = prefix[i - 1] + h[i - 1];
        }
        stack<int> st;
        st.push(0);
        for (int i = 1; i <= n; i++) {
            if (prefix[i] < prefix[st.top()]) {
                st.push(i); // lowest 
            }
        }
        int mx = 0;
        for (int i = n; i >= 0; i--) {
            while (!st.empty() && prefix[i] - prefix[st.top()] > 0) {
                int start = st.top();
                st.pop();
                mx = max(mx, i - start);
            }
        }

        return mx;
    }
};
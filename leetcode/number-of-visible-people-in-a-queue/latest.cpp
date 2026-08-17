class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        int n = size(h);
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty() || h[i] < h[st.top()]) {
                st.push(i);
            }
            else {
                int count = 0;
                while (!st.empty() && h[i] > h[st.top()]) {
                    int j = st.top();
                    st.pop();

                    count = i - j - 1 - res[j];
                    
                    res[j] = i - j;
                    res[j] -= count;
                    
                    if (!st.empty()) {
                        res[st.top()]++;
                    }
                    
                    count += max(0, res[j] - 1);
                }
                st.push(i);
            }
        }
        int prev = -1;
        while (!st.empty()) {
            int j = st.top();
            st.pop();
            if (prev != -1)
                res[j]++;
            prev = j;
        }
        return res;
    }
};
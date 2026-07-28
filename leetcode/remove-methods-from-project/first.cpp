class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& v) {
        vector<vector<int>> adj(n);
        vector<vector<int>> par(n);
        for (auto& a : v) {
            adj[a[0]].push_back(a[1]);
            par[a[1]].push_back(a[0]);
        }
        vector<bool> ok(n, true);
        stack<int> st;
        st.push(k);
        while (!st.empty()) {
            int current = st.top();
            st.pop();
            ok[current] = false;
            for (int i : adj[current]) {
                if (!ok[i])
                    continue;
                st.push(i);
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (!ok[i]) {
                for (int j : par[i]) {
                    if (ok[j]) {
                        vector<int> res;
                        for (int i = 0; i < n; i++)
                            res.push_back(i);
                        return res;
                    }
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
            if (ok[i])
                res.push_back(i);
        return res;
    }
};
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1);
        for (auto& a : paths) {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        vector<int> res(n + 1, 0);
        res[0] = -1;

        while (true) {
            ///
            stack<int> st;
            ///
            int index = find(res.begin(), res.end(), 0) - res.begin();
            st.push(index);
            ///
            while (!st.empty()) {
                int current = st.top();
                st.pop();
                if (res[current] != 0)
                    continue;
                unordered_set<int> s;
                for (int i : adj[current]) {
                    if (res[i] != 0)
                        s.insert(res[i]);
                }
                for (int i = 1; i <= 4; i++) {
                    if (s.count(i) == 0) {
                        res[current] = i;
                        break;
                    }
                }
                for (int i : adj[current]) {
                    st.push(i);
                }
            }
            ///
            bool found = find(res.begin(), res.end(), 0) != res.end();
            if (!found)
                break;
        }

        res.erase(begin(res));
        return res;
    }
};
class Solution {
public:
    bool canRemoveAll(vector<int>& t, vector<int>& c, vector<int>& gs) {
        int n = size(t), m = size(gs);
        vector<array<int, 3>> st;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && t[j] == t[i] && c[j] == c[i])
                j++;
            int x = t[i], y = c[i], z = j - i;
            while (z > 0) {
                int k = gs[x];
                if (!st.empty() && st.back()[0] == x && st.back()[1] == y) {
                    z += st.back()[2];
                    st.pop_back();
                }
                z %= k;
                if(z) {
                    st.push_back({x, y, z}); break;
                }
            }
            i = j;
        }
        return st.empty();
    }
};
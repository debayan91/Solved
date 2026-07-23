class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mt) {
        int mx = 1;
        unordered_map<string, int> m;
        for (auto& aa : mt) {
            string a = "", b = "";
            for (int i : aa) {
                if (i == 1) {
                    a += "1";
                    b += "0";
                } else {
                    b += "1";
                    a += "0";
                }
            }
            string c = max(a, b);
            m[c]++;
            mx = max(mx, m[c]);
        }
        return mx;
    }
};
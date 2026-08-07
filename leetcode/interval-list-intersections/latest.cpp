class Solution {
public:
    vector<int> in(int a, int b, int c, int d) {
        if (a <= c && b >= d)
            return {c, d};
        else if (c <= a && d >= b)
            return {a, b};
        else if (b >= c && b <= d) {
            int start = max(a, c);
            return {start, b};
        } else if (a >= c && a <= d) {
            int end = min(b, d);
            return {a, end};
        } else {
            return {};
        }
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a,
                                             vector<vector<int>>& b) {
        vector<vector<int>> res;
        for (auto& i : b) {
            int sb = i[0], eb = i[1];
            for (auto& j : a) {
                int sa = j[0], ea = j[1];
                if (sa > eb)
                    break;
                auto is = in(sb, eb, sa, ea);
                if (size(is) == 0)
                    continue;
                res.push_back(is);
            }
        }
        return res;
    }
};
class Solution {
public:
    int miceAndCheese(vector<int>& a, vector<int>& b, int k) {
        int n = size(a);
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({a[i], b[i]});
        }
        sort(begin(v), end(v), [](auto& x, auto& y) {
            return x.first - x.second > y.first - y.second;
        });
        int t = 0;
        for (int i = 0; i < n; i++) {
            if (i < k) {
                t += v[i].first;
            } else {
                t += v[i].second;
            }
        }
        return t;
    }
};
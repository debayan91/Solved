class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& a) {
        int n = size(a), mx = 0, b = 0;
        map<array<int, 2>, int> m;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1])
                b++;
            else {
                m[{a[i], a[i + 1]}]++;
                m[{a[i + 1], a[i]}]++;
                mx = max({mx, m[{a[i], a[i + 1]}], m[{a[i + 1], a[i]}]});
            }
        }
        return b + mx;
    }
};
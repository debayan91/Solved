class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = size(s);
        vector<int> p;
        for (int i = 0; i + 2 < n; i++) {
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
                p.push_back(i);
        }
        int m = size(p);
        if (!m)
            return 1LL * n * (n + 1) / 2;

        vector<long long> v;
        v.push_back(p[0] + 2);
        for (int i = 0; i + 1 < m; i++)
            v.push_back(p[i + 1] - p[i] + 1);
        v.push_back(n - p[m - 1] - 1);
        long long a = 0;
        for (auto l : v)
            a += l * (l + 1) / 2;

        a -= m;
        return a;
    }
};
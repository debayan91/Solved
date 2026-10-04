class Solution {
public:
    int minRotations(int n, string s) {
        auto dis = [](int t, int current) {
            return min(abs(t - current), 10 - abs(t - current));
        };

        vector<int> d(n);
        for (int i = 0; i < n; i++)
            d[i] = s[i] - '0';

        int c = dis(d[0], 0);
        for (int i = 0; i < n - 1; i++)
            c += dis(d[i + 1], d[i]);

        int r = c;
        for (int i = 0; i < n; i++) {
            int p = (i == 0) ? 0 : d[i - 1];
            r = min(r, 
                    c - dis(p, d[i]) + dis(p, d[n - 1])
                   );
        }
        return r;
    }
};
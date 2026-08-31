class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int f) {
        int n = size(v);

        if (!f)
            return 1;
        if (n == 0)
            return 0;

        if (n == 1) {
            if (v[0])
                return 0;
            if (f == 1)
                return 1;
            return 0;
        }
        for (int i = 0; i < n && f; i++) {
            if (v[i])
                continue;
            if (i == 0) {
                if (!v[i + 1]) {
                    v[i] = 1;
                    f--;
                }
            } else if (i == n - 1) {
                if (!v[i - 1]) {
                    v[i] = 1;
                    f--;
                }
            } else {
                if (!v[i - 1] && !v[i + 1]) {
                    v[i] = 1;
                    f--;
                }
            }
        }
        return f == 0;
    }
};
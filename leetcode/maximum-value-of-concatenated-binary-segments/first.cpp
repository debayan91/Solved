#pragma GCC optimize("O3,unroll-loops")

class Solution {
public:
    int maxValue(vector<int>& a, vector<int>& b) {
        constexpr long long MOD = 1e9 + 7;

        int n = a.size();
        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; ++i)
            v[i] = {a[i], b[i]};

        // sort(v.begin(), v.end(), [](const auto& x, const auto& y) {
        //     if (x.first != y.first)
        //         return x.first > y.first;
        //     return x.second < y.second;
        // });

        sort(v.begin(), v.end(), [](const auto& x, const auto& y) {

            // x is all 1s
            if (x.second == 0) {
                // y is also all 1s -> equal
                if (y.second == 0)
                    return false;

                return true;
            }

            // y is all 1s
            if (y.second == 0)
                return false;

            // x is all 0s
            if (x.first == 0) {
                // y is also all 0s -> equal
                if (y.first == 0)
                    return false;

                return false;
            }

            // y is all 0s
            if (y.first == 0)
                return true;

            // Both are 1^a 0^b with a,b > 0
            if (x.first != y.first)
                return x.first > y.first;

            return x.second < y.second;
        });

        auto power2 = [&](long long x) {
            long long res = 1;
            long long base = 2;

            while (x) {
                if (x & 1)
                    res = res * base % MOD;
                base = base * base % MOD;
                x >>= 1;
            }

            return res;
        };

        long long ans = 0;

        for (auto [ones, zeros] : v) {
            long long p = power2(ones);

            ans = (ans * p + p - 1) % MOD;

            ans = ans * power2(zeros) % MOD;
        }

        return ans;
    }
};
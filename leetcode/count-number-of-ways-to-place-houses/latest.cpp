class Solution {
public:
    long long modpow(long long a, long long b, long long mod) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % mod;

            a = a * a % mod;
            b >>= 1;
        }

        return res;
    }
    int countHousePlacements(int n) {
        if (n == 1)
            return 4;
        int mod = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }
        return modpow(dp.back(), 2, mod);
    }
};
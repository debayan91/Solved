class Solution {
public:
    long long modpow(long long a, long long b) {
        long long mod = 1e9 + 7;
        long long res = 1;

        while (b) {
            if (b & 1)
                res = (res * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }

        return res;
    }
    int countGoodNumbers(long long n) {
        long long a = (n + 1) / 2;
        long long b = n / 2;
        long long mod = 1e9 + 7;
        return  ((modpow(5, a) % mod) * (modpow(4, b) % mod) % mod);
    }
};
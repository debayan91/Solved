class Solution {
public:
    int numOfWays(int n) {
        long long mod = 1e9 + 7;
        long long a = 6, b = 6;
        for(int i = 1; i < n; i++){
            long long c = ((2 * a) % mod + (2 * b) % mod) % mod;
            long long d = ((2 * a) % mod + (3 * b) % mod) % mod;
            a = c;
            b = d;
        }
        return (a + b) % mod;
    }
};
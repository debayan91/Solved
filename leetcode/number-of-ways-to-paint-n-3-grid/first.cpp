class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9 + 7;
        vector<long long> abc(n, 0);
        vector<long long> aba(n, 0);
        abc[0] = aba[0] = 6;
        for(int i = 1; i < n; i++){
            abc[i] = ((2 * abc[i - 1]) % mod + (2 * aba[i - 1]) % mod) % mod;
            aba[i] = ((2 * abc[i - 1]) % mod + (3 * aba[i - 1]) % mod) % mod;
        }
        return (aba.back() + abc.back()) % mod;
    }
};
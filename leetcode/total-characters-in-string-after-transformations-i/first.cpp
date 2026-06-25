class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9 + 7;
        vector<long long> v(26, 0);
        for(char c : s) v[c - 'a']++;
        for(int i = 0; i < t; i++){
            int z = v[25] % mod;
            for(int j = 24; j >= 0; j--){
                v[j + 1] = v[j] % mod;
            }
            v[0] = z % mod;
            v[1] = (v[1] % mod + z % mod) % mod;
        }
        long long sum = 0;
        for(long long s : v){
            sum += s % mod;
            sum %= mod;
        }
        return sum;
    }
};
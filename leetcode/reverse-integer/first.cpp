class Solution {
public:
    long long reverse(long long x) {
        if (x < -1 * INT_MAX || x > INT_MAX)
            return 0;
        vector<long long> v;
        long long k = 1;
        if (x < 0) {
            k = -1;
            x *= k;
        }
        while (x > 0) {
            v.push_back(x % 10);
            x /= 10;
        }
        long long a = 0;
        for (long long i = 0; i < v.size(); i++) {
            long long k = v.size() - i - 1;
            a += pow(10, k) * v[i];
        }
        if (a > INT_MAX)
            return 0;
        a *= k;
        return a;
    }
};
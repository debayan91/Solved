class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;
        if(n%2 != 0) n--;
        long long a, b, c, d, e, f;
        a = n / 2;
        b = (n - 1) / 2;

        e = a * m - b + s;

        a = b;
        b = n / 2;

        f = a * m - b + s;

        d = max(e, f);

        return d;
        
    }
};
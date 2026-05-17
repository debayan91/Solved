class Solution {
public:
    int divide(int c, int d) {
        if (c == INT_MIN && d == -1)
            return INT_MAX;

        long long a = llabs((long long)c);
        long long b = llabs((long long)d);
        long long q = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            while (temp + temp <= a) {
                temp += temp;
                multiple += multiple;
            }

            a -= temp;
            q += multiple;
        }

        if ((c < 0) ^ (d < 0))
            q = -q;

        return (int)q;
    }
};
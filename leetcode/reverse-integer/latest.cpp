class Solution {
public:
    long long reverse(long long x) {
        if (x < -1 * INT_MAX || x > INT_MAX)
            return 0;
        long long k = 1;
        if (x < 0) {
            k = -1;
            x *= k;
        }

        long long digits = 0;
        long long t = x;
        while(t>0){
            t/=10;
            digits++;
        }
        
        long long a = 0;
        long long i = 0;
        long long p = pow(10,digits-1);
        while (x > 0) {
            long long current = (x % 10);
            x /= 10;
            a += p * current;
            p = p / 10;
            i++;
        }

        if (a > INT_MAX)
            return 0;
        a *= k;
        return a;
    }
};
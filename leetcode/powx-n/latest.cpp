class Solution {
public:
    string binary(long long n) {
        bitset<64> b(n);
        string s = b.to_string();

        int pos = s.find('1');

        if (pos == string::npos)
            return "0";

        return s.substr(pos);
    }

    double myPow(double x, int N) {
        int sign = 0; // care only if the power is negative

        long double res = 1;

        long long n = N;

        if (x == 0)
            return 0;
        if (n == 0)
            return 1;

        if (n < 0) {
            n = -n;
            sign = 1;
        }

        // fast exponentiation
        string bin = binary(n);

        reverse(bin.begin(), bin.end());
        // cout << bin;

        long double value = x; // tracks the value to be multiplied -> fast exp

        for (int i = 0; i < bin.size(); i++) { // logn
            if (bin[i] == '1') {
                // mul is the exponent
                res = res * value;
            }
            value = value * value;
        }

        if (sign) {
            res = 1 / res;
        }

        return res;
    }
};
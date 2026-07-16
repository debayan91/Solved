class Solution {
public:
    int minimizeXor(int num1, int num2) {
        string a;

        while (num1 > 0) {
            a.push_back((num1 % 2) + '0');
            num1 /= 2;
        }

        reverse(a.begin(), a.end());

        string x(a.size(), '0');

        int ones = __builtin_popcount(num2);

        for (int i = 0; i < a.size() && ones > 0; i++) {
            if (a[i] == '1') {
                x[i] = '1';
                ones--;
            }
        }

        for (int i = x.size() - 1; i >= 0 && ones > 0; i--) {
            if (x[i] == '0') {
                x[i] = '1';
                ones--;
            }
        }

        for(int i = 0; i < ones; i++) x = "1" + x;

        int ans = 0;
        for (char c : x) {
            ans = ans * 2 + (c - '0');
        }

        return ans;
    }
};